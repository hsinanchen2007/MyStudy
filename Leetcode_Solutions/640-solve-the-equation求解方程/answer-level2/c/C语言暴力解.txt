### 解题思路
字符串处理，直接扫描整个等式即可，按照等号分开后分别记录x的系数和常数系数。

### 代码

```c
char * solveEquation(char * equation){
    int x = 0;
    int n = 0;
    int i = 0;
    int isRight = 0;
    char c;

    int coefficient = -1;
    int isMinus = 0;
    
    while ((c = equation[i++]) != '\0') {
        if (c == 'x') {
            x += (coefficient == -1 ? 1 : coefficient) * ((~(isMinus ^ isRight) & 0x1) ? -1 : 1);
            coefficient = -1;
        } else if (c >= '0' && c <='9') {
            if (coefficient == -1) coefficient = 0;
            coefficient *= 10;
            coefficient += (c - '0');
        } else if (c == '+' || c == '-') {
            if (coefficient != -1) {
                n += (((isMinus ^ isRight) & 0x1) ? -1 : 1) * coefficient;
            }
            coefficient = -1;
            isMinus = (c == '-') ? 1 : 0;
        } else if (c == '=') {
            if (coefficient != -1) {
                n += (((isMinus ^ isRight) & 0x1) ? -1 : 1) * coefficient;
            }
            isMinus = 0;
            isRight = 1;
            coefficient = -1;
        }
    }
    if (coefficient != -1) {
        n += (((isMinus ^ isRight) & 0x1) ? -1 : 1) * coefficient;
    }
    if (x == 0) {
        if (n == 0) {
            return "Infinite solutions";
        } else {
            return "No solution";
        }
    } else {
        if (n % x == 0) {
            snprintf(equation, i, "x=%d", n/x);
        } else {
            snprintf(equation, i, "x=%f", (float)n/(float)x);
        }
        return equation;
    }
}
```