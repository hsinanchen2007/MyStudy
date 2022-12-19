最后没有设置字符串的结尾, 参考其他的答案后改正了
就是要在最后一位添加'\0'作为字符串的结尾标识符
```
class Solution {
public:
    string replaceSpaces(string str, int len) {
        int numOfSpace = 0;
        int i = 0, j = 0;
        for(; i < len; i++) {
            if(str[i] == ' ') {
                numOfSpace++;
            }
        }
        int extendedLength = len + 2 * numOfSpace;
        i = extendedLength - 1;  // 从后向前比较
        if(len < str.length()) {
            str[extendedLength] = '\0';  // 注意这里就是我添加的地方
        }
        for(j = len - 1; j>= 0; j--) {
            if(str[j] != ' ') {
                str[i--] = str[j];
            } else {
                str[i--] = '0';
                str[i--] = '2';
                str[i--] = '%';              
            }
        }
        return str;
    }
};
```
