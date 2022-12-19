### 解题思路
本人懒，做完上一道子集后，把代码直接copy过来，仔细分析，遂加一访问数组即可，其余和上道题一模一样
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :7.3 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    vector<vector<int>>res;
    vector<int>tmp;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> visited(nums.size(), 0);//0为未访问过，1为访问过
        bk(nums,0,visited);
        return res;
    }

    void bk(vector<int>& nums,int s,vector<int>& visited)
    {
        res.push_back(tmp);
        for(int i=s;i<nums.size();i++)
        {
            if(visited[i]) continue;
            if(i>0&&nums[i]==nums[i-1]&&visited[i-1]==0)continue;
            tmp.push_back(nums[i]);
            visited[i]=1;
            bk(nums,i+1,visited);
            tmp.pop_back();
            visited[i]=0;
        }
    }
};
```