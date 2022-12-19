### 解题思路
标记有没有移动，没有移动直接返回false

### 代码

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) 
    {
        if(matrix.empty()||matrix[0].empty())
        return false;
int i=matrix.size(),j=matrix[0].size();int p=0,k=j-1;int index=0;
while(target!=matrix[p][k]&&k>=0&&p<i)
{
    index=false;
    if(target>matrix[p][k]&&p<i-1)
    {
    p++;index=true;
    }
    else if(target<matrix[p][k]&&k>0)
    {
    k--;index=true;
    }
    if(!index)
    return false;
}
return true;
    }
};
```