### 解题思路
![image.png](https://pic.leetcode-cn.com/0519a61d6794dd8cd41d8ab874925a8ea21a3d0ad854ba9006a72c167e8bea9f-image.png)
分别从两边遍历，直到两指针相遇；两个指针都指向元音时交换。
### 代码

```c
bool is_aeiou(char s) {
    if(s == 'a' || s == 'A' ||
       s == 'e' || s == 'E' ||
       s == 'i' || s == 'I' ||
       s == 'o' || s == 'O' ||
       s == 'u' || s == 'U') {
        return true;
    }
    return false;
}

char * reverseVowels(char * s){
    int len = strlen(s);
    int i = 0, j = len - 1;
    char temp;
    while(i < j) {
        if(is_aeiou(s[i]) && is_aeiou(s[j])) {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
        if(!is_aeiou(s[i])) {
            i++;
        }
        if(!is_aeiou(s[j])) {
            j--;
        }
    }
    return s;
}
```