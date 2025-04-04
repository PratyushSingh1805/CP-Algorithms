// returns shortest path array
vector<ll> dijkstra(ll src, ll n, vector<vector<pl>>& adj) {
    n++;
    vl dist(n, LLONG_MAX); // Distance array
    priority_queue<pl, vector<pl>, greater<pl>> pq; // Min-heap
    
    dist[src] = 0;
    pq.push({0, src});
    
    while (!pq.empty()) {
        ll u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();
        
        if (d > dist[u]) continue; 
        
        for (auto edge : adj[u]) {
            ll v = edge.second;
            ll weight = edge.first;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
   return dist;
}
