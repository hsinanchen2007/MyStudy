这道题目本身不是非常难，难得是细节。

很多个坑点：
1. 点可以重复
2. 斜率精度问题
3. 只有一个点或者没有点

其实都只是边界问题。

这道题目归根结底就是枚举，枚举所有点对的情况。我们可以先固定一个点 a，然后基于这个点去枚举其它所有的点 b 与点 a 之间形成的线段的斜率。然后遇到相同斜率的，那么就可以计算出现次数最大的斜率出现了多少次，最后加上固定点 a 出现的次数，这样就可以了。

但是这里会有个坑，斜率如果直接用 double 来表示，精度会是一个很大的问题，这里不知道其它大佬怎么解决的，反正我是将斜率表示出来的。

众所周知，斜率实际上可以写成下面的式子:

```Latex
k = (y2 - y1) / (x2 - x1)
```

但是这个式子坑太多了，且不说精度问题，x2 == x1 的情况就经常让人很难受了。所以我将这个式子转换为了：

```Latex
k = (y2 - y1) // (x2 - x1) + (y2 - y1) % (x2 - x1)
```

所以实际上，如果我们想要表示一个斜率，只需要给出一个 a 表示斜率的整数部分，b 表示余数部分，c 表示除数。这样就可以完全表示一个斜率。

因此，代码就很简单了，下面贴上我的挫代码：

```cpp
typedef struct node {
    int x, y, z;
    node(int _x = 0, int _y = 0, int _z = 0): x(_x), y(_y), z(_z) {}
    bool operator < (const node& n) const {
        if (x != n.x) {
            return x < n.x;
        } else {
            return y < n.y;
        }
    }
    bool operator == (const node &n) const {
        long long tmpX = n.z;
        long long tmpY = (n.x * n.z + n.y);
        return tmpY * z == tmpX * (x * z + y);
    }
}Node;

struct hash_method {
    size_t operator() (const node &n) const {
        int tmpX = n.z;
        int tmpY = (n.x * n.z + n.y);
        return tmpX == 0 ? 0 : tmpY / tmpX;
    }
};

class Solution {
private:
    map<Node, int> p;
    unordered_map<Node, int, hash_method> k;
    int max(int a, int b) {
        return a >= b ? a : b;
    }
    Node getK(int x1, int y1, int x2, int y2) {
        if (x2 - x1 == 0) return Node(0, (y2-y1), 0);
        return Node((y2-y1)/(x2-x1),(y2-y1)%(x2-x1),(x2-x1));
    }
    vector<vector<int>> getNonRepeatingPoints(vector<vector<int>>& points) {
        for (int i = 0; i < points.size(); ++i) {
            p[Node(points[i][0], points[i][1])] += 1;
        }
        vector<vector<int>> res;
        for (auto it = p.begin(); it != p.end(); ++it) {
            auto pa = it->first;
            vector<int> tmp;
            tmp.push_back(pa.x);
            tmp.push_back(pa.y);
            res.emplace_back(tmp);
        }
        return res;
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        vector<vector<int>> pp = getNonRepeatingPoints(points);
        int res = 1;
        for (int i = 0; i < pp.size(); ++i) {
            int tmp = p[Node(pp[i][0], pp[i][1])];
            k.clear();
            for (int j = i + 1; j < pp.size(); ++j) {
                Node kk = getK(pp[i][0], pp[i][1], pp[j][0], pp[j][1]);
                k[kk] += p[Node(pp[j][0], pp[j][1])];
                res = max(res, tmp + k[kk]);
            }
            res = max(res, tmp);
        }
        return res;
    }
};
```

效果如下：

![截屏2019-12-10下午11.16.25.png](https://pic.leetcode-cn.com/1f534ce72004fe0dd62e0f30eaa8f7683cd220935411ee5452621491a753a9c9-%E6%88%AA%E5%B1%8F2019-12-10%E4%B8%8B%E5%8D%8811.16.25.png)
