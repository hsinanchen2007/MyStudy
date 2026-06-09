### 解题思路
此处撰写解题思路

### 代码

```c
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int visited[50000];
int dfs(int pos, int *nums, int numsSize) {
    if (pos == numsSize-1) {
        return 1;
    }
    int furthJump ;
    furthJump = MIN(pos+nums[pos], numsSize-1);
    for (int i = furthJump; i > pos; i--) {
        if (visited[i] == 0) {
            visited[i] = 1;
            if (dfs(i, nums, numsSize) == 1) {
                return 1;
            }
        }

    }
    return 0;
}
bool canJump(int* nums, int numsSize){
    memset(visited, 0, sizeof(visited));
    return dfs(0, nums, numsSize);
}
```