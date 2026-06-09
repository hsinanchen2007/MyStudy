由于只有5层结构，因此使用树状数组来存储数据最为简单方便，只需要64个大小的空间即可。
代码如下：
```
class Solution {
public:
    pair<int, int> helper(vector<int>& nodes, int ind) {
        if (nodes[ind] == -1) return {0, 0};
        auto left = helper(nodes, 2 * ind + 1);
        auto right = helper(nodes, 2 * ind + 2);
        int count = max(left.second + right.second, 1); // root值被使用几次
        int value = left.first + right.first + nodes[ind] * count; // root及其子树所有可能的路径加和
        return {value, count};
    }
    int pathSum(vector<int>& nums) {
        vector<int> nodes(64, -1); // 能容下6层数组，防止下标溢出
        for (auto x : nums) {
            int val = x % 10;
            int pos = (x / 10) % 10;
            int dep = x / 100;
            int ind = (1 << (dep - 1)) - 1 + pos - 1;
            nodes[ind] = val;
        }
        return helper(nodes, 0).first;
    }
};
```
![image.png](https://pic.leetcode-cn.com/0b455fd1da3f98955ce407a8e4e572dcb76534c31e4576d88a207e3287112b03-image.png)

