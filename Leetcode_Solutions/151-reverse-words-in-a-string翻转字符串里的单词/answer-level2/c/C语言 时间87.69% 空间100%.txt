### 解题思路
1. 去掉字符串中所有没用的空格，用的原地操作法，最后别忘了加'\0'。

2. 全部反转

3. 反转每个单词

注意点：原地操作完字符串要加终止，若最后一个是空格则把空格替换成终止。操作完之后用strlen是求不出字符串长度的，要用之前定义的索引


### 代码

```c
#define END -2

char * reverseWords(char * s){
    
    int i = 0;
    int j = 0;
    int flag = 0;
    int sLen = strlen(s);
    while (s[j] != '\0') {
        if (s[j] != ' ') {
            s[i++] = s[j++];
            flag = 1;
        }
        else {
            if (flag == 1) {
                s[i++] = s[j++];
                flag = 0;
                continue;
            }
            j++;
        }
    }
    if (i >= 1 && s[i - 1] == ' ') {
        s[i - 1] = '\0';
        i--;
    }
    else {
        s[i] = '\0';
    }
    // 下面进行整体反转
    int l = 0;
    int r = i - 1;
    while (l < r) {
        char tmp;
        tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
    }
    // 下面进行单词反转
    int start = 0;
    int end = END;
    int k = 0;
    for (; k <= i; k++) {
        if (s[k] == ' ' || s[k] == '\0') {
            start = end + 2;
            end = k - 1;
            while (start < end) {
                char tmp;
                tmp = s[start];
                s[start] = s[end];
                s[end] = tmp;
                start++;
                end--;
            }
            end = k - 1;
        }
    }
    return s;
}


```