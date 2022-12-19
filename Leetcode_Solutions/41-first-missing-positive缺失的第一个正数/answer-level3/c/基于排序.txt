```
#if 0 //方法1
#define INT_MAX 2^31
//有符号整形变量的范围是INT_MAX - 1 (-2147483648    2147483647)
int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int firstMissingPositive(int* nums, int numsSize){

    if (numsSize == 0) {
        return 1;
    }

    int cnt = 0; //记录大于0的整数个数
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            nums[cnt++] = nums[i];
        }
    }

    if (cnt == 0) {
        return 1;
    }

    qsort(nums, cnt, sizeof(int), cmp);
    int idx = 0;
    for (int i = 0; i < cnt; i++) {
        if (nums[i] > 0) {
            nums[idx++] = nums[i];
        }
    }

    if (nums[0] > 1) {
        return 1;
    }

    if (cnt == 1) {
        return (nums[0] == 1) ? 2 : (nums[0] + 1);  
    }

    for (int i = 1; i < cnt; i++) {
        if (nums[i] - nums[i - 1] > 1) {
            return nums[i - 1] + 1;
        } 
    }

    return nums[cnt - 1] + 1;
}
#else // 方法2
//#define INT_MAX 2^31
//有符号整形变量的范围是INT_MAX - 1 (-2147483648    2147483647)
int cmp(const void *a, const void *b) {  //对负数放弃比较 [-5, 4, 3, -6, 1] ->排序后[-5, -6,, 1, 3, 4]
    if (*(int *)a < 0) {
        return -1;
    }

    if (*(int*)b < 0 ) {
        return 1;
    }

    return (*(int *)a - *(int *)b);
}

int firstMissingPositive(int* nums, int numsSize){

    if (numsSize == 0) {
        return 1;
    }

    qsort(nums, numsSize, sizeof(int), cmp);
    int res = 1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            if (nums[i] > res) {
                return res;
            } else if (nums[i] == res)  {
                res++;
                continue;
            }
        }
    }

    return res;
}
#endif
```

