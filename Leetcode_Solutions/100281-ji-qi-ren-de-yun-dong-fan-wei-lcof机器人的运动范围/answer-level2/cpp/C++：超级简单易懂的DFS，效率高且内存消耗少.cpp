### 解题思路
将功能分成3个函数实现：
（1）数位和计算函数；
（2）深度优先搜索函数；
（3）主函数。
【注意】：因为从右上角开始搜索，所以搜索方向只需要向右和向下就可以。

![image.png](https://pic.leetcode-cn.com/3665a53e3d7fb5cb4e7f9c2ebf6d82176be60bb034bfbf9d761937a946073fe4-image.png)

### 代码

```cpp
class Solution 
{
public:
    int count=0;  //统计走过的格子数
    int num_sum(int x)  //数位和计算
    {
        int sum=0;
        while(x!=0)
        {
            sum+=x%10;
            x=x/10;
        }
        return sum;
    }
    void dfs(int x,int y,int m,int n,int k,vector<vector<int>> &map_set)  //深度优先搜索
    {
        int sum=num_sum(x)+num_sum(y);
        //下标不能等于m/n，否则下标会越界
        if (x<0 || y<0 || x>=m || y>=n || map_set[x][y]==1 ||sum>k)  
        {
            return;
        }
        count++;
        map_set[x][y]=1;
        dfs(x+1,y,m,n,k,map_set);  //向右搜索
        dfs(x,y+1,m,n,k,map_set);  //向下搜索
    }
    int movingCount(int m, int n, int k) 
    {
        vector<vector<int>>map_set(m,vector<int>(n,0));
        dfs(0,0,m,n,k,map_set);  //开始深度优先搜索
        return count;
    }
};
```