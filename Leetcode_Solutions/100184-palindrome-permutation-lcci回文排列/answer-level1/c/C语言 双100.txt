### 解题思路
此处撰写解题思路

### 代码

```c
bool canPermutePalindrome(char* s){
    int hash[128] = {0};
    int nums = 0;// 出现次数为奇数的字母个数
    char ch = ' ';

    for (int i = 0; s[i] != '\0'; i++) {
        hash[s[i]]++;
    }

    for (int j = 0; s[j] != '\0'; j++) {
        if ((hash[s[j]] % 2) != 0) {
            if (ch != s[j]) {
                nums++;
                ch = s[j];
            }
        }
    }

    return (nums > 1) ? false : true;
}
```