### 解题思路
处理字符串的问题，要想办法应对各种奇奇怪怪的输入，没有什么特殊算法和技巧，没意思，选了一个写的比较简单的修改一下交了

原答案:
作者：non1th
链接：https://leetcode-cn.com/problems/string-to-integer-atoi/solution/cyu-yan-jie-fa-ji-si-lu-by-non1th/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处
### 代码

```c
int myAtoi(char* str) {
    //去除空格及判断符号位
    while(*str==' ')
        ++str;
    //默认正数
    int flag = 1;
    switch (*str)
    {
        case '-':flag = -1;
        case '+':str++;
    }
    //排除非数字的情况
    if (*str < '0' || *str>'9')
        return 0;

    long ret = 0;
    while (*str >= '0' && *str <= '9') {
        ret = ret * 10 + (*str - '0');
        //判断溢出
        if ((int)ret != ret)
            return (flag == 1) ? (INT_MAX) : (INT_MIN);
        str++;
    }
    ret *= flag;
    return (int)ret;
}

```