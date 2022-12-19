一开始考虑通过二进制字符串转换整数，然后计算转换次数，直接GG，有用例会超出整数范围，老老实实改回字符串处理。
思路如下：
1、特殊处理3个字符串："0","1","10"，分别返回1,0,1
2、其他场景的字符串做递归，分一下几种场景：
a、最后一个字符是'0'
   a1、没有进位计算，转换次数加一，不需要继续进位
   a2、有进位计算，转换次数加二，需要继续进位
b、最后一个字符是'1'
   b1、没有进位计算，转换次数加二，需要继续进位
   b2、有进位计算，转换次数加一，需要继续进位
此后将s的最后一个字符置为'\0'
递归终止条件： 
s长度为1, 
end1、s[0] 为'0',有进位，返回0
end2、s[0]为'0',无进位，返回1
end3、s[0]为'1',有进位，返回1
end4、s[0]为'1',无进位，返回0.

```
int StepFunc(char *s, bool needInc)
{
    int len = strlen(s);
    if (len == 1 && s[0] == '0') {
        return needInc ? 0 : 1;
    }
    
    if (len == 1 && s[0] == '1') {
        return needInc ? 1 : 0;
    }
    
    printf("%s, %d %d\n", s, len, needInc);
    int incCnt = 0;
    if (s[len - 1] == '0') {
        incCnt = needInc ? 2 : 1;
        needInc = needInc ? true : false;
    } else {
        incCnt = needInc ? 1 : 2;
        needInc = true;
    }
    s[len - 1] = '\0';
    
    return incCnt + StepFunc(s, needInc);
}

int numSteps(char * s){
    int len = strlen(s);
    if (strcmp(s, "0") == 0) {
        return 1;
    }
    
    if (strcmp(s, "1") == 0) {
        return 0;
    }
    
    if (strcmp(s, "10") == 0) {
        return 1;
    }
    bool needInc = strcmp(s, "10") <= 0 ? false : true;
    char *tmpS = (char *)malloc(len + 1);
    strcpy(tmpS, s);
    tmpS[len] = '\0';
    //printf("%s, %d\n", tmpS, needInc);
    int ret = StepFunc(tmpS, false);
    free(tmpS);
    return ret;
}
```

