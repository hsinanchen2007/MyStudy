### 解题思路
无论是官方题解还是大佬们写的题解，对于整体思路都很清楚了，这里就不多赘述。这里只用了最简单的多次枚举的办法，没有进行优化。
我写这个题解是总结一下在过程中遇到的边界与转换坐标不清楚的问题。

1.首先是前缀和中第0行和第0列赋值为0。这里前缀和的定义是当前元素左侧和上侧全部元素之和，包括当前元素。那么如果不通过将前缀和矩阵多一行一列的方法，preSum[i][j]=preSum[i-1][j]+preSum[i][j-1]-preSum[i-1][j-1]+mat[i-1][j-1];这个递推式就无法在第一行列进行有效的计算，只能人工的判断是否越界，很麻烦。但是带来的副作用在于当前preSum矩阵与原mat矩阵中对应元素错位了，因此最后mat并不是加mat[i][j]元素,而要根据错位返回原矩阵对应元素坐标。

2.return preSum[x2][y2]-preSum[x1-1][y2]-preSum[x2][y1-1]+preSum[x1-1][y1-1];getSum函数中的这个语句，其中-1是对应了preSum矩阵的坐标，而非原矩阵mat中的坐标。因此在传入参数时，要传入成getSum(preSum,i+1,j+1,i+1+c,j+1+c)<=threshold，将枚举的原坐标转换为preSum矩阵中坐标。

3.每次枚举的矩形的变成增量要从0开始，但是增量为0则意味着边长最少为1。所以最后计算最大边长要为c+1。

边界问题在任何题目中都会出现，比较好的解决办法就是在纸上画一遍图，举个例子推导一下边界条件关系。但是这种方法挺慢的，也不聪明，如果有大佬知道其他好方法可以跟我说一下啊！再有就是通过多年编程，对于各种问题已经非常熟悉，此时在脑海里有问题的映像和模板，就直接写上去，但是对于非大佬很不友好，想不清楚......
### 代码

```cpp
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> preSum(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                preSum[i][j]=preSum[i-1][j]+preSum[i][j-1]-preSum[i-1][j-1]+mat[i-1][j-1];
            }
        }
        int r=min(m,n);
        int maxLen=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int c=0;c<r;c++){
                    if(i+c<m&&j+c<n&&getSum(preSum,i+1,j+1,i+1+c,j+1+c)<=threshold) maxLen=max(maxLen,c+1);
                }
            }
        }
        return maxLen;
    }

    int getSum(vector<vector<int>>& preSum,int x1,int y1,int x2,int y2){
        return preSum[x2][y2]-preSum[x1-1][y2]-preSum[x2][y1-1]+preSum[x1-1][y1-1];
    }
};
```