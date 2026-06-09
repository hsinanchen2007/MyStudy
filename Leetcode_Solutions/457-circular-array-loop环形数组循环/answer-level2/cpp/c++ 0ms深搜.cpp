归结为简单的有向图找环问题，在有向图中有环等价于深搜时存在反向边，即存在结点到其在搜索树中某个祖先的边。
但是本题加了一些限制条件：不能自成环（也就是环的长度大于一），而且环必须要按单方向生成。
处理第一个条件可以简单地去掉自己到自己的边，也就是`next==i`的case。
处理第二个条件可以将dfs分成两类，分别是forward和backward，一个是正向，一个是反向。两者互不干扰，在正向寻找的时候遇到反向结点就停止搜索，因为这种情况下不可能找到符合要求的环了。
```cpp
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        enum {WHITE = 0, GREY, BLACK};
        vector<int> visited(n, WHITE);
        bool res = false;
        function<void(int, bool)> dfs = [&](int i, bool forward) {
            if ((forward && nums[i] < 0) || (!forward && nums[i] > 0)) return;
            if (visited[i] == GREY) {
                res = true;
            }
            if (visited[i] != WHITE) return;
            visited[i] = GREY;
            int next = (i+nums[i]) % n;
            next = next < 0 ? next + n : next;
            if (next != i) dfs(next, forward);
            visited[i] = BLACK;
        };
        for (int i = 0; i < n; i++) {
            if (visited[i] == WHITE) dfs(i, nums[i] > 0);
        }
        return res;
    }
};
```