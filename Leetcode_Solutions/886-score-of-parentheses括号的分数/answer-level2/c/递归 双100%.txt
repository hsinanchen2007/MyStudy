### 解题思路
此处撰写解题思路
1、遇到‘）’将内部数据乘以2；
2、遇到‘（）’内部没有其他（）返回1；
3、遇到‘（’继续进行递归
![image.png](https://pic.leetcode-cn.com/4fea7331f086d10b245cff40e99ac434e8e429625e1b443604a107796baf658b-image.png)


### 代码

```c
int GetScore(char **S)
{
    int score = 0;
    while (**S != '\0') {
        if (**S == '(') {
            *S += 1;
            score += GetScore(S);
        } else {
            *S += 1;
            score *= 2;
            return (score == 0) ? 1 : score;
        }
    }
    return score;
}
int scoreOfParentheses(char *S)
{
    return GetScore(&S);
}
```