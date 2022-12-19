
### 方法1
迭代，碰到重复数字跳过，见注释

```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        sort(nums.begin(), nums.end());
        int start = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            start = (i && nums[i] == nums[i - 1])?start:0;  //=0为新数字，从头开始
            int len = res.size();
            for(int j = start; j < len; j++)
            {
                auto tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
            start = len;  //重复数字,从上一轮新添加的部分开始
        }
        return res;
    }
};

```
### 方法2
回溯，碰到重复数字不进入递归

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        helper(nums, temp, 0);
        return res;
    }
    void helper(vector<int>& nums, vector<int>& temp,int start){
        res.push_back(temp);
        for(int i=start;i<nums.size();i++){
            if(i>start&&nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            helper(nums, temp, i+1);
            temp.pop_back();
        }
    }
};
```
