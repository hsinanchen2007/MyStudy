**题解：**
本题与[39.组合总和](https://blog.csdn.net/qq_43152052/article/details/102957365)的区别：**在于candidates 中的数字可以是否可以重复多次**。因此在递归的时候`index`为`i+1`，而不是上一题的`index`为` i `。

**剪枝：**
由于连续重复数字在生成一个组合数组的时候，会出现重复的组合数组，所以再次遇到连续重复数字的时候我们直接跳过即可。

**代码如下：**
```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.empty())return {};
        sort(candidates.begin(),candidates.end());
        vector<int> track;
        vector<vector<int>> result;
        backtrack(candidates,track,result,0,target);
        return result;
    }
    
    void backtrack(vector<int>& candidates,vector<int> track,vector<vector<int>>& result,int index,int target)
    {
        if(target==0)
            result.push_back(track);
        else{
            for(int i=index;i<candidates.size();++i)
            {
                /*剪枝：连续相同数字会造成重复的组合数组*/
                if(i>index&&candidates[i]==candidates[i-1])continue;
                
                if(target-candidates[i]>=0)
                {
                    track.push_back(candidates[i]);
                    backtrack(candidates,track,result,i+1,target-candidates[i]);
                    track.pop_back();
                }
            }
        }
    }
};
```
