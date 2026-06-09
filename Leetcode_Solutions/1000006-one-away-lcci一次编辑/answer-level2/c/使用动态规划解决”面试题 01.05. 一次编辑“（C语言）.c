### 解题思路
问题可以拆解为两个子问题：

1.长度相同：只能替换，只需找到不同字符数量即可

2.长度不同：

（1）差超过1，则一定false

（2）差为1，只需判断两个状态，即：dp[i][0],表示first[i]和second[i]；dp[i][1],表示first[i + 1]和second[i]；

递推公式为：

dp[i][0] = second[i - 1] == first[i - 1]? dp[i - 1][0] : dp[i - 1][0] + 1
dp[i][1] = second[i - 1] == first[i]? MMIN(dp[i][0] + 1, dp[i - 1][1]) : MMIN(dp[i][0] + 1, dp[i - 1][1] + 1)


![image.png](https://pic.leetcode-cn.com/d74dca553513b298db99eaa3f4c3210a001405dffa919f9325ab791ed42ee324-image.png)


### 代码

```c
#define STR_LEN     100
#define MMIN(a, b)        ((a) < (b)? (a) : (b))

int dp[STR_LEN][2];

//【算法思路】dp。两者长度差2则返回false；差1，可能删除，或插入；相等则是替换
bool oneEditAway(char* first, char* second){
    int flen = strlen(first);
    int slen = strlen(second);

    if(flen == 0 && slen == 0)
    {
        return true;
    }

    //两者相等，分析有几个字符不同
    if(flen == slen)
    {
        int dcnt = 0;
        for(int i = 0; i < flen; i++)
        {
            if(first[i] != second[i])
            {
                dcnt++;
            }
        }

        return dcnt <= 1;
    }

    if(abs(flen - slen) > 1)
    {
        return false;
    }

    if(flen < slen)
    {
        return oneEditAway(second, first);
    }

    //printf("first:  %s, second:  %s\n", first, second);

    //此处只解决first比secend长1个的情况，这里不能用替换，只能插入或删除
    //dp[i][j] 表示first[i+j]和second[i]需要几次编辑
    for(int i = 0; i <= slen; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 0;
    }

    dp[0][0] = 0;
    dp[0][1] = 1;

    for(int i = 1; i <= slen; i++)
    {
        dp[i][0] = second[i - 1] == first[i - 1]? dp[i - 1][0] : dp[i - 1][0] + 1;
        dp[i][1] = second[i - 1] == first[i]? MMIN(dp[i][0] + 1, dp[i - 1][1]) : MMIN(dp[i][0] + 1, dp[i - 1][1] + 1);
    }
/*
    for(int i = 0; i <= slen; i++)
    {
        printf("dp[%d][%d] = %d, dp[%d][%d] = %d\n", i, 0, dp[i][0], i, 1, dp[i][1]);
    }
*/
    return dp[slen][1] <= 1;
}
```