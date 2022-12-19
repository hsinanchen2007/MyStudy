### 解题思路
此处撰写解题思路
1.字符个数建立表；
2.奇数和偶数个数时，不同处理
3.若存在奇数个数时，最后长度加1
4.ASCII码 A-z 不连续， A 65，z 122 中间有其他字符，数组长度 122-65+1
### 代码

```c
// ASCII码 A-z 不连续， A 65，z 122 中间有其他字符，数组长度 122-65+1
#define CHAR_ARRAY_SIZE 58

int longestPalindrome(char * s)
{
    if (s == NULL || strlen(s) == 0) {
        return 0;
    }

    int charArrayCnt[CHAR_ARRAY_SIZE] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int index = s[i] - 'A'; // 大小写都存在时，从A开始
        charArrayCnt[index]++;
    }

    int maxLen = 0;
    bool exisOddCount = false;
    for (int i = 0; i < CHAR_ARRAY_SIZE; i++) {
        if (charArrayCnt[i] % 2 == 0) {
            maxLen = maxLen + charArrayCnt[i]; // 字符是偶数个数时直接相加
        }

        if (charArrayCnt[i] % 2 == 1) {
            maxLen = maxLen + (charArrayCnt[i] - 1); // 字符是奇数个数时，个数减1后相加
            exisOddCount = true;
        }
    }

    if (exisOddCount) {
        maxLen = maxLen + 1; // 如果存在奇数个数时，还可以加1个放最中间
    }

    return maxLen;
}
```