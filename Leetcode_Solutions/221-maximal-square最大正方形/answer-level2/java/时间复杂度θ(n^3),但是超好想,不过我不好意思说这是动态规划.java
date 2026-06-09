### 解题思路
![QQ截图20200327172404.png](https://pic.leetcode-cn.com/a3a77074be0aab66f74a4b64fa3b0ee5afe167ded92596c24434282a5de024e5-QQ%E6%88%AA%E5%9B%BE20200327172404.png)

不知道算不算动态规划，鉴于暴力好像是O(n^4)，就打上DP的tag了

说一下我的做法：

对每一个边长为x的正方形，假设它的起始坐标（即左上角那个点的坐标）为[i][j],定义它的状态temp_x[i][j]等于'0':该正方形里含'0';等于'1':该正方形只由'1'组成

边长为x的正方形的状态由位于它体内的四个边长为(x-1)的小正方形的状态决定，只有当这四个边长为(x-1)的小正方形均=='1'时，边长为x的正方形状态才=='1',假设边长为x的正方形的起始坐标为[i][j]，那么四个边长为(x-1)的小正方形的起始坐标分别为[i][j]，[i][j+1]，[i+1][j]，[i+1][j+1]。
如图：
![120f5fc93d20c5bc5bea301622512fd2c482ccb1228da4afb0dcad4538f21281-image.png](https://pic.leetcode-cn.com/6132ce462bc81bf63f12a5ae1f6af3b73843bed1d00bb54b25c3c85a4c35da31-120f5fc93d20c5bc5bea301622512fd2c482ccb1228da4afb0dcad4538f21281-image.png)

比如对于左上的四个元素组成的边长为2的正方形，把这四个元素分别看成四个边长为1的小正方形组成即可，当这四个的状态都为‘1’时，该边长为2的正方形状态为‘1’，当边长x>=3时，实际上组成它的四个边长（x-1）的小正方形有大范围重叠，但是我没有优化出这些重叠部分的判断。因此最外层的x循环寻找可能的最大边长，里面的i,j循环记录当正方形边长为x时,当前正方形temp_x[i][j]的状态。
因为当计算边长为x的正方形的状态时，只会用到边长为x-1的正方形的状态，更小的就用不到了，因此可把原始矩阵matrix充分利用，matrix相当于x=1时的状态，x>=2时，每一次计算完的temp_x存入matrix的对应坐标的元素，以供下次循环使用

每当出现一次正方形的状态为‘1’的情况，用其边长x更新最大值
### 代码

```java
class Solution {
    public int maximalSquare(char[][] matrix) {
        if(matrix.length==0) return 0;
        if(matrix[0].length==0) return 0;
        int m=matrix.length;//行数
        int n=matrix[0].length;//列数
        int max_side_len=0;//初始化最大可能的边长

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1')   max_side_len=1;//初始化最大可能的边长
            }
        }

        if(max_side_len==0) return 0;
        if(m==1||n==1) return max_side_len;
        
        
        for(int x=2;x<=Math.min(m,n);x++){//边长
            char temp_x[][]=new char[m-x+1][n-x+1];//temp_x[i][j]存放左上起始坐标为i,j,边长为x的那个正方形的状态，它的状态由其四部分决定
            for(int i=0;i<temp_x.length;i++){
                for(int j=0;j<temp_x[0].length;j++){
                    if(matrix[i][j]=='1'&matrix[i][j+1]=='1'&&matrix[i+1][j]=='1'&&matrix[i+1][j+1]=='1') {
                        temp_x[i][j]='1';
                        if(x>max_side_len) max_side_len=x;
                    }
                    else {temp_x[i][j]='0';}
                }
            }
            for(int i=0;i<temp_x.length;i++) {
                for (int j = 0; j < temp_x[0].length; j++) {
                    matrix[i][j]=temp_x[i][j];
                }
            }
            

        }
        return max_side_len*max_side_len;

    }
}
```