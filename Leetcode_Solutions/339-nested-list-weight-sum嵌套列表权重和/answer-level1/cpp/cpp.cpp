![image.png](https://pic.leetcode-cn.com/8037c277ba3360927f2e22ea13f5b582b3891c6bf5d328c5d6289dd5173c99ea-image.png)

最基本的dfs，需要加个缺省参数

```
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList, int depth = 1) {
        int sum = 0;
        for (const auto& nestedInteger : nestedList) {
            if (nestedInteger.isInteger()) {
                sum += nestedInteger.getInteger() * depth;
            } else {
                sum += depthSum(const_cast<vector<NestedInteger>&>(nestedInteger.getList()), depth + 1);
            }
        }
        return sum;
    }
};
```

