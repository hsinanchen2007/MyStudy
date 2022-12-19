### 解题思路
回溯法，依次将字符串拼在一起计算长度。过程中需要注意字符串本身也不要能有重复字符。

### 代码

```c
int fillArr(char ** arr, int arrSize, int index, char *s)
{
    int tmpLen = strlen(s);
    char *newChar = NULL;
    // 如果字符串数组已经遍历完了，则返回字符串长度
    if (index == arrSize) {
        return tmpLen;
    }
    int i, j;
    int flag;
    // 遍历剩余字符串
    for (i = index; i < arrSize; i++) {
        char *p = arr[i];
        flag = 0;
        // 检查待插入字符串本身是否有重复，待插入字符串与已有字符串是否有重复
        // 如果有重复的话都要跳过，这里用一个flag来标记
        while (*p) {
            char *q = p + 1;
            while(*q) {
                if (*p == *q) {
                    flag = 1;
                    break;
                }
                q++;
            }
            for (j = 0; j < strlen(s); j++) {
                if (*p == s[j]) {
                    flag = 1;
                }
            }
            p++;
        }
        if (flag == 1) {
            continue;
        }
        p = arr[i];
        // 如果不重复则新增一个字符串
        newChar = (char *)malloc(sizeof(char) * (strlen(s) + strlen(p) + 1));
        sprintf(newChar, "%s%s", s, p);
        // 继续遍历，用新字符串是为了原有的s能够用来回溯
        int tmp = fillArr(arr, arrSize, i + 1, newChar);
        // tmpLen取较大的值
        tmpLen = tmpLen > tmp ? tmpLen : tmp;
    }
    return tmpLen;
}
int maxLength(char ** arr, int arrSize){
    char *s = "";
    return fillArr(arr, arrSize, 0, s);
}
```