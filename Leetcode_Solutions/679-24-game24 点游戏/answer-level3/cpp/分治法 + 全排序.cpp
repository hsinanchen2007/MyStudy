其实这道题可以看做[241. 为运算表达式设计优先级](https://leetcode-cn.com/problems/different-ways-to-add-parentheses/)和[31. 下一个排列](https://leetcode-cn.com/problems/next-permutation/)的结合，偷懒直接用了自带的next_permutation。反正都是O(1)就懒得剪枝了（逃
```c++ []
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> dnums(nums.begin(), nums.end());
        sort(dnums.begin(), dnums.end());
        do {
            vector<double> tries = dfs(dnums, 0, 4);
            for (auto x : tries) {
                if (abs(x - 24) < 1e-3) return true;
            }
        } while (next_permutation(dnums.begin(), dnums.end()));
        return false;
    }

    double op(double n1, double n2, int s) {
        switch (s) {
            case 0: return n1 + n2;
            case 1: return n1 - n2;
            case 2: return n1 * n2;
            case 3: return n1 / n2;
        }
        return 0;
    }
    
    vector<double> dfs(vector<double>& nums, int front, int rear) {
        vector<double> res;
        if (rear - front == 1) res.push_back(nums[front]);
        for (int i = front + 1; i < rear; ++i) {
            vector<double> left = dfs(nums, front, i);
            vector<double> right = dfs(nums, i, rear);
            for(auto x : left) for(auto y : right) for(int j = 0; j < 4; ++j) 
                res.push_back(op(x, y, j));
        }
        return move(res);
    }
};
```
