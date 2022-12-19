### 解题思路
套回溯的模板

求大佬告知标题的 原因

### 代码

```cpp
class Solution {
public:
vector<vector<int>> answer;
vector<int> v;
int last=0;
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    if(target==0)
    {
        answer.push_back(v);
    }
    else if(target<0) return answer;
    else
    {
       int last0=last;
        for(int i=last;i<candidates.size();i++)
        {
            last=i;
            v.push_back(candidates[i]);
             combinationSum(candidates,target-candidates[i]);
            v.pop_back();
            last=last0;
        }
    }
       return answer;
}
        
};
```