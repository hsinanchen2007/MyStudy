两步
【1】不跨边界，计算个最大值。此时的结果，比较了所有元素相加的结果
【2】跨边界计算，不用再次比较所有元素相加的结果。
（1）对于每个位置i，都要计算包括第一个0位置的数的时候的最大值。
    这个最大值，要么是：从0位置一直加到当前位置i的值。
    要么是：前一个位置计算出来的最大值
（2）每个位置到第0个元素的最大值（1）已经计算出来了。  
最后的结果要遍历刚刚计算出来的这个结果 + 最后面开始算的sum

至于这个从后面直接倒着算的sum为什么不需要再找最大值，只需要直接加起来就能得到结果。  如果也计算，中间的一部分数就被过滤重复了。

!!问题的关键是，跨边界的时候要遍历，真的不知道在哪里才是最大值。如果直接两层嵌套遍历，会超时，所以要利于之前计算的dp结果。不不重复计算




```
#define MAX(A, B) ((A) > (B) ? (A) : (B))


int maxSubarraySumCircular(int* A, int ASize){
    int i;
    int j = 0;
    int minCnt = 0;
    int sum = 0;
    int dp[ASize];
    int result = A[0];


    // 不循环的最大值 
        dp[0] = A[0];
        for (i = 1; i < ASize; i++) {
            dp[i] = MAX(dp[i - 1] + A[i], A[i]);
            result = MAX(dp[i], result);
//            printf("result = %d \n", result);
        }

        if (i != 1) {
            dp[0] = A[0];
            sum = A[0];
            for (i = 1; i < ASize; i++) {
                sum += A[i];
                dp[i] = MAX(sum, dp[i - 1]); //因为要包含0！！！所以每个的计算都要取i - 1相关的。关键是要连续的！！
//                printf("dp[%d] = %d, dp[%d] = %d\n", i - 1, dp[i - 1], i, dp[i]);
            }

            sum = 0;
            /* result 上面不跨边界已经有一个结果了，正好拿来一起比较计算 */
            for (j = ASize - 1; j > 0; j--) { //上面已经都dp过一次了。直接利用上面结果求和。要倒着加，因为dp是正的
                sum += A[j];
                result = MAX(result, dp[j - 1] + sum);
//                printf("===dp[%d] = %d, sum = %d\n", j - 1, dp[j - 1], sum);
            }
            /* 全部加起来的时候。不需要比较一下了！！！因为上面不跨边界已经覆盖了 */
//            sum += A[0];
//            result = MAX(result, sum);
        }

            
    return result;
}
```
