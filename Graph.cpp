#include <bits/stdc++.h>

using namespace std;

#define cin(vec) for(auto& i : vec) cin >> i
#define cin_2d(vec, n, m) for(int i = 0; i < n; i++) for(int j = 0; j < m && cin >> vec[i][j]; j++);
#define cout(vec) for(auto& i : vec) cout << i << " "; cout << "\n";
#define cout_2d(vec, n, m) for(int i = 0; i < n; i++, cout << "\n") for(int j = 0; j < m && cout << vec[i][j] << " "; j++);
#define cout_map(mp) for(auto& [f, s] : mp) cout << f << "  " << s << "\n";
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define fixed(n) fixed << setprecision(n)
#define ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define fill(vec, value) memset(vec, value, sizeof(vec));
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define mod_combine(a, b, m) (((a % m) * (b % m)) % m)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << (x) << "\n";
#define fi first
#define se second
#define Pair pair < int, int >
#define ll long long
#define ull unsigned long long
#define Mod  1'000'000'007
#define OO 2'000'000'000
#define EPS 1e-9
#define PI acos(-1)

void AhMeD_HoSSaM(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    #endif
}

struct Graph {

    struct Edge {
        
        int v;
        ll c;    

        Edge(int V = 0, ll C = 0){
            v = V, c = C;
        }
    
        bool operator < (const Edge& e) const {
            return c > e.c;
        }
    };

    int n, m, connected_components;
    vector < vector < int > > adj;
    // vector < vector < Edge > > adj;   //If we need to use dijkstra
    vector < bool > vis;
    vector < int > depth, parent, deg;
    
    Graph(int N, int M){
        n = N, m = M;
        connected_components = 0;
        adj.resize(n + 10); 
        vis.resize(n + 10); 
        depth.resize(n + 10); 
        parent.resize(n + 10);
        deg.resize(n + 10);
    }

    void add_edge(int u, int v){
        adj[u].push_back(v), adj[v].push_back(u);
        deg[u]++, deg[v]++;
    }

    // If we need to use dijkstra

    /*void add_edge(int u, int v, int w){ 
        adj[u].push_back({v, w}), adj[v].push_back({u, w});
    }*/

    void remove_edge(int u, int v){
        adj[u].erase(find(all(adj[u]), v)), adj[v].erase(find(all(adj[v]), u));
    }

    void build_adj(){
        for(int i = 0, u, v; i < m && cin >> u >> v; i++)
            add_edge(u, v);
    }

    void dfs(int node, int dep = 0, int par = -1){
        vis[node] = true, parent[node] = par, depth[node] = dep;
        for(auto& new_node : adj[node])
            if(!vis[new_node])
                dfs(new_node, dep + 1, node);
    }

    bool is_cycle(int node, int par){
        vis[node] = true;
        for(auto& new_node : adj[node]){
            if(!vis[new_node]){
                if(is_cycle(new_node, node))
                    return true;
            }
            else if(new_node != par)
                return true;
        }
        return false;
    }

    void get_path(int node){
        if(parent[node] == node) return;
        cout << node << " ";
        get_path(parent[node]);
    }

    void topology (){
        queue < int > topo;
        vector < int > graph;
        for(int i = 1; i <= n; i++)
            if(deg[i] == 1) topo.push(i), deg[i]--;
        while(!topo.empty()){
            int curr_node = topo.front();
            topo.pop();
            graph.push_back(curr_node);
            for(auto& new_node : adj[curr_node]){
                deg[new_node]--;
                if(deg[new_node] == 1)
                    topo.push(new_node);
            }
        }
        reverse(all(graph));
        cout(graph);
    }

    int bfs(int from, int to){
        if(from == to) return 0;
        queue < int > BFS;
        depth.assign(n + 10, OO);
        vis[from] = true, depth[from] = 0;
        BFS.push(from);
        while(!BFS.empty()){
            int sz = sz(BFS);
            while(sz--){
                int curr_node = BFS.front();
                BFS.pop();
                for(auto& new_node : adj[curr_node]){
                    if(!vis[new_node]){
                        BFS.push(new_node), parent[new_node] = curr_node; 
                        depth[new_node] = min(depth[new_node], depth[curr_node] + 1);
                        vis[new_node] = true;
                    }
                }
            }
        }
        return depth[to];
    }

    // Remove the comment if you need to use Dijkstra

    /*void dijkstra(int from){
        priority_queue < Edge > Dij;
        depth[from] = 0;
        Dij.push({from, 0});
        while(!Dij.empty()){
            auto curr_node = Dij.top();
            Dij.pop();
            if(curr_node.c > depth[curr_node.v]) continue;
            for(auto& new_node : adj[curr_node.v]){
                if(depth[new_node.v] > curr_node.c + new_node.c){
                    Edge add = new_node;
                    add.c += curr_node.c;
                    Dij.push(add); 
                    depth[new_node.v] = curr_node.c + new_node.c;
                }
            }
        }
    }*/

};

void Solve(){
    
}

int main(){
    AhMeD_HoSSaM();
    int t = 1;
    //cin >> t;
    while(t--)
        Solve();
    Time
    return 0;
} 