### 解题思路
核心在于如何处理“*”
按照x*的字符串可分为三种情况，
1. x 与 x* 匹配：*多余  =>  f(i,j) = f(i, j-1)
2. xx 与 x* 匹配：*需要扩展  => f(i,j) = f(i-1, j) : if s[i] == p[j - 1] or p[j - 1] == '.'
3. y 与 x*匹配：x*都多余 => f(i,j) = f(i, j - 2)

### 代码

```c
bool isMatch(char * s, char * p){
    if (s == NULL || p == NULL) {
        return false;
    }

    if (p == NULL || strlen(p) == 0) {
        return strlen(s) == 0;
    }
    
    int len_s = strlen(s);
    int len_p = strlen(p);
    bool**f = (bool**)malloc((len_s + 1) * sizeof(bool*));
    for (int i = 0; i <= len_s; i++) {
        f[i] = (bool *)malloc(len_p + 1);
        memset(f[i], 0, len_p + 1);
    }
    
    f[0][0] = true;
    for (int j = 0; j < len_p; j++) {
        if (p[j] == '*') {
            f[0][j + 1] = f[0][j - 1];
        } else {
            f[0][j + 1] = false;
        }
    }

    for (int i = 0; i < len_s; i++) {
        for (int j = 0; j < len_p; j++) {
            if (p[j] == '*') {
                // 1.  x* 不存在
                if (j >= 1) {
                    f[i + 1][j + 1] = f[i + 1][j - 1];
                }
                // 2. x* 无需扩展x
                if (!f[i + 1][j + 1]) {
                    f[i + 1][j + 1] = f[i + 1][j];
                }                
                // 3. x* 需要扩展x
                if (!f[i + 1][j + 1] && (i >= 1)) {
                    if (s[i] == p[j - 1] || p[j - 1] == '.') {
                        f[i + 1][j + 1] = f[i][j + 1];
                    }
                }
            } else if ((p[j] == '.') || (s[i] == p[j])) {
                f[i + 1][j + 1] = f[i][j];
            }
        }
    }
    bool ret = f[len_s][len_p];
    for (int i = 0; i <= len_s; i++) {
        free(f[i]);
    }
    free(f);
    return ret;
}
```