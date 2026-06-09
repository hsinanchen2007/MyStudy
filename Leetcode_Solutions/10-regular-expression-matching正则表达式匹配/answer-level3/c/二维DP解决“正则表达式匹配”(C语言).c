### 解题思路
二维DP。核心问题为'*'的处理，‘.’起混淆作用

编程框架为：判断p为0时与不同长度s的匹配情况，p为1时与s的匹配情况。。。

递推公式为(将可能变为true的情况整合相或)：

(1)s[i] == p[i] || p[i] == '.'时
    dp[i][j] = dp[i-1][j-1]

(2)p[i] == '*'时
    (2-1)s[i] == p[j-1] || p[j-1] = '.'
        dp[i][j] = dp[i][j-2];  //  s = "c", p = "cc*"  即“消掉前一个有可能匹配”
        dp[i][j] = dp[i-1][j];  //  s = "cbb", p = "cb*" 即“延续的前一个匹配情况”
    (2-2)s[i] != p[j-1]
        dp[i][j] = dp[i][j-2];  //  s = "c", p = "cb*"  即“消掉前一个有可能匹配”
(3)其余情况
    dp[i][j] = false;

根据以上地推公式，需要逐层（sid）逐次(pid)获得新的状态

![image.png](https://pic.leetcode-cn.com/b486a01194268c8fb09b93cbb21f0f4e5bccdab235c6e856df8c71ee5fef6cca-image.png)


### 代码

```c
/*
 * @lc app=leetcode.cn id=10 lang=c
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
#define SMAX_SIZE 1000
#define PMAX_SIZE 100

bool dp[SMAX_SIZE][PMAX_SIZE];

//【算法思路】二维DP。核心问题为'*'的处理，‘.’起混淆作用

//编程框架为：判断p为0时与不同长度s的匹配情况，p为1时与s的匹配情况。。。

//递推公式为(将可能变为true的情况整合相或)：

//(1)s[i] == p[i] || p[i] == '.'时
//    dp[i][j] = dp[i-1][j-1]

//(2)p[i] == '*'时
//    (2-1)s[i] == p[j-1] || p[j-1] = '.'
//        dp[i][j] = dp[i][j-2];  //  s = "c", p = "cc*"  即“消掉前一个有可能匹配”
//        dp[i][j] = dp[i-1][j];  //  s = "cbb", p = "cb*" 即“延续的前一个匹配情况”
//    (2-2)s[i] != p[j-1]
//        dp[i][j] = dp[i][j-2];  //  s = "c", p = "cb*"  即“消掉前一个有可能匹配”
//(3)其余情况
//    dp[i][j] = false;

//根据以上地推公式，需要逐层（sid）逐次(pid)获得新的状态
bool isMatch(char * s, char * p){
    int slen = strlen(s);
    int plen = strlen(p);

    //先给出plen == 0的解，后面专注与plen > 0
    if(plen == 0)
    {
        return slen == 0;
    }

    //注意：由于需要解决s为空的问题，因此遍历下标0表示字串为空
    dp[0][0] = true;
    dp[0][1] = false;

    // 根据递推公式，准备初始化值
    for(int i = 2; i <= plen; i++)
    {
        if(p[i - 1] != '*')
        {
            dp[0][i] = false;
        }
        else
        {
            dp[0][i] = dp[0][i - 2];
        }
    }

    for(int i = 1; i <= plen; i++)
    {
        dp[i][0] = false;
        
        dp[i][1] = (i == 1)? (s[0] == p[0] || p[0] == '.') : false;
    }

    // 初始值已经足够，可以开始迭代
    for(int i = 1; i <= slen; i++)
    {
        for(int j = 2; j <= plen; j++)
        {
            if(s[i - 1] == p[j - 1] || p[j - 1] == '.')
            {
                dp[i][j] = dp[i - 1][j - 1];
                //printf("dp[%d][%d] = dp[%d - 1][%d - 1] = %d\n", i, j, i, j, dp[i][j]);
            }
            else if(p[j - 1] == '*')
            {
                if(s[i - 1] == p[j - 2] || p[j - 2] == '.')
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 2];
                }
                else
                {
                    dp[i][j] = dp[i][j - 2];
                }
            }
            else
            {
                dp[i][j] = false;
                //printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
            }
        }
    }
/*
    for(int i = 0; i <= slen; i++)
    {
        for(int j = 0; j <= plen; j++)
        {
            printf("dp[%d][%d] = %d,   ", i, j, dp[i][j]);
        }
        printf("\n");
    }
*/
    return dp[slen][plen];
}


// @lc code=end


```