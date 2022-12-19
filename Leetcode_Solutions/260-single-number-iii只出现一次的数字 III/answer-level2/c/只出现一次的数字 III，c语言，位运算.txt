### 解题思路
我们不妨假设出现一个的两个元素是x，y，那么最终所有的元素异或的结果就是res = x^y。并且res！=0，那么我们可以找出res二进制表示中的某一位是1，那么这一位1对于这两个数x,y只有一个数的该位置是1。对于原来的数组，我们可以根据这个位置是不是1就可以将数组分成两个部分。求出x,y其中一个，我们就能求出两个了。

原文链接：https://blog.csdn.net/deaidai/article/details/78167367
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize){
    int* result = (int*)malloc(sizeof(int)*2);
    *returnSize = 2;
    int temp1=0,temp2=0,count=0;
    for(int i=0;i<numsSize;i++){
        temp1 = temp1^nums[i]; 
    }
    temp2 = temp1;
    while((temp2&1)==0){
        count++;
        temp2 = temp2>>1;
    }
    temp2 = 0;
    for(int i=0;i<numsSize;i++){
        if((nums[i]>>count)&1 == 1){
            temp2 = temp2^nums[i];
        }
    }
    result[0] = temp2;
    result[1] = temp1^temp2;
    return result;
}
```