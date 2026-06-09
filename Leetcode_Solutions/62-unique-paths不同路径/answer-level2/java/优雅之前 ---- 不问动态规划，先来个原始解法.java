一上手是抽象的，但是自己画下图，大概捋一捋第二个例子得出结果的过程，
大概就是边上的就只用一种方法可达，其他的都是他想领两个框可达数目之和；
这个思路转化为代码就容易了
时间复杂度O(m*n),空间复杂度O(m*n);

```
   int[][] pathLength = new int[m][n];
        for(int i = 0; i<m;i++){
            for(int j = 0;j<n;j++){
                if(i==0||j==0){
                    pathLength[i][j] = 1;
                }else{
                    pathLength[i][j] = pathLength[i-1][j]+pathLength[i][j-1];
                }
            }
        }
   return pathLength[m-1][n-1];
```
