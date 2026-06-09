### 解题思路  
![SharedScreenshot.jpg](https://pic.leetcode-cn.com/d38bc1c056c4c1b01f8e57c1059b54d0e0a860cc860c31810350d90fa8bd682e-SharedScreenshot.jpg)
思路非常清楚，就是手跟不上脑袋，写出来总不对。。。

flag数组用于标记格子是否被机器人抵达了。
sum_i为横坐标的数位和，一般上下相邻的两个格子，下面的sum_i比上面多1，但是如果遇到下面的横坐标是整10的时候，sum_i需要重新计算。
sum_j为纵坐标的数位和，计算同上。

两重for循环，遍历整个地图的格子，对于任意的一个格子，它会被机器人抵达的条件是：
1. 左边的格子或上面的格子被抵达了  
2. 横坐标和纵坐标的数位和小于k  

结束的条件是某一行（比如第i行）的所有格子，机器人都不能抵达。


### 代码

```c
int movingCount(int m, int n, int k){
    int i, j, sum_i=0, sum_j=0, res=0, res_old=0;
    int flag[m][n];
    for(i=0; i<m; i++){
        // 计算横坐标的和
        if(i%10 == 0){
            sum_i = i/10;
        }else{
            sum_i++;
        }
        for(j=0; j<n; j++){
            // 计算纵坐标的和
            if(j%10 == 0){
                sum_j = j/10;
            }else{
                sum_j++;
            }
            // 判断本格子的左边和上面格子是否被访问过, 并且本格子满足条件
            if((j==0 || j>0 && flag[i][j-1]==1 || i>0 && flag[i-1][j]==1) && sum_i+sum_j <= k){
                flag[i][j] = 1;
                res++;
            }else{
                flag[i][j] = 0;
            }
        }
        // 如果第i行没有满足条件的格子，则结束
        if(res != res_old){
            res_old = res;
        }else{
            break;
        }
    }
    return res;
}
```