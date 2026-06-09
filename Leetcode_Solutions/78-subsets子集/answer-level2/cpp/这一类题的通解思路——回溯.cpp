![image.png](https://pic.leetcode-cn.com/0b7df9412a9fdab338f3276f289c6931710b789aec7e9f4a7cc4ab403f8f1011-image.png)

```
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void backtrack(vector<int>& nums, int index, int len){
        if(path.size()==len){
            res.emplace_back(path);
            return ;
        }
        for(int i=index;i<nums.size();i++){
            path.emplace_back(nums[i]);
            backtrack(nums,i+1,len);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        for(int i=0;i<=nums.size();i++){
            backtrack(nums,0,i);
        }
        return res;
    }

};
```
