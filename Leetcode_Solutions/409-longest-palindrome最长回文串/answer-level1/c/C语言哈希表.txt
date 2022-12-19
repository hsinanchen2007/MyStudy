### 解题思路
回文串分两种：奇数和偶数个数，只能插入一个奇数个数的数，各个字符信息可以使用哈希表来保存。

### 代码

```c
#define MAXLEN 1010
#define CHARSIZE 52
#define PRINTF printf
int longestPalindrome(char * s){
    int iRet = 0;
    int chrHash[CHARSIZE] = {0};
    if(s == NULL) {
        goto END;
    }
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if ((s[i] >= 'a') && (s[i] <= 'z')) {
            int index = (s[i] - 'a');
            chrHash[index]++;
        }
        if ((s[i] >= 'A') && (s[i] <= 'Z')) {
            int index = (s[i] - 'A' + 26);
            chrHash[index]++;
        }
    }
    bool haveOdd = false;
    for(int i = 0; i < CHARSIZE; i++) {
        if ((chrHash[i] % 2 == 1) && (haveOdd == false)) {
            haveOdd = true;
        }
        iRet += ((chrHash[i] / 2) * 2);
    }
    if (haveOdd == true) {
        iRet++;
    }
    PRINTF ("%d\n", iRet);
END:
    return iRet;
}
```