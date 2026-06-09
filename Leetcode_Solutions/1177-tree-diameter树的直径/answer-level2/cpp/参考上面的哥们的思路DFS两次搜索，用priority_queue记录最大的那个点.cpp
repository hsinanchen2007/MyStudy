```
class Solution {
public:
    typedef struct {
        int val;
        int step;
    } P;

    struct cmp {
        bool operator() (P &a, P &b) {
            return a.step < b.step;
        }
    };

    int treeDiameter(vector<vector<int>>& edges) {
        if (edges.size() == 0) {
            return 0;
        }
        vector<vector<int> > graph(edges.size() + 1);
        initGraph(graph, edges);
        vector<bool> isVisit(edges.size()+1, false);
        priority_queue<P, vector<P>, cmp> dests;
        dfs(0, dests, -1, graph, isVisit);
        P firstDest = dests.top();

        vector<bool> isVisit2(edges.size()+1, false);
        priority_queue<P, vector<P>, cmp> dests2;
        dfs(firstDest.val, dests2, -1, graph, isVisit2);
        return dests2.top().step;
    }

    void initGraph(vector<vector<int> > &graph, vector<vector<int> > &edges)
    {
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
    }

    void dfs(int point, priority_queue<P, vector<P>, cmp> &dests, int step, vector<vector<int> > &graph, vector<bool> &isVisit)
    {
        step++;
        if (isVisit[point]) {
            return;
        }
        isVisit[point] = true;
        dests.push(P{point, step});

        for (int i = 0; i < graph[point].size(); i++) {
            dfs(graph[point][i], dests, step, graph, isVisit);
        }
        return;
    }
};
```
