### 解题思路
利用双指针不断往两头逼近，当i遇到元音字母后，就会从另一头j继续寻找元音字母。当两头都找到后就会执行最后一个分支，交换两个位置处都元音字母。while(i <= j)条件保证两头都指针没相遇之前一直循环下去。

### 代码

```c
bool isVowel(char c) {
    if ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') ||
        (c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U')) {
        return true;
    } else {
        return false;
    }
}

void swap(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}

char * reverseVowels(char * s){
    int len = (int)strlen(s);
    char t;
    
    int i = 0, j = len - 1;
    while (i <= j) {
        if (!isVowel(s[i])) {
            i++;
        } else if (!isVowel(s[j])) {
            j--;
        } else {
            t = s[i];
            s[i] = s[j];
            s[j] = t;
            i++;
            j--;
        }
    }
    return s;
}
```