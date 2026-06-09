### 解题思路
![image.png](https://pic.leetcode-cn.com/fe2168bd62cec679337dcd19128295af2ef1a357e8225dc902847609f481b847-image.png)

```
            if(i > start && nums[i] == nums[i-1]){
                continue;
            }
```
回溯保证的就是相同的元素在（1）同一个树高度，（2）同一个父节点；两个条件情况下，只能选择一个；
1->{2,2,2}
其中1 是父节点，那么{2,2,2} 在1 这个父节点下面只能选择一个；
### 代码

```cpp
class Solution {
public:
    // 回溯法 就是一棵树
    // 回溯保证的就是相同的元素在同一个父节点下的同一个高度不能别使用两次，只能选一个；1->{2,2,2}，2只能选一个
    void suba(vector<vector<int>>& result,vector<int>& nums,int start,vector<int> ans){
        if(start == nums.size()) return ;
        for(int i = start;i<nums.size();i++){
            if(i > start && nums[i] == nums[i-1]){
                continue;
            }
            ans.push_back(nums[i]);
            result.push_back(ans);
            suba(result,nums,i+1,ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        int size = nums.size();
        if(size == 0) return result;
        sort(nums.begin(),nums.end());
        vector<int> ans;
        suba(result,nums,0,ans);
        result.push_back({});
        return result;
    }
};
```