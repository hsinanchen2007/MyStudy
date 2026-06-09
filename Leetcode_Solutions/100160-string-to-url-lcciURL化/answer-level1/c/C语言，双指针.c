### 解题思路
此处撰写解题思路

### 代码

```c
char* replaceSpaces(char* S, int length){
    int spaceNum = 0;
    int i, j, index;

    for (i = 0; i < length; i++) {
        if (S[i] == ' ') {
            spaceNum++;
        }
    }

    index = length + 2 * spaceNum;
    S[index] = '\0';
    for (i = index - 1, j = length - 1; i >= 0 && j >= 0; j--) {
        if (S[j] == ' ') {
            S[i--] = '0';
            S[i--] = '2';
            S[i--] = '%';
        } else {
            S[i--] = S[j];
        }
    }

    return S;
}
```