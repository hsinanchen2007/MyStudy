算法：
1、火柴长度求和除以4，得到商
2、按照长度从大到小排序
3、先从长的火柴里面组合商，如果可以组合成4个商，则返回true

```
int compare(const void* v1,const void* v2) {
    return *(int*)v2-*(int*)v1;
}
bool dfs(int* nums, int numsSize, int start, int cha) {
    for (int i=start;i<numsSize;i++) {
        if (0 == nums[i]) {
            continue;
        }
        if (cha == nums[i]) {
            nums[i] = 0;
            return true;
        }
        if (nums[i] > cha) {
            continue;
        }

        if (true == dfs(nums,numsSize,i+1,cha-nums[i])) {
            nums[i] = 0;
            return true;            
        }
    }
    return false;
}
bool makesquare(int* nums, int numsSize){
    // 1. 边界值
    if (numsSize < 4) {
        return false;
    }

    // 2.
    // 2.1 火柴长度求和除以4，得到商
    int i;
    int sum = 0; // 给定的火柴长度和在 0 到 10^9之间。
    for (i=0;i<numsSize;i++) {
        sum += nums[i];
    }
    if (sum%4 != 0) {
        return false;
    }
    int shang = sum/4;
    // 2.2 按照长度从大到小排序
    qsort(nums,numsSize,sizeof(int),compare);
    if (nums[0] > shang) {
        return false;
    }
    // 2.3 先从长的火柴里面组合商，如果可以组合成4个商，则返回true
    int edge = 0; // 边的个数
    for (int i=0;i<numsSize;i++) {
        if (0 == nums[i]) {
            continue;
        }
        if (shang == nums[i]) {
            edge++;
            continue;
        }
        // if (nums[i] < shang)
        if (true == dfs(nums,numsSize,i+1,shang-nums[i])) {
            edge++;
        }
    }
    if (edge == 4) {
        return true;
    }
    return false;
}
```
