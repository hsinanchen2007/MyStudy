### 解题思路
找规律：
根据题意，每个字母所在的位置与所在的行和列存在等式。例如numRows=4,则可以把m=2*numRows-2作为一个整体进行考虑，每行的字母又与这m个字母存在简单的行数关系，需要将第一行和最后一行单独考虑，因为这两行每个整体中只有一个字母，中间行则有至少一个字母。例如第i（数组下标i）行，第一个字母为s[n+i],第二个字母为s[n+m-i]。同时需要关注n+i和n+m-i的范围，避免s[n+i]越界访问。

### 代码

```c
char * convert(char * s, int numRows){
    int len = strlen(s);
    if (len < 1) {
        return "";
    }
    if (len <= numRows || len < 3 || numRows == 1) {
        return s;
    }
    int m = 2*numRows - 2;
    char *buf = (char*)malloc(len+1);
    memset(buf,'\0',len+1);
    int k = 0;
    for (int i = 0; i < numRows; i++) {
        int n = 0;
        int flag = 0;
        while (1) {
            n = m*(flag++);
            if (n+i > len - 1)
                break;
            if (i == 0) {
                buf[k++] = s[n];
            }else if (i == numRows-1) {
                buf[k++] = s[n+i];
            }else {
                buf[k++] = s[n+i];
                if (n+m-i > 0 && n+m-i < len)
                    buf[k++] = s[n+m-i];
            }
        }
    }
    return buf;
}
```