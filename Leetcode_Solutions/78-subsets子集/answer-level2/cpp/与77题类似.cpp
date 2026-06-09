### 解题思路
与77题实际是类似的，还是通过一个索引记录避免使用备忘录。

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户。
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> temp;
        helper(nums, res, temp, n, 0);
        return res;
    }
    void helper(vector<int>& nums, vector<vector<int>>& res,vector<int>& temp, int n,int start){
        res.push_back(temp);
        for(int i=start;i<n;i++){
            temp.push_back(nums[i]);
            helper(nums,res, temp, n, i+1);
            temp.pop_back();
        }
        return;
    }
};

```