#include <bits/stdc++.h>

using namespace std;

#define fixed(n) fixed << setprecision(n)
#define ceil(n, m) (((n) + (m) - 1) / (m))
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << (x) << "\n";
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define EPS 1e-9
constexpr int INF = 1 << 30, Mod = 1e9 + 7;
constexpr ll LINF = 1LL << 62;
#define PI acos(-1)
template < typename T = int > using Pair = pair < T, T >;
vector < string > RET = {"NO", "YES"};

template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}

template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
    for (const T &x : v) out << x << ' '; 
    return out;
}

template < typename T = int , typename CompFunction = std::greater_equal < T > > struct Heap {
    
    vector < T > heap;

    Heap() { }

    Heap(const vector < T > &v){
        for(auto& x : v)
            insert(x);
    }

    bool comp(const T &a, const T &b){
        return CompFunction()(a, b);
    }

    void push_down(int idx){
        int n = sz(heap);
        while(idx < n){
            int l = 2 * idx + 1, r = 2 * idx + 2;
            if(l >= n) break;
            if(r >= n) r = l;
            T mx = comp(heap[l], heap[r]) ? l : r;
            if(comp(heap[mx], heap[idx]))
                swap(heap[mx], heap[idx]), idx = mx;
            else
                break;
        }
    }

    void push_up(int idx){
        while(idx > 0){
            int p = (idx - 1) / 2;
            if(!comp(heap[p], heap[idx]))
                swap(heap[p], heap[idx]), idx = p;
            else
                break;
        }
    }

    void insert(const T x){
        heap.push_back(x);
        push_up(sz(heap) - 1);
    }

    void pop(){
        swap(heap.back(), heap.front());
        heap.pop_back();
        push_down(0);
    }

    T top(){
        return heap.front();
    }

    bool empty(){
        return sz(heap) == 0;
    }

    int size(){
        return sz(heap);
    }
};

void Solve(){
    
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int test_cases = 1;
    // cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
        // cout << "Case #" << tc << ": ";
        Solve();
    }
    return 0;
}