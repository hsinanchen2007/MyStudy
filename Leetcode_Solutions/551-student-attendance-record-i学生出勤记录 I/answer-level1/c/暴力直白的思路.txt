##菜鸟的暴力思路，O(∩_∩)O哈哈~

### 代码

```c
bool checkRecord(char * s){
    int i;
    int cntA = 0;
    int cntL = 1;

    for (i = 0; i < strlen(s); i++) {
        if (s[i] == 'A') {
            cntA++;
        } else if (s[i] != 'L') {
            cntL = 1;
        }
        if ((i > 0) && (s[i-1] == 'L') && (s[i] == 'L')) {
            cntL++;
            if (cntL > 2) {
                return false;
            }
        }
    }

    if ((cntA <= 1) && (cntL <= 2)) {
        return true;
    } else {
        return false;
    }
}
```