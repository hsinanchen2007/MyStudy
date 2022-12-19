![image.png](https://pic.leetcode-cn.com/a3d209df432d3984e826c9c824c4882f7aa552a1c5f5a6d579741e0dbc474810-image.png)

### 代码

```c
char * longestPalindrome(char * s){
    int right = 0, left = 0, count = 0;
    int startidx = 0;
    int max_len = 0;
    for (int i = 0; s[i] != '\0'; i += count) {
        count = 1;
        left = i - 1;
        right = i + 1;

        while ((s[right]!='\0') && (s[i] == s[right])) { // 选出重复字符
            right++;
            count++;
        }
        
        while ((left >= 0) && (s[right]!='\0') && (s[left] == s[right])) { // 由中心字符向左右扩展
            left--;
            right++;
        }
        
        if (max_len < (right - left - 1)) {
            max_len = right - left - 1;  // 左右标记不在回文子串范围内，在外面两侧，需要减1
            startidx = left + 1;
        }
    }
    s[startidx + max_len] = '\0';
    return s + startidx;
}
```