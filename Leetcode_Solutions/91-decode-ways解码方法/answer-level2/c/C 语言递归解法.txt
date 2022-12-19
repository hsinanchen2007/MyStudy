
### 代码

```c
void fuc(char* s,int* count)
{
    char* p = s;
    for(;*(p+1)!='\0';p++)
    {
        int a = ((int)*p-48) * 10 +  ((int)*(p+1)-48); // 判断两个字符连接起来是否大于26
        if(a<=26) // 如果小于26
        {
            *count = *count+1;  //解码方法+1
            if(*(p+2)!='\0')
            {
                fuc(p+2,count); // 将剩下字符串重复以上过程
            }
        }
    }
}

int numDecodings(char * s){
    int len = strlen(s);
    int count = 1;
    int i;
    for(i=0;i<len;i++) // 处理字符串中含有的"0" 注：字符串中的"0"只能于"1"或"2"拼接成10或20，不能单独成为一个字符
    {
        if(s[i]=='0')
        {
            if(i==0) // 如果第一个字符为0直接返回0
            {
                return 0;
            }
            else if(s[i-1]=='1'|| s[i-1]=='2') //如果"0"前面为1或2
            {
                s[i-1] = s[i] = 'a'; // 将这两个字符都置为"a"，目的为了防止递归受到"0"字符影响多加了方法种类
            }
            else
            {
                return 0; // 如果"0"前面不为1或2，返回0
            }
        }
    }
    fuc(s,&count); // 调用递归
    return count; // 返回结果
}
```