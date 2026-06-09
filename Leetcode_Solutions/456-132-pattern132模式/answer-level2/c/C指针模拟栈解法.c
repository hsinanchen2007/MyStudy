### 解题思路
解法一比较暴力
解法二使用指针模拟栈的pop和push，详见代码注释

### 代码

```c
bool find132pattern(int* nums, int numsSize){
    if (numsSize < 3) return false;
/*  暴力解法
    int min = nums[0];
    for (int i = 1; i < numsSize - 1; i++) {
        if (min > nums[i]) {
            min = nums[i];
            continue;
        }
        int max = nums[i];
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] < max && nums[j] > min)
                return true;
        }
    }
    return false;
*/
//C指针模拟栈解法
    //创建一个辅助最小值数组
    int *min = (int*)malloc(sizeof(int) * numsSize);
    int i;
    min[0] = nums[0];
    for (i = 1; i < numsSize; i++) {
        min[i] = (min[i - 1] > nums[i] ? nums[i] : min[i - 1]);
    }
    //mid数组模拟栈，存储aj可能值
    int *mid = (int*)malloc(sizeof(int) * (numsSize + 1));
    *mid = 15000; //mid[0]存一个不可能的值，模拟栈空
    int *tmp = mid; //tmp指针存malloc初始位置，方便释放
    for (i = numsSize - 1; i > 0; i--) {
        if (nums[i] > min[i]) {
            while(*mid != 15000 && *mid <= min[i])
                --mid;
            if (*mid != 15000 && *mid < nums[i])
                return true;
            *(++mid) = nums[i];
        }
    }
    free(min);
    mid = tmp;
    free(mid);
    return false;
}
```