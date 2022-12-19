### 解题思路
执行用时 :
0 ms, 在所有 C 提交中击败了100%的用户
内存消耗 :
6.9 MB, 在所有 C 提交中击败了35.58%的用户

一定要看懂题目的要求，过滤掉不需要的字符就行
### 代码

```c
int myAtoi(char * str){
    int i = 0;
    int unflag = 1;
    long num = 0;
    int max = 0x7fffffff;

    while (str[i] != '\0') {
        if (str[i] == ' ') {
            i++;
            continue;
        }
        if ((str[i] == '-') || (str[i] == '+')) {
            unflag = (str[i] == '-') ? -1 : 1;
            i++;
        } else if (str[i] >= '0' && str[i] <= '9') {
            unflag = 1;
        } else {
            return 0;
        }

        while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
            num = num * 10 + (str[i] - '0');
            if ((num * unflag > max) || (num * unflag < (-1 * (max + 1)))) {
                return unflag == 1 ? max : -1 * (max + 1);
            }
            i++;
        }
        return unflag * num;
    }
    return unflag * num;
}
```