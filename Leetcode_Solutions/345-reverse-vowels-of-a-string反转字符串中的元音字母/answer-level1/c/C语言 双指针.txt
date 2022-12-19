### 解题思路
双指针进行移动碰撞，只有遇到都是元音的情况下进行swap；
如果left是元音，right不是，就移动右指针；
如果left不是，right是元音，就移动左指针。
需要注意的是，用例里面一定要注意到元音不止是小写，大写字母也算作是不同的原因字母，共有10个

### 代码

```c
bool isVowel(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
      || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return true;
    }
    return false;
}

void swap(char *s, int i, int j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

char * reverseVowels(char * s){
    if (s == NULL) {
        return NULL;
    }
    
    int fast = strlen(s) - 1;
    int slow = 0;
    while(slow < fast) {
        if(isVowel(s[slow]) && isVowel(s[fast])) {
            swap(s, slow, fast);
            slow++;
            fast--;
        }else if (isVowel(s[slow])) {
            fast--;
        }else {
            slow++;
        }
    }
    return s;
}
```