### 解题思路
以i作为string遍历下标，j作为patern遍历下标，动态规划递推公式如下：
1. `s[i] == p[j]`时，`dp[j][i] = dp[j - 1][i - 1]`。此时隐含的条件是p[j]不是特殊字符
2. `p[j] == '.'`时，`dp[j][i] = dp[j - 1][i -1 ]`
3. `p[j] == '*'`时，分为两种情况
   - `p[j-1] =='.'`时，`dp[j - 2][temp_i]`（temp_i在0~i之间取值），如果有为true的，`dp[j][i] = true`。
举例来说，`s="x"`, `patern="ya.*"`。x与y分别表示所有可能存在的字符串，我们只需要确认字符串`"ya"`与x中任意字符是否能够等价即可。
   - 其他情况时，存在两类情况：
     1. 跳过`p[j]`，直接比较`p[j - 1]`以前字符`dp[j][i] = dp[j - 2][i]`
     2. 存在N个`p[j]`字符：则需先判断`p[j - 1]`与`s[i]`，二者相等时`dp[j][i] = dp[j][i - 1]`)

### 代码

```c
#define PRINTF //printf

bool isMatch(char *s, char *p)
{
    int s_len = strlen(s);
    int p_len = strlen(p);
    int i_loop, j_loop, temp_i, i, j;
    char **dp;

    if ((p_len == 2) && (p[0] == '.') && (p[1] == '*')) {
        return true;
    }

    if (p_len == 0) {
        if (s_len == 0) {
            return true;
        } else {
            return false;
        }
    }

    dp = (char **)malloc(sizeof(char **) * (p_len + 1));
    if (dp == NULL) {
        return false;
    } else {
        for (j_loop = 0; j_loop < p_len + 1; j_loop++) {
            dp[j_loop] = (char *)malloc(sizeof(char) * (s_len + 1));
            if (dp[j_loop] == NULL) {
                return false;
            } else {
                memset(dp[j_loop], false, s_len + 1);
            }
        }
    }

    dp[0][0] = true;
        for (j_loop = 1; j_loop < p_len + 1; j_loop++) {
        if (p[j_loop - 1] == '*') {
            PRINTF("\n[%3d]dp[j_loop - 2][0]=%d", __LINE__, dp[j_loop - 2][0]);
            dp[j_loop][0] = dp[j_loop - 2][0];
        }
    }

    PRINTF("\n[%3d]init dp:", __LINE__);
    PRINTF("\n[%3d]    # ", __LINE__);
    for (i_loop = 0; i_loop < s_len ; i_loop++) {
        PRINTF(" %c ", s[i_loop]);
    }

    for (j_loop = 0; j_loop < p_len + 1; j_loop++) {
        if (j_loop == 0) {
            PRINTF("\n[%3d] # ", __LINE__);
        } else {
            PRINTF("\n[%3d] %c ", __LINE__, p[j_loop - 1]);
        }

        for (i_loop = 0; i_loop < s_len + 1; i_loop++) {
            PRINTF(" %d ", dp[j_loop][i_loop]);
        }
    }

    for (i_loop = 1; i_loop < s_len + 1; i_loop++) {
        for (j_loop = 1; j_loop < p_len + 1; j_loop++) {
            i = i_loop - 1;
            j = j_loop - 1;
            PRINTF("\n[%3d]p[%d]=%c, s[%d]=%c", __LINE__, j, p[j], i, s[i]);
            if (p[j] == s[i]) {
                dp[j_loop][i_loop] = dp[j_loop - 1][i_loop - 1];
            } else {
                if (p[j] == '*') {
                    if (p[j - 1] == '.') {
                        // .*
                        if (j_loop == 2) {
                            // 在patern开头的情况
                            dp[j_loop][i_loop] = true;
                        } else {
                            // 不在开头
                            for (temp_i = 0; temp_i < s_len + 1; temp_i++) {
                                if (dp[j_loop - 2][temp_i]) {
                                    dp[j_loop][i_loop] = true;
                                    break;
                                }
                            }                       
                        }
                    } else {
                        PRINTF("\n[%3d]p[j-1]=%c, s[i]=%c, s[i-1]=%c", __LINE__, p[j - 1], s[i], s[i - 1]);

                        // 0 * p[j-1]
                        if (dp[j_loop - 2][i_loop] == true) {
                            dp[j_loop][i_loop] = true;
                            continue;
                        }

                        // 1 * p[j-1]
                        if ((p[j - 1] == s[i]) && (dp[j_loop][i_loop - 1] == true)) {
                            dp[j_loop][i_loop] = true;
                            continue;
                        }
                    }
                } else if (p[j] == '.') {
                    dp[j_loop][i_loop] = dp[j_loop - 1][i_loop - 1];
                }
            }
        }
    }

    PRINTF("\n[%3d]after calculated dp:", __LINE__);
    PRINTF("\n[%3d]    # ", __LINE__);
    for (i = 0; i < s_len ; i++) {
        PRINTF(" %c ", s[i]);
    }

    for (j = 0; j < p_len + 1; j++) {
        if (j == 0) {
            PRINTF("\n[%3d] # ", __LINE__);
        } else {
            PRINTF("\n[%3d] %c ", __LINE__, p[j - 1]);
        }

        for (i = 0; i < s_len + 1; i++) {
            PRINTF(" %d ", dp[j][i]);
        }
    }

    return dp[p_len][s_len];
}
```