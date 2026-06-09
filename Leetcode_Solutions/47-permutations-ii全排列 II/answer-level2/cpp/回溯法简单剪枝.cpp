```C++ []
class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& nums, vector<int>& curr, vector<int>& visited){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(visited[i]) continue;
            if(i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) continue;
            curr.push_back(nums[i]);
            visited[i] = 1;
            backtrack(ans, nums, curr, visited);
            curr.pop_back();
            visited[i] = 0;
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        vector<int> visited(nums.size(), 0);
        backtrack(ans, nums, curr, visited);
        return ans;
        
    }
};
```

这个题和上一个全排列的题只是差一个剪枝的问题。

1. 首先将给定的数组排序，这样的好处就是相同的数字一定是连续的，处理起来比较简单

2. 按照之前的写法写出全排列

3.写出的全排列必定会包含重复的项，此时我们在适当的位置进行剪枝。            
if(i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) continue;
首先确保i-1有意义，然后判断改数字是否为重复的，如果这个数字是重复的，那么就判断它前面的字符是否被访问，如果没被访问，我们直接将这一项跳过就可以了。
