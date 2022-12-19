![2019-09-26_21-58.png](https://pic.leetcode-cn.com/b89bc3aab35d4386202108ec906f108cc24359bd56a4d2b9e14a4193819ff4c6-2019-09-26_21-58.png)

```c
int myAtoi(char * str){
    // 移除开头的空格
    while(*str == ' ')
        ++str;

    // 记录正负性
    int flag = 1;
    if (*str == '-') {
        flag = -1;
        ++str;
    }
    else if (*str == '+')
        ++str;

    int ret = 0;
    // 因为只能使用 32 位 int，因此将 ret 乘 10 后再与 INT_MAX 比较可能会溢出
    // 因此使用 ret 与 INT_MAX/10 比较
    int div = INT_MAX / 10;
    while (*str <= '9' && *str >= '0') {
        int dig = *str - '0';
        // 若 ret 比 div 小，则 ret * 10 + dig 也一定小于 INT_MAX，不会溢出
        // 若 ret 与 div 相等，只有 dig 比 8 小时不会溢出
        // 此处本来需要正负分开讨论，INT_MAX 个位是 7，INT_MIN 个位是 8
        // -INT_MIN 在 int 中会溢出，当 dig == 8 时直接当作溢出处理
        if (ret < div || (ret == div && dig < 8)) {
            ret = ret * 10 + dig;
            ++str;
        }
        // 溢出，根据正负性返回值
        else
            return (flag == 1? INT_MAX: INT_MIN);
    }
    return flag * ret;
}
```