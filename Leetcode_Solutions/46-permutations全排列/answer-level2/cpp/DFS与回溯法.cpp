### 解题思路
回溯法就是从头到尾，每次递归：在循环中对当前点与右边剩下的点进行所有可能的交换来完成选择、组合，完成一种组合后，定住（存储）该点以及之前的结果，往下递归（组合剩下的点），在本次循环中撤销之前的交换以便进入下次循环交换另一个点。

### 代码

```cpp
//DFS
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>temp;
        for(int i = 0 ; i < nums.size() ; i++){
            generate(res,nums,nums[i],temp,nums.size());
        }
        return res;
    }
    void generate(vector<vector<int>> &res,vector<int> option,int add,vector<int>temp,int len){
        temp.push_back(add);
        if (temp.size() == len) {
            res.push_back(temp);
            return;
        }
        option.erase(find(option.begin(), option.end(), add));
        for(int i = 0 ; i < option.size() ; i++){
            generate(res,option,option[i],temp,len);
        } 
    }
};
//回溯法
class Solution {
public:
    void backtrack(int n, vector<int> &nums, vector<vector<int>> &res, int first)
    {
        if(first == n)  res.push_back(nums);
        for(int i = first; i < n; i++)
        {
            swap(nums[first], nums[i]);
            backtrack(n, nums, res,  first+1);
            swap(nums[first], nums[i]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums.size(), nums, res, 0);
        return res;
    }
};
```