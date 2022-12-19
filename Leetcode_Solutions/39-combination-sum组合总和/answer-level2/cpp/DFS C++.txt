### 解题思路
解题思路跟[@liweiwei1419](/u/liweiwei1419/) 这位大神的思路是一样的，但我没有加入对candidates排序进行剪枝提速。
这位大神的画图对去重的解释，对我来说其实有些看不懂，我从另一个思路讲解去重：

输入是2,3,6,7。

当在第一层递归时，for循环里选择2，经过深层的递归，就已经得出了2开头的所有可能性，在这些可能性里，也会包含3。所以在这里已经得出了同时包含2和3的所有组合。

所以在for循环里选择3的时候，就不要再考虑2了。

所以在每一层递归时，承接上一层传过来的searchBegin作为初始的搜索开头。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        step(candidates, target, current, 0, result);
        return result;
    }

    /**
     *
     * @param candidates    备选的数字
     * @param target        本层需要拼凑的目标值
     * @param current       已经拼凑进去的数值
     * @param searchBegin   candidates中哪个地方可是搜索
     * @param result        已有的答案
     */
    void step(vector<int>& candidates, int target, vector<int>& current, int searchBegin, vector<vector<int>>& result) {
        for (int index = searchBegin; index < candidates.size(); ++ index) {
            if (candidates[index] == target) {
                current.push_back(candidates[index]);
                result.push_back(current);
                current.pop_back();
            }
            else if (candidates[index] > target) {
                continue;
            }
            else {
                current.push_back(candidates[index]);
                step(candidates, target-candidates[index], current, index, result);
                current.pop_back();
            }
        }
    }
};
```

![微信截图_20200407005344.png](https://pic.leetcode-cn.com/913b9b818a205eec8e3b41950b9724507aca6229b7d1de3e567f9bb2088fa539-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200407005344.png)
