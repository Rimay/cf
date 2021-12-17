#include <bits/stdc++.h>
 
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define forde(i, r, l) for (int i = (int)(r); i >= l; --i)
#define forlle(i, l, r) for (long long i = (long long)(l); i <= (long long)(r); ++i)
 
#define pb push_back
#define fi fisrt
#define se second

#define count_one(x) __builtin_popcount(x)
#define check_parity(x) __builtin_parity(x)
#define count_leading_zero(x) __builtin_clz(x)
#define count_trailing_zero(x) __builtin_ctz(x)

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yl_min(a, b) ((a) < (b) ? (a) : (b))
#define max_int 2147483647
 
using namespace std;
typedef long long lli;
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef vector<vi> vvi;

class base
{
private:
    /* data */
    int v;
public:
    base(int a) {
        this->v = a;
    }
    ~base(){}

    void func0() {
        cout << "base func0" << endl;
    }
    virtual void func1() {
        cout << "base func0" << endl;
    }
    void func2(int x) {
        cout << "base func2 " << x  << endl;

    }
};



class child: public base
{
private:
    int v;
public:
    child(int a):base(a) {
    }
    ~child(){}
    void func0() {
        cout << "child func0" << endl;
    }
    void func1() {
        cout << "child func1" << endl;
    }
    void func2(int x, int y) {
        cout << "child func2 " << x + y << endl;

    }
};

void test_smart_pointer ()
{
    shared_ptr<int> p = make_shared<int>(100);
    cout << p << endl << p.use_count() << endl;
    shared_ptr<int> p1 = p;
    cout << p1 << endl << p.use_count() << endl << p1.use_count() << endl;

    int *p0 = p.get();
    cout << p0 << " " << *p0 << endl;
}


void test_class()
{
    base *b = new child(100);
    b->func0();             // 隐藏
    b->func1();             // 重写 / 覆盖(多态)
    b->func2(100);          // 重载

    child *c = new child(100);
    c->func0();
    c->func1();
    c->func2(100, 100);

}

int main() 
{
    string s;
    test_class();
    return 0;
}
 