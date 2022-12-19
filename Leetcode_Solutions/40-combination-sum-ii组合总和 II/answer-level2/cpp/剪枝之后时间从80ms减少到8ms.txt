### 解题思路
完全复制上题的代码，在dfs函数中增加一段
if(remain==0)
    {
        for(int i=0;i<answer.size();i++)
        {
            if(answer[i]==v) return;
        }
        answer.push_back(v);
    }
防止重复的产生
for(int i=last;i<candidates.size();i++)
        {
            if(remain-candidates[i]<0) return;//剪枝代码
            last=i+1;//last=i,变为last=i+1，每个元素用一次
            v.push_back(candidates[i]);
            dfs(remain-candidates[i]); 
            v.pop_back();
            last=last0;
        }
### 代码

```cpp
class Solution {
public:
vector<vector<int>> answer;
vector<int> v;
vector<int> candidates;
int last=0;
void dfs(int remain)
{
    if(remain==0)
    {
        for(int i=0;i<answer.size();i++)
        {
            if(answer[i]==v) return;
        }
        answer.push_back(v);
    }
    else if(remain<0) return;
    else
    {
       int last0=last;
        for(int i=last;i<candidates.size();i++)
        {
            if(remain-candidates[i]<0) return;//剪枝代码
            last=i+1;
            v.push_back(candidates[i]);
            dfs(remain-candidates[i]); 
            v.pop_back();
            last=last0;
        }
    }
}
vector<vector<int>> combinationSum2(vector<int>& _candidates, int target) {
       candidates=_candidates;
       sort(candidates.begin(),candidates.end());//排序，方便剪枝
       dfs(target);
       return answer;
}
        
};
```