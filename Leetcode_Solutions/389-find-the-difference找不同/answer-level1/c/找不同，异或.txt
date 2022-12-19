### 解题思路
异或这个运算还是很牛的：0与任何数异或，该数值不变，出现相同就抵消掉

### 代码

```c
char findTheDifference(char * s, char * t){
    char res=0;
    int len,i;
    len=strlen(s);
    if(len==0){
        return t[0];
    }
    for(i=0;i<len;i++){
        res=res^s[i];
        res=res^t[i];
    }
    res=res^t[len];
    return res;
}
```