### 解题思路
如果是RRRDDDD的话，虽然R比D少，但是R有先手优势，头三个D在说话前就被ban了，只有最后一个D能够发声，一轮后R和D依旧有存活的，所以一次遍历不能得出结论，必须多次遍历，直到出现一方一个不剩，那就是对方胜利了

### 代码

```c
char * predictPartyVictory(char * senate){
    bool R = true;
    bool D = true;
    int flag = 0;
    int qLen = strlen(senate);
    int i;
    char *p = senate;
    // 遍历数组直到出现一方一个不剩
    while (R & D) {
        R = false;
        D = false;
        // 遍历剩余数组
        while (*p) {
            if (*p == 'R') {
                R = true;
                if (flag < 0) {
                    *p = 'a';
                }
                flag++;
            } else if (*p == 'D') {
                D = true;
                if (flag > 0) {
                    *p = 'a';
                }
                flag--;
            }
            p++;
        }
        p = senate;
    }
    if (flag > 0) {
        return "Radiant";
    }
    return "Dire";
}
```