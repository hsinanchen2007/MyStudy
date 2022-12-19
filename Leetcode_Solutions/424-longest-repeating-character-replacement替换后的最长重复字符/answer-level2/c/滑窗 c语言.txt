### 解题思路
利用滑窗
缩小滑窗的条件，当前滑窗内的元素总数 - 最大的元素个数 > k ，说明k无法替换全部的不一样的元素
在缩小之前，要把最左边的元素对应的个数 -1
扩大滑窗的条件，就是当前滑窗的元素总数 - 最大的元素个数 <= k， 说明k可以替换剩余不一样的元素
res始终保存最大的元素个数

### 代码

```c
int characterReplacement(char * s, int k){
    int res = 0;
    int slow = 0;
    int fast;
    int map[26] = {0};
    int len = strlen(s);
    int idx;
    for (fast = 0; fast < len; fast++) {
        idx = s[fast] - 'A'; // 0-25分别存储字符个数
        map[idx]++;
        res = res < map[idx] ? map[idx] : res;
        if (fast - slow + 1 - res > k) {
            idx = s[slow] - 'A';
            map[idx]--;
            slow++;
        }
    }
    return len - slow;
}
```