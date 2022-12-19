### 解题思路
初看题目，觉得预处理（保存上下级关系和子节点个数）后可以直接做，提交发现最后一个case超时，看数据发现4w多个节点退化为单链表结构，怎么都过不了，想到各种优化点都不行。
只能想其他方法了，题目特性很适合线段树，但是这里有个问题，线段树是二叉树，但这里是一颗多叉树，没法直接使用线段树。
这里有个技巧，使用dfs，重新给节点分配新的值，包括入口节点和出口节点，并且是连续的，这样就可以满足条件构建线段树了

### 代码

```cpp
using ll = long long;
const int E = 1000000007;
struct Node {
    Node *l, *r;
    int s, e, m, coin, two;
    Node(int s_, int e_) : s(s_), e(e_), m((s_ + e_) >> 1), coin(0), two(0) {
        build(s_, e_);
    }

    void build(int start, int end) {
        if (start == end) {
            l = r = NULL;
            return;
        }
        l = new Node(start, m);
        r = new Node(m + 1, end);
    }

    void update(int start, int end, int val) {
        if (start > e || end < s || start > end) return;
        coin += (ll)(end - start + 1) * val % E; // 对于更新节点的父节点都要加上更新值
        coin %= E;
        if (start == s && end == e) { //找到更新节点
            if (s < e) two += val; // 非叶子节点需要加上更新值，延迟更新子节点数据
            return;
        }
        down(); // 将当前节点的two值向子节点
        if (m < start) r->update(start, end, val);
        else if (m > end) l->update(start, end, val);
        else {
            l->update(start, m, val);
            r->update(m + 1, end, val);
        }
    }

    void down() {
        if (two > 0) {
            l->coin += (ll)two*(l->e - l->s + 1) % E;
            l->two += two;
            r->coin += (ll)two*(r->e - r->s + 1) % E;
            r->two += two;
            two = 0;
        }
    }

    ll query(int start, int end) {
        if (start > e || end < s || start > end) return 0;
        if (start == s && end == e) { // 找到要查询的节点直接返回即可
            return coin;
        }
        down(); // 没有找到时，将当前节点的two值向子节点
        if (m < start) return r->query(start, end);
        else if (m > end) return l->query(start, end);
        return (l->query(start, m) + r->query(m + 1, end)) % E;
    }
};

class Solution {
public:
    vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
        vector<int> vin(n + 1);  // dfs的入口节点映射
        vector<int> vout(n+1);   // dfs的出口节点映射
        vector<vector<int>> vson(n + 1); // 子节点数组
        for (auto& i : leadership)  vson[i[0]].push_back(i[1]);
        int idx = -1, k;
        dfs(vson, vin, vout, 1, idx);

        vector<int> ans;
        Node tree(0, n - 1); // 构建线段树
        for (auto& i : operations) {
            k = i[1];
            if (i[0] == 1) tree.update(vin[k], vin[k], i[2]);
            else if (i[0] == 2) tree.update(vin[k], vout[k], i[2]);
            else ans.push_back(tree.query(vin[k], vout[k]) % E);
        }
        return ans;
    }

    void dfs(vector<vector<int>>& vson, vector<int>& vin, vector<int>& vout, int k, int& idx) {
        vin[k] = ++ idx;
        for (auto& i : vson[k]) dfs(vson, vin, vout, i, idx);
        vout[k] = idx; 
    }
};
```