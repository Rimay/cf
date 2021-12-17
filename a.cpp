#include <bits/stdc++.h>

using namespace std;
 
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define forde(i, r, l) for (int i = (int)(r); i >= l; --i)

#define forlle(i, l, r) for (long long i = (long long)(l); i <= (long long)(r); ++i)
 
#define pb push_back
#define fi first
#define se second

#define count_one(x) __builtin_popcount(x)
#define check_parity(x) __builtin_parity(x)
#define count_leading_zero(x) __builtin_clz(x)
#define count_trailing_zero(x) __builtin_ctz(x)

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yl_min(a, b) ((a) < (b) ? (a) : (b))
#define yl_max(a, b) ((a) > (b) ? (a) : (b))
#define max_int 2147483647
 
typedef long long lli;
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef vector<vi> vvi;
typedef vector<vlli> vvlli;
typedef pair<lli, int> pir;
// priority_queue <int, vi, greater<int> > pq_mn;
// priority_queue <int, vi, less<int> >  pq_mx;

const int maxn = 1005;
const int mod = 1e9 + 7;


lli jc[maxn];

lli ksm(lli sum,int num){
	lli ans=1ll;
	while(num){
		if(num&1)ans=ans*sum%mod;
		sum=sum*sum%mod;
		num>>=1;
	}
    return ans;
}

lli C(int a,int b){
	return jc[a] * ksm(jc[b], mod-2) % mod * ksm(jc[a-b], mod-2) % mod;
}

int n, t, k;
string s;

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> s;
		int l1 = -1, r1, l2, r2 = 0;
		l2 = n / 2;
		fore (i, l2, n - 1) {
			if (s[i] == '0') {
				r2 = i;
				break;
			}
		}
		if (r2 != 0) {
			cout << 1 << " " << r2 + 1 << " " << 1 << " " << r2 <<endl;
			continue;
		}
		forde (i, l2 - 1, 0) {
			if (s[i] == '0') {
				l1 = i;
				break;
			}
		}
		if (l1 != -1) {
			cout << l1 + 1 << " " << n << " " << l1 + 2 << " " << n << endl;
			continue;
		}
		if (n % 2 == 0) {
			cout << 1 << " " << l2 << " " << l2 + 1  << " " << n << endl;
		}
		else {
			cout << 1 << " " << l2 << " " << l2 + 2 << " " << n << endl;
		}
	}
    return 0; 
}










 
