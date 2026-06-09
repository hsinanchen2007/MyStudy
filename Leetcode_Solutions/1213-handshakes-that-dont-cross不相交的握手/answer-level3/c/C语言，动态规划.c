### 解题思路
动态规划：奇数的dp=0；dp[0] = 1;
dp[num]:
for (int i = 1; i < num; i = i + NUM_2)  {
        g_dpMap[num]    +=  ((g_dpMap[i - 1] * g_dpMap[num - i - 1]) % MOD_MUN);
        g_dpMap[num]    = g_dpMap[num] % MOD_MUN;
    }
![image.png](https://pic.leetcode-cn.com/dbc98084552792396e4714eedf3f40bb5c1fe92e906545d21eb9cf1b2edf42fc-image.png)


### 代码

```c
#define             MAX_SIZE        10002
#define             NUM_2           2
#define             MOD_MUN         (1000000000 + 7)

unsigned long long      g_dpMap[MAX_SIZE];
int                     g_curNum            = 0;
int                     firstFlag           = 1;


void Caculate(int num)
{
    if (num == NUM_2) {
        g_dpMap[num]    = 1;
        return;
    }

    for (int i = 1; i < num; i = i + NUM_2)  {
        g_dpMap[num]    +=  ((g_dpMap[i - 1] * g_dpMap[num - i - 1]) % MOD_MUN);
        g_dpMap[num]    = g_dpMap[num] % MOD_MUN;
    }
}

void InitGlobalPara(int num_people)
{
    if (firstFlag == 1) {
        memset(g_dpMap, 0, sizeof(g_dpMap));
        g_dpMap[0]      = 1;
        g_curNum        = 0;
    }

    firstFlag       = 0;

    if (num_people <= g_curNum) {
        return;
    }

    for (int i = g_curNum + NUM_2; i <=  num_people; i = i + NUM_2) { 
        Caculate(i);
    }

    g_curNum        = num_people;
}

int numberOfWays(int num_people)
{
    if ((num_people <= 0) || (num_people % 2 != 0)) {
        return 0;
    }

    InitGlobalPara(num_people);

    return (int)g_dpMap[num_people];
}
```