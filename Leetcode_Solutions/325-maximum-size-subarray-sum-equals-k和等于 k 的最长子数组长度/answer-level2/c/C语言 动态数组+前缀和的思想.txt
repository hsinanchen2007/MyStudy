用 https://leetcode-cn.com/problems/maximum-size-subarray-sum-equals-k/solution/on-prefix-sum-hash-by-mike-meng/的思想
我们知道如何最终结果为sum(i,j)为从i到j的子序列和，则sum(i,j) = sum(0,j) - sum(0,i-1);
2.按照第一条的规则，假设sum(i,j) = k,则 sum(0,j) = k + sum(0,i-1),因此我们利用hash查找是否存在前N项和的值为sum(0,n) - k,如果找到，则输出结果。
3.代码如下所示：

int max(int a, int b) 
{
    return (a > b) ? a : b;
}

int maxSubArrayLen(int* nums, int numsSize, int k){
    int i;
    int j;
    int sum = 0;
    int maxLen = 0;
    
    if ((nums == 0) || (numsSize == 0)) {
        return 0;
    }    
    int dpSum[numsSize + 1];
    memset(dpSum, 0, sizeof(int) * (numsSize + 1));
    
    for (i = 0; i < numsSize; i++) {
        sum += nums[i];
        dpSum[i+1] = sum;        
        for (j = i; j >= 0; j--) {
            if ((dpSum[i+1] - dpSum[j]) == k) {
                maxLen = max(maxLen, i - j +  1);                
            }
        }        
    } 

    return maxLen;
}
