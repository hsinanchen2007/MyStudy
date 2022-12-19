### 解题思路
写个快速排序练练手

### 代码

```c
//快速排序
void sortFast(char* Str,int Low,int High)
{
    if(Low<High)
    {   
        char temp=Str[Low];
        int i=Low,j=High;
        while(i!=j)
        {
            while(i<j&&Str[j]>temp)--j;
            if(i<j)Str[i++]=Str[j];
            while(i<j&&Str[i]<temp)++i;
            if(i<j)Str[j--]=Str[i];
            Str[i]=temp;
        }
        Str[i]=temp;
        sortFast(Str,Low,i-1);
        sortFast(Str,i+1,High);        
    }
}
//测字符串长度
int length(char* Str)
{
    int result=0;
    while(*Str!='\0')
    {
        ++result;
        ++Str;
    }
    return result;
}

bool isAnagram(char * s, char * t){
     //两个都是空串
    if(s==0&&t==0)return true;
    //只有一个是空串
    if(s==0||t==0)return false;
    //测量两个串长度
    int lengthS=length(s);
    int lengthT=length(t);
    if(lengthS!=lengthT)return false;
    //排序
    sortFast(s,0,lengthS-1);
    sortFast(t,0,lengthT-1);
    //对比
    while(*s!='\0'&&*t!='\0')
    {
        if(*s!=*t)return false;
        ++s;
        ++t;
    }
    return true;
}
```