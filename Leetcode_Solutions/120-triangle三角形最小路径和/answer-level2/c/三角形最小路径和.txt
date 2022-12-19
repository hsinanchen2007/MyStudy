### 解题思路
题目要求只使用O(n)的额外空间，那么我们的dp数组就设为dp[triangleSize]。
接从三角形的倒数第二行开始，以题目给的数据为例子说明：
dp数组首先初始化为：[4,1,8,3]
然后从倒数第二行开始，每个数都只能与它下方的和右下的相加，我们选取这两个和中较小的那个，这样dp数组就变为[7,6,10,3]。继续这样操作，dp变为[9,10,10,3]，最后dp变为[11,10,10,3]，这样dp[0]就是我们要求的结果。

### 代码

```c
int min(int x,int y){
    return (x < y) ? x : y;
}


int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){

    int dp[triangleSize];
    int i,j;

    for(i = 0;i < triangleSize;i++){
        dp[i] = triangle[triangleSize-1][i];
    }


    for(i = triangleSize-2;i >= 0;i--){
        for(j = 0;j <= i;j++){
            dp[j] = min(triangle[i][j] + dp[j],triangle[i][j] + dp[j+1]);
        }
    }

    return dp[0];

}
```