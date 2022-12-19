![QQ截图20190720073219.png](https://pic.leetcode-cn.com/2e2ddd8e8b0bef05f6ede86cd58d1e2d8929d7f14f564ff445544d7fdaa45805-QQ%E6%88%AA%E5%9B%BE20190720073219.png)

```
int strtop;
int scoreOfParentheses(char * S){
    if (S == NULL || S[0] == '\0') return 0;
    int len = strlen(S);
    strtop = 0;
    int sum = 0;
    while (strtop < len) sum += find(S);//对于这种情况：()()()
    return sum;
}
int comp_sum(char *str) //计算子括号的值
{
    int sum = 0;
    ++strtop;
    while (str[strtop] == '(') sum += comp_sum(str);//对于这种情况：(()()())
    ++strtop;
    return (sum ? 2*sum : 1);//如果sum不等于0，那么乘以2，否则为1
}

```
