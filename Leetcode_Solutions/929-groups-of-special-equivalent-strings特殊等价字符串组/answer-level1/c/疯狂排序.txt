由题意可知每个字符串只要奇偶位置包含的字母相同，即一个集合
可以先对每个字符串进行处理，把奇偶位置的字母拿出分别排序，然后合并
再对处理完的字符串进行排序
相邻的字符串如果相等就是一个集合，不等就是另一个集合，即可得出集合数量
代码如下
paixu函数对每个字符串进行处理
```
int cmp(const void*a,const void*b)
{
    return *(char*)a-*(char*)b;
}
int cmpstr(const void*a,const void*b)
{
    return strcmp(*(char**)a,*(char**)b);
}
char*paixu(char*s)
{
    int i;
    int len=strlen(s);
    int countodd=0;
    int counteven=0;
    char*odd=(char*)malloc(sizeof(char)*(len+1));
    char*even=(char*)malloc(sizeof(char)*(len+1));
    for(i=0;i<len;i++)
    {
        if(i%2==0)
        {
            even[counteven++]=s[i];
        }
        else
        {
            odd[countodd++]=s[i];
        }
    }
    even[counteven]=0;
    odd[countodd]=0;
    qsort(even,counteven,sizeof(char),cmp);
    qsort(odd,countodd,sizeof(char),cmp);
    for(i=0;i<counteven;i++)
    {
        s[i]=even[i];
    }
    for(i=counteven;i<counteven+countodd;i++)
    {
        s[i]=odd[i-counteven];
    }
    s[i]=0;
    return s;
}
int numSpecialEquivGroups(char ** A, int ASize){
    int i,j;
for(i=0;i<ASize;i++)
{
    A[i]=paixu(A[i]);
}
qsort(A,ASize,sizeof(A[0]),cmpstr);
int count=1;
for(i=1;i<ASize;i++)
{
    if(strcmp(A[i],A[i-1])!=0)
    {
        count++;
    }
    if(i==ASize-1)
    {
        continue;
    }
}
return count;
}
```
