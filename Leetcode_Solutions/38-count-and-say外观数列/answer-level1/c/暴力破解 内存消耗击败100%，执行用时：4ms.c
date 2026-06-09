### 解题思路
暴力破解

### 代码

```c
char * countAndSay(int n){
    int i;
    char *re=calloc(5000,sizeof(char));//注意空间要足够大
    char *s=calloc(5000,sizeof(char));
    s[0]='1';s[1]='\0';//初始化
    int k=0,cnt=0;//cnt指的是有几个相同的数；k代表re的下标
    int p=2;
    while(p++<=n){
        cnt=1;
        k=0;//k的值初始化
        for(i=0;i<strlen(s);i++){
        	cnt=1;
            while(i<strlen(s)-1&&s[i]==s[i+1]){//相等，且s[i]这个元素不是最后一个元素
                cnt++;//相同元素数+1
                i++;
            }
            re[k]=cnt+'0';//表示数量
            k++;
            re[k]=s[i];//多个相同元素的最后一个元素;无相同元素时，re[k]就是该元素
            k++;
            
        }
        re[k]='\0';//re代表的是每次处理之后的结果，也是下一次循环要处理的字符串
        strcpy(s,re);//注意一定不要用等号!!一定不要用等号!!一定不要用等号!!重要的事情说三遍
    }
    return s;
}
```