### 解题思路
题目绕来绕去最后意思就是：若两串相等则返回-1，否则返回较长的串

### 代码

```c
int findLUSlength(char * a, char * b){
    int alen=strlen(a),blen=strlen(b);
    if (strcmp(a,b)==0)return -1;
        return alen>blen?alen:blen;
}
```