### 解题思路
- 我是先把这个矩阵变成0/1矩阵
- 再深度遍历就好了
- ——————————！！
- 做得比较慢，有以下几个错误，记录一下：
1. dfs的时候当前位置的值忘了改成0
2. 在进行当前坐标的各位数相加的时候不能用i，j直接来加，i和j的值变化了会死循环
3. while的条件不能写(x%10)当x等于10的时候会等于0，直接跳过，少加了前面的数，要用(x!=0)来当条件
![image.png](https://pic.leetcode-cn.com/8aa341ecd14104ca2138e4580a21c52c83bf72e8f91097a51b965e1cbc856227-image.png)


### 代码

```cpp
class Solution {
    private:
    int dfs(vector<vector<int>>& mat,int m,int n,int cur_i,int cur_j)
    {
        int res=0;
        if(cur_i<0||cur_j<0||cur_i==m||cur_j==n||mat[cur_i][cur_j]==0) return 0;
        mat[cur_i][cur_j]=0;
        res++;
        
        int di[4]={0,0,1,-1};
        int dj[4]={1,-1,0,0};
        for(int i=0;i<4;i++)
        {
            res+=dfs(mat,m,n,cur_i+di[i],cur_j+dj[i]);
        }
        return res;
    }
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int>> mat(m,vector<int>(n,0));
        vector<vector<int>> map=mat;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int count=0;
                int x=i,y=j;
                while(x!=0)
                {
                    count+=x%10;
                    x/=10;
                }
               
                while(y!=0)
                {
                    
                    count+=y%10;
                    
                    y/=10;
                    
                }
                
                map[i][j]=count;
                if(map[i][j]<=k) mat[i][j]=1;
                
            }
        }
        
        //return mat[10][9];
         int ans=dfs(mat,m,n,0,0);
         return ans;
        
        
    }

};
```