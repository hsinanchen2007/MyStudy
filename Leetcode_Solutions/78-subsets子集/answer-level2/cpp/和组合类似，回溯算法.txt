### 解题思路
此处撰写解题思路
和组合类似，只是res不是放在最后了，而是灵活到for循环里
### 代码

```cpp
class Solution {
    vector<vector<int>>res;
    vector<int>path;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size()==0) return {};
        backtrace(nums,0,0);
        res.push_back(path);
        return res;
    }
    void backtrace(vector<int>&nums,int k,int start){
        if(k==nums.size()) return ;
        for(int i=start;i<nums.size();i++){
            path.push_back(nums[i]);
            res.push_back(path);
            backtrace(nums,k+1,i+1);
            path.pop_back();
        }
    }
};
```