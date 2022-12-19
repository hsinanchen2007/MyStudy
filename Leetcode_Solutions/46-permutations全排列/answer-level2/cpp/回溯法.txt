### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void permute(vector<vector<int>> &result,vector<int> &tempRes,vector<int> &nums,vector<bool> &flag,int n)
    {
        //result为全局变量
        //tempRes为全局变量
        //flag为标记变量
        //n为nums的大小
        if(tempRes.size()==n)
        {
            result.push_back(tempRes);
        }
        else
        {
            for(int i=0;i<n;++i)
            {
                if(flag[i]==false)
                {
                    //第i个下标的数未选
                    tempRes.push_back(nums[i]);
                    flag[i] = true;  //标记已选
                    permute(result,tempRes,nums,flag,n);
                    tempRes.pop_back();  //撤回上一个数
                    flag[i] = false;
                }
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()==0)return {};
        vector<vector<int>> result;
        vector<int> tempRes;
        int n = nums.size();
        vector<bool> flag(n,false);
        permute(result,tempRes,nums,flag,n);
        return result;
    }
};
```