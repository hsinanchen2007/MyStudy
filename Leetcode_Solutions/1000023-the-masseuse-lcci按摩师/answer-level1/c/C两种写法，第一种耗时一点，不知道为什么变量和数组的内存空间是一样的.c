执行用时 :4 ms, 在所有 C 提交中击败了48.51%的用户
内存消耗 :5.6 MB, 在所有 C 提交中击败100.00%的用户
#define MAXNUM(a, b) (a) > (b) ? (a) : (b)
int massage(int* nums, int numsSize)
{
    int i;
    int a,b,c;
    if (numsSize == 0) {
        return 0;
    }
    a = 0;
    b = nums[0];
    c = b;
    for (i = 2; i < (numsSize + 1); i++) {
        c = MAXNUM(a + nums[i - 1], b);
        a = b;
        b = c;
    }    
    return c;
}

执行用时：0 ms
内存消耗：5.6 MB
#define MAXNUM(a, b) (a) > (b) ? (a) : (b)
int massage(int* nums, int numsSize)
{
    int *dp = (int *)malloc(sizeof(int) * (numsSize + 1));
    int i;
    if (numsSize == 0) {
        return 0;
    }
    dp[0] = 0;
    dp[1] = nums[0];
    for (i = 2; i < (numsSize + 1); i++) {
        dp[i] = MAXNUM(dp[i - 2] + nums[i - 1], dp[i - 1]);
    }    
    return dp[numsSize];
}