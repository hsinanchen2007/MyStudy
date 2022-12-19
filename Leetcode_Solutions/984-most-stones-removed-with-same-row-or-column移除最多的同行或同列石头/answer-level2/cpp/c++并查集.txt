**题意**：移除掉部分石头，使得剩下的石头不会出现在同一列或同一行。计算能够移除石头的最大个数。
**思路**：
**想法1**，深度或广度优先遍历，从某一个石头出发，将其加入到一个集合中（例如：队列），然后将其同一行和同一列的石头也加入集合中，递归查找；最后判断一共形成了多少个集合（即，移除最多石头后，剩下的石头个数）。
**想法2**，基于想法1，可以利用并查集这一数据结构，将相互关联的行列合并。**注意**，为了区别行列，行从0到10000，列从0+10001到10000+10001，来表示。

以下为采取并查集的代码：
```c++

class Solution {
public:
    int find(int cur, vector<int> &parent) {
        if (cur == parent[cur]) {
            return cur;
        }
        parent[cur] = find(parent[cur], parent);
        return parent[cur];
    }

    int removeStones(vector<vector<int>>& stones) {
        // 移除掉部分石头，使得剩下的石头不会出现在同一列或同一行
        // 能够取出的最多的石头数量

        int MAX_N = 10001;
        // 通过石头会将某一行和某一列相关联，该行该列上的石头属于同一个集合
        vector<int> parent(MAX_N * 2, 0);
        for (int i = 0; i < MAX_N * 2; i ++) {
            parent[i] = i;
        }

        // 找出总的集合个数
        unordered_set<int> nums;
        for (vector<int> stone : stones) {
            if (nums.find(stone[0]) == nums.end()) {
                nums.insert(stone[0]);
            }
            if (nums.find(stone[1] + MAX_N) == nums.end()) {
                nums.insert(stone[1] + MAX_N);
            }
            if (stone[0] != stone[1] + MAX_N) {
                int p0 = find(stone[0], parent);
                int p1 = find(stone[1] + MAX_N, parent);
                if (p0 != p1) {
                    parent[p1] = p0;
                }
            }
        }

        unordered_set<int> ans;
        for (int i : nums) {
            int pi = find(i, parent);
            if (ans.find(pi) == ans.end()) {
                ans.insert(pi);
            }
        }
        return stones.size() - ans.size();
    }
};
