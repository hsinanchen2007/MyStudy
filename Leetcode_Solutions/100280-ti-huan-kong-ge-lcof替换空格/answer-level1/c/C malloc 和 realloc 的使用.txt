### 解题思路
1. 重新申请内存空间，使用malloc申请大于3*n(n为原串长度)的空间，然后O(n)时间进行替换。
2. 如果在原串上更改，则需统计串长度和空格长度，然后使用realloc改变串长度，然后从尾部进行替换。
### 代码
1. 思路1代码
    ```
    char* replaceSpace(char* s){
        int n = 0;
        for(int i = 0; s[i] != '\0'; ++i) {
            ++n;
        }
        // printf("%d", n);
        char* res;
        res = (char*)malloc(3 * (n + 3) * sizeof(char));
        int k = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] != ' '){
                res[k++] = s[i];
            }else {
                res[k++] = '%';
                res[k++] = '2';
                res[k++] = '0';
            }
        }
        res[k] = '\0';
        return res;
    }
    ```

2. 思路2代码
    ```c
    char* replaceSpace(char* s){
        int len = 0, whitespace = 0;
        for(int i = 0; s[i] != '\0'; ++i) {
            ++len;
            if(s[i] == ' ')
                ++whitespace;
        }
        if(whitespace == 0)
            return s;

        s = (char* )realloc(s, sizeof(char) * (len  + 2 * whitespace + 1));
        s[len + 2 * whitespace] = '\0';

        int k = len + 2 * whitespace - 1;
        for(int i = len - 1; i >= 0; --i) {
            if(s[i] != ' '){
                s[k--] = s[i];
            }else {
                s[k--] = '0';
                s[k--] = '2';
                s[k--] = '%';
            }
        }
        return s;
    }
    ```