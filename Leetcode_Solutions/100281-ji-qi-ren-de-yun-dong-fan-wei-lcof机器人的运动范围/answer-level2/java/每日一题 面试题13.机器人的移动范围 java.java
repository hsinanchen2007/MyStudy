### 解题思路
思路1、先考虑穷举，然后再考虑如何改进
  对每个坐标都遍历一次，通过二维数组记录，判断当前坐标的左侧和下侧相邻的坐标点是否是可达的，随后再判断当前坐标是否符合小于k的规则
  比如 m=3, n=2, k=1
  首先初始化二维数组int[m][n]=[[0,0],[0,0],[0,0]];赋值arr[0][0]=1;
  坐标形式表示为：（红圈表时可达）
![image.png](https://pic.leetcode-cn.com/93b6bd9eec543a250f7d1375656fc3b0476ce2e05e1534005ff1df78f2d92ff2-image.png)
  示例在（0，1）时的判断，坐标左侧left=arr[0][0],下侧down=0，再判断0+1<=1,所以可达，赋值arr[0][1]=1,也用红圈标记
![image.png](https://pic.leetcode-cn.com/3978fa7f6ba792524b5b2a8a962f8e81f67d7baf3feb6906e60f7e32289e5c66-image.png)
  最终的坐标图：
![image.png](https://pic.leetcode-cn.com/9d42e9226c27d80150d1180535ef66083d1906475d84074e66e513f266748ea4-image.png)




### 代码

```java
class Solution {
    public int movingCount(int m, int n, int k) {
        //穷举
        int count = 1;
        int m0,m1,n0,n1;
        int arr[][] = new int[m][n];
        arr[0][0] = 1;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int left = i>0 ? arr[i-1][j] : 0;
                int down = j>0 ? arr[i][j-1] : 0;
                if (left == 1 || down == 1) {
                    m0 = i%10;
                    m1 = i/10;
                    n0 = j%10;
                    n1 = j/10;
                    if ( m0+m1+n0+n1 <= k ) {
                        arr[i][j] = 1;
                        count++;
                    }
                }
                
            }
        }
        return count;
    }
}
```