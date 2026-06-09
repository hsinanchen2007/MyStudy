### 解题思路
对与回溯算法的理解

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> input;
        vector<bool> used(nums.size(),false);
        permute(result, input, used,nums);
        return result;
    }
    void permute(vector<vector<int>>& result,vector<int> input,vector<bool>& used,vector<int> nums){
        if (input.size() == used.size()) {
            result.push_back(input);
            return;
        }
        // 全排列为二叉树选择树,遵循深度优先原则,每次会结算一种组合,
        // 全排列的核心是,数字不可重复使用,所以每次前序遍历要标记当前位已使用,在进行遍历,并且要在后序遍历中取消选择,保证下一次选择使用
        for (int i=0; i < nums.size(); i++) {
            //这里解释一下 !used[i-1] 和used[i-1] 为什么结果是一样的
            //1. 使用 `!` :表示左-1位未选择,则跳过,左1位value相同且未选择的状态只有一种,拥有同一父节点的左子节点已经排列完成,所有标记位已取消选择.也就是说相同元素已经排列完毕,此时应跳过此元素,直接对下一位进行排列.结果是 相同值取左节点排列结果
            //2. 不使用 `!` :与上述情况相反,如果左1位 已选择则跳过,此时也有且只有一种情况,左节点到低时发现相邻节点value相同,则跳过.取右节点排列结果
            if (used[i] || (i>0 && nums[i] == nums[i-1] && !used[i-1]))
                continue;
            //前序遍历选择
            used[i]=true;
            //组合当前位
            input.push_back(nums[i]);
            //遍历
            permute(result, input, used, nums);
            //后序遍历,取消选择,移除选择数据
            used[i]=false;
            input.pop_back();
            
            
        }
        
    }
};
```