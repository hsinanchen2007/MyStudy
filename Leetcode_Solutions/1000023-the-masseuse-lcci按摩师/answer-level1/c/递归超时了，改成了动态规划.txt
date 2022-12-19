```
/*1、递归求解最大值，超时。估计需要动态规划了。*/
/*#define MAX_NUM(a,b)  ((a) > (b) ? (a) : (b))
int getMax(int* nums, int numsSize, int index)
{
    if (index > numsSize - 1) {
        return 0;
    }else if (index == numsSize - 1){
        return nums[index];
    }
    int num1 = nums[index] + getMax(nums, numsSize, index + 2);
    int num2 = nums[index + 1] + getMax(nums, numsSize, index + 3);
    return MAX_NUM(num1, num2);

}
int massage(int* nums, int numsSize){
    if (nums == NULL || numsSize <= 0) {
        return 0;
    }
    return getMax(nums, numsSize, 0);
}*/
/*2、动态规划*/
#define MAX_NUM(a,b)  ((a) > (b) ? (a) : (b))
int massage(int* nums, int numsSize)
{
    if (nums == NULL || numsSize <= 0) {
        return 0;
    }
    int last1 = nums[0];
    int last2 = 0;
    int tmp = 0;
    for (int i = 1; i < numsSize; i++){
        tmp = MAX_NUM(last1, last2 + nums[i]);
        last2 = last1;
        last1 = tmp;
    }
    return MAX_NUM(last1, last2);
}
```
