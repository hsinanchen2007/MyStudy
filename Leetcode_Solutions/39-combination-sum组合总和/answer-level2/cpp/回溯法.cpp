### 解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>result;
        vector<int>temp;
        tarckback(candidates,target,0,0,result,temp);
        return result;
    }
    void tarckback(vector<int>&candidates,int target,int start,int sum, 
    vector<vector<int>>&result,vector<int>&temp)
    {
        if(sum==target) //得到结果，将其记录
        {
            result.push_back(temp);
            return;
        }
        if(start==candidates.size()||sum+candidates[start]>target)
        //剪枝函数，如果此时位置和数组大小一样（数组越界），或者当前结果加上当前数大与目标数，没有符合要求的结果，退回
            return;
        temp.push_back(candidates[start]);//选当前的数
        tarckback(candidates,target,start,sum+candidates[start],result,temp);
        temp.pop_back();//不选当前的数，因为题目说了是无重复的数组，所以不需要循环去处理重复元素
        tarckback(candidates,target,start+1,sum,result,temp);
    }
};
```