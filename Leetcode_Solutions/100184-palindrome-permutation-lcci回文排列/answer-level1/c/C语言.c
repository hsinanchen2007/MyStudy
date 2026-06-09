### 解题思路
此处撰写解题思路
整个字符串中最多出现1个奇数字符

### 代码

```c
#define CHARNUM 256

bool canPermutePalindrome(char* s){
    int *arr;
    int sz, i, oddNum;

    sz = strlen(s);
    if (sz <= 0) {
        return true;
    }

    arr = (int *)malloc(sizeof(int) * CHARNUM);
    memset(arr, 0, sizeof(int) * CHARNUM);
    for (i = 0; i < sz; i++) {
        arr[s[i]]++;
    }

    oddNum = 0;
    for (i = 0; i < CHARNUM; i++) {
        if (arr[i] % 2 == 1) {
            oddNum++;
            if (oddNum > 1) {
                return false;
            }
        }
    }

    return true;
}

```