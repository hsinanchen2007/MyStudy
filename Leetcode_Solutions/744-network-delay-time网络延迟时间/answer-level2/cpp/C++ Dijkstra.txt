```
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int> > adj(N + 1, vector<int>(N + 1, INT_MAX));
        vector<int> dist(N + 1, INT_MAX);
        vector<bool> visited(N + 1, false);
        dist[K] = 0;
        visited[K] = true;
        for (auto& e : times) {
            adj[e[0]][e[1]] = e[2];
            if (e[0] == K) {
                dist[e[1]] = e[2];
            }
        }
        for (int i = 1; i < N; ++i) {
            int min_dist = INT_MAX;
            int min_ind = -1;
            for (int j = 1; j <= N; ++j) {
                if (!visited[j] && dist[j] < min_dist) {
                    min_dist = dist[j];
                    min_ind = j;
                }
            }
            if (min_dist == INT_MAX)
                return -1;
            visited[min_ind] = true;
            for (int j = 1; j <= N; ++j) {
                if (!visited[j] && adj[min_ind][j] != INT_MAX && 
                        min_dist + adj[min_ind][j] < dist[j])
                    dist[j] = min_dist + adj[min_ind][j];
            }
        }
        int max_dist = -1;
        for (int i = 1; i <= N; ++i)
            if (max_dist < dist[i])
                max_dist = dist[i];
        return (max_dist == INT_MAX) ? -1 : max_dist;
    }
};
```
