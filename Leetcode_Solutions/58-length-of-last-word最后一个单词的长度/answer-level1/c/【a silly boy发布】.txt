![8DEBCF71-AF22-4955-84DA-3D35B7C7B685.jpeg](https://pic.leetcode-cn.com/13bdf27ded2fe8013f1cfc6419e630b2c8bb9550fb20e8a844a1bbd5ae70d783-8DEBCF71-AF22-4955-84DA-3D35B7C7B685.jpeg)

```
int lengthOfLastWord(char * s){
    if (s == NULL) {
        return 0;
    }
    int sLen = strlen(s);
    int i;
    int tmpPos;
    for (i = sLen - 1; i >= 0; i--) {
        if (s[i] != ' ') {
            tmpPos = i;
            break;
        }
    }

    for (i = tmpPos; i >= 0; i--) {
        if (s[i] == ' ') {
            return tmpPos - i;
        }
    }
    return tmpPos + 1;
}
```
