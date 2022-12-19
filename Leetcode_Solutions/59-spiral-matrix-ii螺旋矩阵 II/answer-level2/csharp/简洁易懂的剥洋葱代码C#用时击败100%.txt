参考评论区的大佬https://leetcode-cn.com/problems/spiral-matrix-ii/solution/yang-cong-bian-li-tian-chong-fa-by-mei-de-gan-qing/

优化后的代码如下，主体代码会短一些，总代码偏长是因为前面是C#的交错数组的初始化多的代码。
```
逐个填充，像剥洋葱一样，一圈一圈地去遍历(填充)矩阵
比如第一圈以（0,0）为起点，以（1,0）为终点，逐圈遍历
(0,0)-------------------->(0,n)
(1,0) (1,1)------->(1,n-1)  |
  ↑  (2,1)-->......  |     | 
  |      ↑           |     | 
  |      |            ↓    |
  |   (n-1,1)<---(n-1,n-1)  ↓
(n,0)<-------------------(n,n)
```
```
public class Solution 
{
    public int[][] GenerateMatrix(int n) 
    {
        int num = 1;
        int[][] result = new int[n][];
        
        //初始化数组
        for(int i = 0; i < n; i++)
            result[i] = new int[n];
        
        //所有的圈总是中心对称的，start表示这一圈的左上角的横纵坐标（横坐标始终等于纵坐标），end表示这一圈的右下角的横纵坐标
        for(int start = 0, end = n - 1; num <= n * n; start++, end--)
        {//从(0,0)到(0,n)，从(1,n)到(n,n),从(n,n-1)到(n,0)，最后从(n-1,0)到(1,0)
            for(int col = start; col <= end; col++) result[start][col] = num++;
            for(int row = start + 1; row <= end; row++) result[row][end] = num++;
            for(int col = end - 1; col >= start; col--) result[end][col] = num++;
            for(int row = end - 1; row > start; row--) result[row][start] = num++;
        }
        
        return result;
    }
}
```

![Snipaste_2019-09-30_10-28-03.png](https://pic.leetcode-cn.com/65dca967409512e3fed873ee01a443c30604fe84ed5a920f3645c1c8ff102ceb-Snipaste_2019-09-30_10-28-03.png)
