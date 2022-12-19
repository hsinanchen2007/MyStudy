这题很容易构造成图的问题，将可以跳的两个楼转换为两个结点连一条有向边，这些楼的关系就变成了有向无环图，要求的就是最长的一条路径。求解的过程本质上与记忆化递归、dp是相同的，只不过用图的方法套路化，代码也复杂了一些。

求一个有向无环图的最长路径可以用拓扑排序的方法，这里的边长都为1，更加简单。

```
struct Edge{
    int to, next;
};

class Solution {
private:
    const static int maxm = 1000003 / 2;
    const static int maxn = 1001;
    Edge edges[maxm];
    int head[maxn], inNum[maxn];
    int now;
    int n;
    
    static inline int min(int a, int b) {
        return a < b ? a : b;
    }
    
    static inline int max(int a, int b) {
        return a > b ? a : b;
    }
    
    
public:
    
    void initData() {
        memset(edges, 0, sizeof(edges));
        memset(head, 0, sizeof(head));
        memset(inNum, 0, sizeof(inNum));
        now = 0;
        n = 0;
    }
    
    void addEdge(int a, int b) {
        now++;
        edges[now].next = head[a];
        edges[now].to = b;
        head[a] = now;
        inNum[b]++;
    }
    
    void makeMap(const vector<int> & arr, int d) {
        this->n = arr.size();
        int len = this->n;
        for(int i = 0; i < len; ++i) {
            int left = max(0, i - d), right = min(i + d, len - 1);
            int tempMax = 0;
            for(int j = i - 1; j >= left; --j) {
                if(arr[j] >= arr[i]) {
                    left = j + 1;
                    break;
                }
            }
            for(int j = i + 1; j <= right; ++j) {
                if(arr[j] >= arr[i]) {
                    right = j - 1;
                    break;
                }
            }
            for(int j = left; j < i; ++j) {
                addEdge(i, j);
            }
            for(int j = i + 1; j <= right; ++j) {
                addEdge(i, j);
            }
        }
    }
    

    int topoSort() {
        int ret = 0;
        static int mStack[maxn];
        int top = -1;
        static int dis[maxn];
        for(int i = 0; i < n; ++i)
            dis[i] = 1;
        for(int i = 0; i < n; ++i) {
            if(inNum[i] == 0) {
                mStack[++top] = i;
                dis[i] = 1;
            }
        }
        for(int k = 0; k < n; ++k) {
            int u = mStack[top--];
            for(int i = head[u]; i; i = edges[i].next) {
                int v = edges[i].to;
                inNum[v]--;
                if(inNum[v] == 0) {
                    mStack[++top] = v;
                    
                }
                dis[v] = max(dis[v], dis[u] + 1);
            }

        }
        for(int i = 0; i < n; ++i)
            ret = max(ret, dis[i]);
        return ret;
    }
    
    
    int maxJumps(vector<int>& arr, int d) {
        initData();
        makeMap(arr, d);
        return topoSort();
    }
};
```
