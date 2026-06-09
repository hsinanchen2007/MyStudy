### 解题思路
执行用时 :4 ms, 在所有 C 提交中击败了96.72%的用户
内存消耗 :5.4 MB, 在所有 C 提交中击败了100.00%的用户

如果当前罗马字符值大于前一个的，如IV，当前是V，前一个是I，则应减去2I，即1+5-2=4。

### 代码

```c
int romanMap(char c) {
    switch (c) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default:  return 0;
    }
}

int romanToInt(char * s) {
    int ret = 0;
    char ch;
    int prev = INT_MAX;
    int cur;
    while ((ch = *s++) != '\0') {
        cur = romanMap(ch);
        ret += cur;
        if (cur > prev) ret -= prev * 2;
        prev = cur;
    }
    return ret;
}
```