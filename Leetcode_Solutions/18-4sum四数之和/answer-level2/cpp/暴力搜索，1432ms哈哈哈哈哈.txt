### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()==0)
            return ans;
        if(nums.size()<4)//如果数组不够4个，直接返回空容器ans
            return ans;
        for(int i=0;i<nums.size()-3;i++)
        {
            for(int j=i+1;j<nums.size()-2;j++)
            {
                for(int k=j+1;k<nums.size()-1;k++)
                {
                    for(int z=k+1;z<nums.size();z++)
                    {
                        if(nums[i]+nums[j]+nums[k]+nums[z]==target)
                        {
                            vector<int> res;
                            res.push_back(nums[i]);
                            res.push_back(nums[j]);
                            res.push_back(nums[k]);
                            res.push_back(nums[z]);
                            sort(res.begin(),res.end());//这一部分是去重，先排序，排好序，就可以比较是否相同了
                            if(ans.size()==0)
                                ans.push_back(res);
                            else{
                                ans.push_back(res);//不管三七二十一，先压入容器
                                for(int a=0;a<ans.size()-1;a++)
                                {
                                    if(ans[a]==res)
                                        ans.pop_back();//如果遍历和之前的相同，就弹出容器
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return ans;

    }
};
```
//这效率是真的慢，希望大家不要学我，引以为戒