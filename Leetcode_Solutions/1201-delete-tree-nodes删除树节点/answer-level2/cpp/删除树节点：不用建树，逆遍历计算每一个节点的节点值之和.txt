这道题给出的节点编号是按照层次遍历给出的，所以我们可以逆遍历一次，并用一个数组记录每一个节点节点值之和，如果某一个节点的节点值之和为0，我们就把这个节点以及其子树的所有节点都标记一下，最后统计一下没有标记的节点有哪些即可。（第一次发布题解，请大家多多指正）
```
class Solution {
   public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        int n = parent.size();
        vector<int> sum(n, 0), vis(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            sum[i] += value[i];
            if (parent[i] == -1) continue;
            sum[parent[i]] += sum[i];   //记录每一个节点的节点值之和
        }
        int ans = n;
        //顺序遍历，把节点值之和为0的点以及其子节点全都标记一遍
        for (int i = 0; i < n; i++) {
            if (sum[i] == 0 || (parent[i] != -1 && vis[parent[i]] == 1)) {
                ans--;
                vis[i] = 1;
            }
        }
        return ans;
    }
};
```
[https://github.com/gxsoar/LeetCode_Practice]