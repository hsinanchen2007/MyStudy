![image.png](https://pic.leetcode-cn.com/eef558e46f0986482240d02b7da84d838e343f638095f8cc361aa9f1197028a4-image.png)

```
#define MAXSIZE 52

int longestPalindrome(char * s){
    if (s == NULL) {
        return 0;
    }

    int *map = (int *)malloc(MAXSIZE * sizeof(int));
    memset(map, 0, MAXSIZE * sizeof(int));

    int i = 0;
    int sLen = 0;
    sLen = strlen(s);
    int returnValue = 0;
    bool isSingle = false;

    for (i = 0; i < sLen; i++) {
        if ((s[i] >= 'a') && (s[i] <= 'z')) {
            map[s[i] - 'a']++;
        } else {
            map[s[i] - 'A' + 25]++;
        }
    }

    for (i = 0; i < MAXSIZE; i++) {
        if (map[i] > 1) {
            if (map[i] % 2 == 0) {
                returnValue += map[i];
            } else {
                returnValue = returnValue + map[i] - 1;
                isSingle = true;
            }
        } 
        if (map[i] == 1) {
            isSingle = true;
        }
    }

    if (isSingle == true) {
        returnValue = returnValue + 1;
    }

    return returnValue;
}
```
