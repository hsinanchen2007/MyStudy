### 解题思路
此处撰写解题思路

### 代码

```c
char * addBinary(char * a, char * b){
    int length_a = strlen(a);
    int length_b = strlen(b);
    int length = length_a>length_b?length_a+2:length_b+2;

    char *result = (char*)malloc(length*(sizeof(char)));
    memset(result,'\0',length); //初始化结果数组
    length -= 2;
    while(length_a>0 || length_b>0){
       int an=length_a>0?a[--length_a]-'0':0;//相当于两个指针指向a，b的尾部；短的那一个直接用0来补充
       int bn=length_b>0?b[--length_b]-'0':0;
        if(an+bn+result[length]+'0'=='1') result[length--]='1';     //以下都是分类处理过程，其实有更简化的分类；
        else if(an+bn+result[length]+'0'=='0') result[length--]='0';
        else if(an+bn+result[length]+'0'=='2') {result[length--]='0';result[length]='1'-'0';}
        else {result[length--]='1';result[length]='1'-'0';}

    }
    result[0]+='0';
//  判断result[0]是否产生进位
    if(result[0]!='1')
        result++; 
    return result;
}
```