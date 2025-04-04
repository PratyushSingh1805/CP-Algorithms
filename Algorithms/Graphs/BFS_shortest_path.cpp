// returns shortest paths array for a uniweighted undirected graph
vector<ll> bfs(ll src, vvl& adj, ll n) {
    n++;
    vl dist(n, LLONG_MAX);
    
    queue<ll> q;
    
    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        ll node = q.front();
        q.pop();

        for (ll neighbor : adj[node]) {
            if (dist[neighbor] == LLONG_MAX) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return dist;
}
