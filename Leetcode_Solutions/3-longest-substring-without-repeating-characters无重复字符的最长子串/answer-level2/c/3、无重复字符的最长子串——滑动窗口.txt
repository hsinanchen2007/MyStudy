### 解题思路
1、暴力求解，两层循环；
2、滑动窗口，参考答案，巧妙利用了char[128]来存储下标；

### 代码

```c
#define max(a,b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring(char * s) {
    int Idx[128] = { 0 };
    int ret = 0;

    for (int i = 1, left = 1; *s; s++, i++) {
        if (Idx[*s] < left) {
            ret = max(ret, (i - left + 1));
        } else {
            left = Idx[*s] + 1;
        }
         Idx[*s] = i;
    }
    return ret;
}
```