### 解题思路
跟组合总和I的思路差不多，就是DFS的思路。
有一个重要的注意的是：针对candidates需要排序，然后在某层递归实现时，去除它曾经遇到过的重复的candidate。
比如1,2,2,2,5
```
第一层递归考虑1（index=0），交给第二层递归去寻找满足5-1=4的组合，并指示在candidates中从index=1开始寻找。
    第二层递归考虑2（index=1），交给第三层丢给去寻找满足4-2=2的组合，并指示在condidates中从index=2开始寻找。
        第三层递归考虑2（index=2），满足条件，答案（1,2,2）纳入result。
        第三层递归考虑2（index=3），满足条件，答案（1,2,2），自己曾经遇到过，忽略。
        第三层递归考虑5（index=4），不满足条件，忽略。
    （于是到这里，在有1的前提下，至少有一个2的所有情况都考虑完了，下面再遇到2，就可以忽略了。）
    第二层递归考虑2（index=2），自己曾经遇到过，忽略
    第二层递归考虑2（index=3），自己曾经遇到过，忽略
    第二层递归考虑5（index=4），大于4，忽略
```

。。。。（以此类推）


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
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
            // 去除它曾经遇到过的重复的candidate
            if (index > searchBegin && candidates[index] == candidates[index - 1]) {
                continue;
            }
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
                step(candidates, target-candidates[index], current, index + 1, result);
                current.pop_back();
            }
        }
    }
};
```
![微信截图_20200407014735.png](https://pic.leetcode-cn.com/9d6d8f9629946d8f4863b6eaa8fc42a8b174e5a035bb707ccaf149af768bf763-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200407014735.png)
