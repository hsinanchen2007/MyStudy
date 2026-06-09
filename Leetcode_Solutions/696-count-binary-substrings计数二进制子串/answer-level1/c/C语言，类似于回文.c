### 解题思路
找到“01”字串，或者“10”字串时，开始寻找回文串，找到的个数就是出现的01串的个数。

### 代码

```c
void calculate(char *s, int start, int end, int *count) {
    char f = s[start];
    char l = s[end];
    while (start >= 0 && end < strlen(s) && s[start] == f && s[end] == l) {
        start--;
        end++;
        (*count)++;
    }
}
int countBinarySubstrings(char * s){
    int count = 0;
    int len = strlen(s);

    for (int i = 1; i < len; i++) {
        if (s[i - 1] == '0' && s[i] == '1') {
            calculate(s, i - 1, i, &count);
        }
        if (s[i - 1] == '1' && s[i] == '0') {
            calculate(s, i - 1, i, &count);
        }
    }
    return count;
}

```