### 代码

```cpp
class Solution {
public:
    const int INF = 0x3f3f3f3f;
    int f[10005];
    
    struct Node {
        int l, r;
        Node() : l(-1), r(-1) {}
        Node(int _l, int _r) : l(_l), r(_r) {}
        bool operator < (const Node& other) const {
            if (l == other.l) return r > other.r;
            return l < other.l;
        }
    };
    int minTaps(int n, vector<int>& ranges) {
        vector<Node> nodes(n + 1);
        for (int i = 0; i <= n; ++i) {
            nodes[i] = Node(i - ranges[i], i + ranges[i]);
        }
        memset(f, INF, sizeof(f));
        f[0] = 0;
        sort(nodes.begin(), nodes.end());
        for (int i = 0; i <= n; ++i) {
            int l = max(nodes[i].l, 0);
            int r = min(nodes[i].r, n);
            for (int j = l; j <= r; ++j) {
                f[j] = min(f[j], f[l] + 1);
            }
        }
        return f[n] == INF ? -1 : f[n];
    }
};
```

![image.png](https://pic.leetcode-cn.com/6afbddc890371711c2d454e40d235d5f83cae3ebfabf826542d28fb1e6a28f53-image.png)
