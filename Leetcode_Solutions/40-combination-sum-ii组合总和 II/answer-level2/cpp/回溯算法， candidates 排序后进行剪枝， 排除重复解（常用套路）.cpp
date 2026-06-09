### 解题思路
本题与 [组合总和](https://leetcode-cn.com/problems/combination-sum/) 相似， 不同点在于 candidates 中每个元素不可重复使用， 这个可以通过让下层索引开始位置 +1 实现， 还有就是不能有重复的解， 可以考虑排序 candidates 遍历时和前一个兄弟节点比较， 相同的则排除。
去除重复的解， 这种理论依据是排序过的数组， 如果非起始分支， 并且数值与前一个分支相同， 则此分支可以剪枝， 因为前一个分支的数据遍历范围是大于此分支的， 如果还相同， 那此份之属于与前一个分支肯定是相同的， 这也是回溯算法剪枝的常用套路之一
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        __combinationSum(candidates, target, temp, 0);
        return res;
    }
private:
    void __combinationSum(vector<int>& candidates, int target, vector<int> temp, int start){
        if(target == 0){
            res.push_back(temp);
        }else{
            for(int i = start; i < candidates.size(); i++){
                if( i > start && candidates[i - 1] == candidates[i]){
                    continue;  // 去除重复的解， 这种理论依据是排序过的数组， 如果非起始分支， 并且数值与前一个分支相同， 则此分支可以剪枝， 因为前一个分支的数据遍历范围是大于此分支的， 如果还相同， 那此份之属于与前一个分支肯定是相同的， 这也是回溯算法剪枝的常用套路之一
                }
                if(target >= candidates[i]){
                    temp.push_back(candidates[i]);
                    __combinationSum(candidates, target - candidates[i], temp, i + 1);
                    temp.pop_back();
                }
            }
        }
    }
};
```