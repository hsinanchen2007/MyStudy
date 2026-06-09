### 解题思路
1. 双指针对撞，可以去重
选择最左边的作为now固定，然后从now + 1至最右边，开始碰撞
遇到符合条件的，就加入结果集。
2. 怎么去重？
对于左和右，只要往内部找一直是相等的就移动，直到两个指针已经越过彼此，就移动下一个now
3. 防止溢出
有用例内容是很大的，这时候要考虑malloc出来的结果集内存究竟多大
怎么计算？
尝试出来6 * numsSize是可以通过的，也就是max = n * (An3 / Cn3)
4. 最需要注意的一点
returnColumnSize 也需要malloc

### 代码

```c
int Compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if (nums == NULL || numsSize < 3) {
        *returnSize = 0;
        return NULL;
    }
    
    qsort(nums, numsSize, sizeof(int), Compare);
    int now = 0;
    int low;
    int high;
    *returnSize = 0;
    long maxSize = (long)numsSize * 6;
    int **res = (int **)malloc(sizeof(int *) * maxSize);
    
    while (nums[now] <= 0 && (now + 2) < numsSize) {
        while (now > 0 && (now + 2) < numsSize&& nums[now] == nums[now - 1]) {
            now++;
        }
        if ((now + 2) >= numsSize) {
            break;
        }
        low = now + 1;
        high = numsSize - 1;
        int target = -nums[now];
        while(low < high) {
            if (nums[low] + nums[high] == target) {
                res[(*returnSize)] = (int *)malloc(sizeof(int) * 3);
                res[(*returnSize)][0] = nums[now];
                res[(*returnSize)][1] = nums[low];
                res[(*returnSize)][2] = nums[high];
                (*returnSize)++;
                int temp_low = nums[low];
                int temp_high = nums[high];
                while (low < numsSize && nums[low] == temp_low) {
                    low++;
                }
                while (high > now && nums[high] == temp_high) {
                    high--;
                }
                if (high <= low) {
                    break;
                }else {
                    continue;
                }
            } 
            
            if (nums[low] + nums[high] < target) {
                low++;
                continue;
            }
            
            if (nums[low] + nums[high] > target) {
                high--;
                continue;
            }
        }
        
        now++;
        low = now + 1;
        high = numsSize - 1;
        continue;

    }
    
    *returnColumnSizes = (int *)malloc(sizeof(int) * 6 * numsSize);
    for (int i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = 3;
    }
    
    return res;
}
```