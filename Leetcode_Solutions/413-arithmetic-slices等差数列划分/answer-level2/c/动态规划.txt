### 运行情况
![image.png](https://pic.leetcode-cn.com/dcce6bd4b7613960b70582e9ffdbe8f6191d2725292a6a5d8db42c1bcee51207-image.png)

### 解题思路 ：动态规划三部曲
* 确定状态：定义dp[i]数组，表示以A[i]结尾的等差数列的个数
* 转移方程：如果(A[i]-A[i-1])==(A[i-1]-A[i-2]) 则 dp[i] = 1 + dp[i-1]；**否则dp[i]=0;**
>这里不好思考的地方就是 为什么在(A[i]-A[i-1])==(A[i-1]-A[i-2])时，dp[i] = 1 + dp[i-1]；
>因为，如果A[i]满足等差数列的条件，那么以A[i]结尾的等差数列的最大长度就比以A[i-1]结尾的最大长度要多1位；从而以A[i]结尾的子等差序>列的**头指针位置**就比以A[i-1]结尾的子等差序列的**头指针位置**的**选择多一位**，这样也就dp[i] = 1 + dp[i-1]；
* 边界值的确定：dp[0]=0; dp[1]=0;

### 代码

```c
int numberOfArithmeticSlices(int* A, int ASize){
    if(A==NULL||ASize<=2)
       return 0;
    int dp[ASize];
    dp[0]=0;
    dp[1]=0;
    int sum = 0;
    for (int i = 2; i < ASize; i++) 
    {
            if ((A[i]-A[i-1])==(A[i-1]-A[i-2])) 
            {
                dp[i] = 1 + dp[i-1];
                sum += dp[i];
            }
            else
               dp[i]=0;
    }
        return sum;
}

```