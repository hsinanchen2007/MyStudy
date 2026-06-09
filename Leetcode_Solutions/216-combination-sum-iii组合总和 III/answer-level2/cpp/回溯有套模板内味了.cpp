### 解题思路
跟前两个还是差不多，照着模板写一遍就行了

### 代码

```cpp
class Solution {
public:
vector<vector<int>> answer;
vector<int> v;
int last=1;
void dfs(int k,int n)
{
    if(n==0&&k==0) 
    {
        answer.push_back(v);
        return;
    }
    if(k==0||n==0) return;
    int last0=last;
    for(int i=last;i<10;i++)
    {
        if(n-i<0) return;
        last=i+1;
        v.push_back(i);
        dfs(k-1,n-i);
        v.pop_back();
        last=last0;
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k,n);
        return answer;
    }
};
```