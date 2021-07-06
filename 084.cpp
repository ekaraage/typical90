#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long MOD2 = 998244353;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main(){
    ll N;
    string S;
    cin >> N >> S;
    vector<ll> osum(N + 1, 0), xsum(N + 1, 0);
    for (ll i = 0; i < N; i++) {
        osum[i + 1] = osum[i] + (S[i] == 'o');
        xsum[i + 1] = xsum[i] + (S[i] == 'x');
    }
    ll ans = N * (N - 1) / 2 + N;  //i!=jとなる選び方は(N,2)通りで、i==jなる選び方はN通り
    ll right = 0;
    for (ll left = 0; left < N; left++) {
        while (right < N and (osum[right + 1] - osum[left] <= 0 or xsum[right + 1] - xsum[left] <= 0)) {
            right++;
        }
        ans -= (right - left);
        if (right == left) right++;
    }
    cout << ans << endl;
}
