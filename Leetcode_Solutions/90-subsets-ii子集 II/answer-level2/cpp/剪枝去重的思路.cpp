### 解题思路
本题与 [总的组合 II](https://leetcode-cn.com/problems/combination-sum-ii/) [全排列 II](https://leetcode-cn.com/problems/permutations-ii/) 类似， 关键点在于如何在回溯中进行剪枝
这种需要去除 解集中重复的子集 的题目通常都需要对输入的元素进行排序， 目的是让相同的元素聚在一起， 这样可以据此进行剪枝。 排序后观察选取到重复的解的特点（元素不可重复使用， 这个使用 start 标记开始位置即可解决）， 都发生在有 2 个和以上个相同的元素被先后选区的过程例如输入参数 [1, 1', 2] （1' 是为了理解方便加的）， 此时
[1] [1'] 
[1, 2] [1', 2] 
[1, 1', 2] [1', 1, 2]
.....
就是重复的解， 总的来说就是： 2 个和以上个相同的元素排列组合只会有一种情况 [1] 与 [1'] ; [1, 1'] 与 [1, 1'] 是相同的， 排除这种就可以（从这也可以看出为啥要先排序了， 不排序的化相同的元素都分散在各处了）， 方法就是判断i > start && nums[i - 1] == nums[i] 即可，其中 i > start是为了让  nums[i - 1] 在循环中一直有意义。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        __subsetsWithDup(nums, 0, tmp);
        return res;
    }
private:
    void __subsetsWithDup(vector<int>& nums, int start, vector<int> &tmp){
        res.push_back(tmp);
        for(int i = start; i < nums.size(); i++){
            if(i > start && nums[i - 1] == nums[i])
                continue;
            tmp.push_back(nums[i]);
            __subsetsWithDup(nums, i + 1, tmp);
            tmp.pop_back();
        }
    }
};
```