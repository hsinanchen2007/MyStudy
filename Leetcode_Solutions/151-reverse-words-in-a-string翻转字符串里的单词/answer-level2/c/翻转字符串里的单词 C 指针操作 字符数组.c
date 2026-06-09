### 解题思路
此处撰写解题思路

### 代码

```c

#include <string.h>

#define swap(a,b) {{a ^= b ; b ^= a; a ^= b;}}

// 翻转字符串
void reve(char *s, int l, int r) {
    if (r <= l) return ;
    while (l < r) {
        // swap(s[l],s[r]);
        int temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        l++, r--;
    }
}

char * reverseWords(char * s) {
    int l = 0, r = strlen(s) - 1;
    // 翻转整句字符串
    reve(s,l,r);
    // 除掉前导空格
    while (s[0] == ' ') s++;
    // i：每个单词的第一个字母，j：计算单词长度
    int i = 0, j = 0;
    char *temp = s;
    // 循环处理每个单词
    while (j <= r) {
        // 计算单词长度
        while (s[j] != ' ' && s[j] != 0) j++;
        // 翻转单词字符串
        reve(s,i,j - 1);
        // 当单词间只有一个空格时是自己赋给自己，但是当单词间有多个空格时，可以去掉多余的空格
        for (int k = 0; k < j - i; k++) {
            *(temp + k) = s[i + k];
        }
        temp = temp + j - i;
        // j移动到下一个单词开头
        while(s[j] == ' ') j++;
        // i移动到下一个单词开头
        i = j;
        // 字符串结尾结束循环
        if (s[j] == 0) {
            *temp = 0;
            break;
        }
        // 默认处理完一个单词，加一个空格
        *temp = ' ';
        temp++;
    }
    return s;
}


int main(){
    char ss[] = {'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e','\0'};
    printf("%s\n", reverseWords(ss));
}


```