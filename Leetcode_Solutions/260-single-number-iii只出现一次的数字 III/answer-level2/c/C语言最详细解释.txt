/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize){
    /**
        有两个数只出现了一次记为 num1、num2 初始化为 0, 其余的数出现了两次, 
        我们可以对所有的数进行一次异或操作, 易知这个结果就等于 num1 和 num2 
        的异或结果(相同的数异或结果都为 0, 0和任意数异或结果都为那个数). 

        那么我们可以考虑异或结果的某个非 0 位，如最后一个非 0 位, 因为我们知道只
        有当 num1、num2 在该位不一样的时候才会出现异或结果为 1。所以我们以该
        位是否为 1 对数组进行划分, 只要该位为 1 就和 num1 异或, 只要该位为 0
        就和 num2 异或, 这样最终得到就是只出现过一次的两个数 (其他在该位为 1 或
        0 的数必然出现 2 次，相同数异或的结果是0，对异或结果无影响)

        那么我们可以考虑异或结果的某个非 0 位，如最后一个非 0 位, 因为我们知道只
        有当 num1、num2 在该位不一样的时候才会出现异或结果为 1。
        比如a的二进制是 ??????10000，取反就是??????01111，加1就是??????10000。
        前面?的部分是和原来a相反的，相与必然都是0，所以最后整体相与的结果就是00000010000。
    **/

    int num = 0; 
    for(int i = 0; i < numsSize; i++) {
        num ^= nums[i];
    }
    
    // 异或结果就是两个出现一次数的异或结果

    num = num & (~num + 1);

    int *res = (int *)malloc(sizeof(int)*2);
    res[0] = res[1] = 0;
    
    for(int i = 0; i < numsSize; i++) {
        if(num & nums[i]) {
            res[0] ^= nums[i];
        } else {
            res[1] ^= nums[i];
        }
    }

    *returnSize = 2;

    return res;
}