### 解题思路
注意题意，　找到最大长度有重复即可，不管重复了几次。封装一个函数判断此长度是否有重复字串。

这里用到了一个二分长度



给定字符串 S，找出最长重复子串的长度。如果不存在重复子串就返回 0。
 

示例 1：

输入："abcd"
输出：0
解释：没有重复子串。
### 代码

```c

int search(int L, char * S) {
    int i, len;
    char *temp = malloc(L+1);

    len = strlen(S);
    temp[L] = '\0';
    for (i = 0; i < len - L + 1; i++) {
        strncpy(temp, S+i, L);
        if (strstr(S + i + 1, temp))
            return true;
    }
    return false;
}

int longestRepeatingSubstring(char * S){
    int l = 1, r =strlen(S) - 1;
    int mid;

    while(l <= r) {
        mid = (l + r)/2;
        if (search(mid, S)) l = mid + 1; 
        else r = mid - 1;
    }
    return l - 1;
}
```