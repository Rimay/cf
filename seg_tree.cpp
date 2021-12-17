#include "bits/stdc++.h"
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
typedef pair<int, int> pir;
priority_queue <int,vector<int>,greater<int> > pq_mn;
priority_queue <int,vector<int>,less<int> >  pq_mx;

const int maxn = 100010;
const int mod = 998244353;

lli gcd(lli a, lli b) { return b == 0 ? a : gcd(b, a % b); }

bool is_prime(lli v) {
    if (v == 2 || v == 3 || v == 5)    return true;
    if (v % 2 == 0 || v % 3 == 0 || v % 5 == 0)    return false;
    for (lli i = 6; i * i <= v; i+= 6) {
        if (v % (i + 1) == 0 || v % (i + 5) == 0) return false;
    }
    return true;
}

class binary_index_tree {
public:
    binary_index_tree(vector<lli> &a) {
        this->len = a.size();
        forn (i, a.size() + 1) {
            this->arr.pb(0);
        }
        for (int i = 0; i < a.size(); i++) {
            this->update(i, a[i]);
        }
    }

    lli _pre_sum(int p) {
        lli ret = 0;
        while (p) {
            ret += arr[p];
            p -= (p & -p);
        }
        return ret;
    }

    lli query(int l, int r) {
        l++;
        r++;
        return _pre_sum(r) - _pre_sum(l - 1);
    }

    void update(int p, lli v) {
        p++;
        while (p <= this->len) {
            this->arr[p] += v;
            p += (p & -p);
        }
    }

private:
    int len;
    vector<lli> arr;
};


// class seg_tree {
// public:
//     seg_tree (vector<lli> &a) {
//         this->len = a.size();
//         this->arr = 
//     }
// private:
//     int len;
//     vector<lli> arr;
// }


int main() {
    vlli arr({1,2,3,4,5});
    binary_index_tree *b = new binary_index_tree(arr);
    forn (i, 5) {
        cout << b->_pre_sum(i + 1) << " ";
    }
    cout << endl;
    cout << b->query(0, 4) << endl;
    b->update(3, 10);
    cout << b->query(3, 3) << endl;

    return 0;
}


