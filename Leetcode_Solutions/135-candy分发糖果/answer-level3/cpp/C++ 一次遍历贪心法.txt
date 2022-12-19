见代码详细注释：
```
class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) return 0;
        ratings.push_back(INT_MAX); // 添加末尾最大值保证最后一定能触发降序终止的条件
        int N = ratings.size();
        vector<int> cands(N, 1);
        int left = 0; // 降序序列的起始位置
        for (int i = 1; i < N; ++i) {
            // 降序序列终止
            if (ratings[i] >= ratings[i - 1]) {
                cands[i - 1] = max(cands[i - 1], 1);
                // 回溯逐渐加一
                for (int j = i - 2; j >= left; --j)
                    cands[j] = max(cands[j], cands[j + 1] + 1);
                // 处理当前元素
                if (ratings[i] == ratings[i - 1]) cands[i] = 1;
                else cands[i] = max(cands[i], cands[i - 1] + 1);
                // 重置left
                left = i;
            }
        }
        int res = 0;
        for (int i = 0; i < N - 1; ++i) res += cands[i];
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/941092532b0e2139a0e761ab483c33bc2d598a8d22589c50b6aa1c4e60d76b07-image.png)
