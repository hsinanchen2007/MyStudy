# 通过标记为计算。踩了多个坑。

```
bool circularArrayLoop(int* nums, int numsSize){
    if (nums == NULL || numsSize <= 0) {/* 第一个坑空数组 */
        return false;
    }
    int *flag = (int *)malloc(numsSize * sizeof(int));
    memset(flag, -1, numsSize * sizeof(int));/* 第二个坑环到了之前不成立的数据 */
    for (int i = 0; i < numsSize; i++) {/* 第三个坑每个数据都要判断是否可以成环 */
        int count = 0;
        int start = i;
        int index = i;
        int diriction = nums[index];
        while (flag[index] == -1) {
            int next = (index + numsSize + nums[index] % numsSize) % numsSize;
            if ((diriction > 0 && nums[index] > 0) ||
                (diriction < 0 && nums[index] < 0)) {
                count++;
            }else {
                diriction = nums[index];
                count = 1;
                start = index;
            }
            flag[index] = start;
            if (count > 1 && flag[next] == start && index != next) {/* 第四个坑防止最后一个数字自环 */
                free(flag);
                flag = NULL;
                return true;
            }
            index = next;
        }
    }
    free(flag);
    flag = NULL;
    return false;
}
```

