### 解题思路
执行用时 :8 ms, 在所有 C++ 提交中击败了84.91%的用户
内存消耗 :8.3 MB, 在所有 C++ 提交中击败了100.00%的用户

实在懒，做完上一题想直接搬过来用，所以在上一题基础上小改一下即可。也就是重复数字的判定，加一个visited数组标记一下是否访问过就行了，其他代码和上一题一模一样
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> result;
    vector<int>tmp;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> visited(nums.size(), 0);//0为未访问过，1为访问过
        backtrack(nums,visited);
        return result;
    }

    void backtrack(vector<int>& nums,vector<int> &visited)
    {
        if(tmp.size()==nums.size()) result.push_back(tmp);
        for(int i=0;i<nums.size();i++)
        {
            if(visited[i]) continue;
            if(i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) continue;
            tmp.push_back(nums[i]);
            visited[i] = 1;
            backtrack(nums,visited);
            tmp.pop_back();
            visited[i] = 0;
        }
    }
};


            


```