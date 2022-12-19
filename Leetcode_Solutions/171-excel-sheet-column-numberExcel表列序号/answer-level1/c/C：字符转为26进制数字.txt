思路：
A表示1，则字符转化规则 num = char - ‘A’ + 1,
转化后一次遍历字符数组，迭代加得到结果
```
int titleToNumber(char * s){
    int num;
    int ret = 0;
    for(int i = 0; i < strlen(s); i++){
        num = s[i] - 'A' + 1;
        ret = ret * 26 + num;
    }
    return ret;
}
```
