### 解题思路
去重后利用并查集计算子序列长度

### 代码

```c
int *cnt;
/* 并查集寻找根节点 */
int find(int *fa, int x)
{
    if(fa[x] == x){
        return fa[x];
    } else {
        return find(fa, fa[x]);
    }
}
/* 并查集合并结点 */
void join(int *fa, int x, int y)
{
    int xx = find(fa, x);
    int yy = find(fa, y);
    if (xx == yy) {
        return;
    }
    fa[xx] = yy;
    cnt[yy] += cnt[xx];
}
/* 去除重复值时调用 */
bool isExit(int num, int* list, int numsSize){
    for(int i = 0; i < numsSize; i++) {
        if (num == list[i])return true;
    }
    return false;
}
int longestConsecutive(int* nums, int numsSize){
    int max = 0;
    int n = 0;
    bool first = true;
    int *fa = (int *)malloc(sizeof(int) * numsSize);
    int *list = (int *)malloc(sizeof(int) * numsSize);
    memset(list, 0, sizeof(int) * numsSize);
    cnt = (int *)malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; i++) {
        fa[i] = i;
        cnt[i] = 1;
    }
    /* 去除nums中的重复值，赋值给新的数组 */
    for(int i = 0; i < numsSize; i++) {
        if (nums[i] == 0 && first == true){
            n++;
            first = false;
            continue;
        }
        if (isExit(nums[i],list,numsSize))continue;
        list[n] = nums[i];
        n++;
    }
    /* 利用并查集计算子序列长度 */
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(list[i]+1 == list[j] || list[i] == list[j] + 1) {
                join(fa, i,j);
            }
        }
    }
    /* 获取最长子序列的长度 */
    for(int i = 0; i < numsSize; i++) {
        max = max > cnt[i] ? max : cnt[i];
    }
    free(fa);
    free(cnt);
    free(list);
    return max;
}
```