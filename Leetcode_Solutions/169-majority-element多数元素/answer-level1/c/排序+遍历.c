### 解题思路
1.排序；
2.累计相邻的相同元素个数，保留最大的；

### 代码

```c
int cmp(void *a, void *b)
{
    return *((int *)a) - *((int *)b);
}
int majorityElement(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);

    int maxTime = 1;
    int maxNum = nums[0];
    int pre = nums[0];
    int time = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == pre) {
            time++;
        } else {
            if(time > maxTime) {
                maxTime = time;
                maxNum = pre;
            }
            pre = nums[i];
            time = 1;
        }
    }

    if((pre != maxNum) && (maxTime < time)) {
        maxNum = pre;
    }

    return maxNum;

}
```