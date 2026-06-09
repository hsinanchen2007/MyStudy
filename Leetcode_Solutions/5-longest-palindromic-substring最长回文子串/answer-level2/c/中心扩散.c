### 解题思路
此处撰写解题思路

### 代码

```c
/*
怎么算回文中心：
a b b a 为例：a b b a 本身都可以作为中心，它们之间的空白也可以作为中心
所以有 n + n - 1 = 2n - 1 个中心

还有种理解方式：中心可以是一个字符的情况，也可以是两个字符的情况。
一个字符为中心：a b b a
两个字符为中心：ab bb ba
这样也是 2n - 1 个。

倾向于使用第二种方式，这样，可以减小比较的次数，比如 ab为中心，就一定不是回文。

简化的思路：左右不要同时扩张，而是先扩张右边，先去重。然后左右一起扩张。
*/
static void expand(char *s, int midPos, int *max, int *leftPos, int *rightPos) {
    int left = 0;
    int right = 0;

    right = midPos + 1;
    left = midPos - 1;

    while(s[right] != '\0' && s[midPos] == s[right]) {
        right++;
    }

    while(left >= 0 && s[right] != '\0' && s[left] == s[right]) {
        left--;
        right++;
    }

    left++;
    right--;
    if (right - left + 1 > *max) {
        *max = right - left + 1;
        *leftPos = left;
        *rightPos = right;
    }
}

char *longestPalindrome(char * s) {
    int left = 0;
    int right = 0;
    int max = 0;

    if (strlen(s) == 0 || strlen(s) == 1) {
        return s;
    }

    for (int i = 0; i < strlen(s); i++) {
        // 需要注意"ccc"的场景，以两个字符作为中心不一定是最优解
        expand(s, i, &max, &left, &right);
    }

    s[right + 1] = '\0';
    return (s + left);
}
```