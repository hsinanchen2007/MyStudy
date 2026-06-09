```
bool dfs(int *nums, int step, int dst)
{
    if (step >= dst) {
        return true;
    }

    int cnt = nums[step];
    if (cnt == 0) {
        return false;
    }
    bool flag;
    for (int i = cnt; i > 0; i--) {
        flag = dfs(nums, step + i, dst);
        if (flag == true) {
            return true;
        }
    }

    return flag;
}

bool canJump(int* nums, int numsSize){
    if (numsSize <= 1) {
        return true;
    }

    bool flag = dfs(nums, 0, numsSize - 1);
    return flag;
}
```
