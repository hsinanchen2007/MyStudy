### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int count=0;
    int movingCount(int m, int n, int k) {
        //深度优先搜索
        vector<bool> v(n,false);
        vector<vector<bool>> reached(m,v);
        
        dfs(0,0,m,n,k,reached);

        return count;
    }

    void dfs(int row, int col, int m, int n, int k, vector<vector<bool>>& reached)
    {
        if(bitSum(row)+bitSum(col)>k) return;
        else
        {
            count++;
            reached[row][col]=true;
        }

        if(row-1>=0 && !reached[row-1][col])
        {
            dfs(row-1,col,m,n,k,reached);
        }
        if(col+1<n && !reached[row][col+1])
        {
            dfs(row,col+1,m,n,k,reached);
        }
        if(row+1<m && !reached[row+1][col])
        {
            dfs(row+1,col,m,n,k,reached);
        }
        if(col-1>=0 && !reached[row][col-1])
        {
            dfs(row,col-1,m,n,k,reached);
        }

        return;
    }

    int bitSum(int val)
    {
        int res=0;
        while(val!=0)
        {
            res+=val%10;
            val=val/10;
        }
        return res;
    }
};
```