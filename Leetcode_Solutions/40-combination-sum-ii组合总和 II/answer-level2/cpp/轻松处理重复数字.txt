### 解题思路
此处撰写解题思路
核心要点，排序，把重复数据堆一块
其次如果重复数字从某个位置不被选择，那么从哪之后这个重复数字就不再被选择了，避免重复的结果
### 代码

```cpp
class Solution {
public:
    void lookup(vector<int>& candidates,int nSize, int nStartIndex,int ntarget,int nLastNoCheck,vector<int>& vMiddle,vector<vector<int>>& vresult )
    {
        if(ntarget==0)
        {
            vresult.push_back(vMiddle);
            return;
        }
        if(nStartIndex>=nSize)
        {
            return ;
        }
        //没有负数和0 不然无解
        if(candidates[nStartIndex]>ntarget)
        {
            return;
        }
        //在这里他有选和不选2种选择
        if(nLastNoCheck!=candidates[nStartIndex])
        {
            //重复的数字要保持连续选，不然会引起组合
            //选
            //不进这个分支，就表示曾经有跟当前重复的数没选，后面这个重复的数字都不选了
            vMiddle.push_back(candidates[nStartIndex]);
            lookup(candidates,nSize,nStartIndex+1,ntarget-candidates[nStartIndex],nLastNoCheck,vMiddle,vresult);
            vMiddle.pop_back();
        }
        {
            //不选
            lookup(candidates,nSize,nStartIndex+1,ntarget,candidates[nStartIndex],vMiddle,vresult);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> vresult;
        vector<int> vMiddle;
        int nSize=candidates.size();
        if(nSize<=0)
        {
            return {};
        }
        sort(candidates.begin(),candidates.end());//排序
        lookup(candidates,nSize,0,target,-1,vMiddle,vresult);
        return vresult;
    }
};
```