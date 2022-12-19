### 解题思路
此处撰写解题思路
将罗马数字对应的小写字母定义为其对应的整数，方便接下来的运算；
定义一个字符指针p指向s,用来遍历s的字符串；指针next指向p的下一个字符，用来判断是否出现罗马数字中小的数字在大的数字的右边；
while用来遍历指针p所指向的字符串；前三个判断语句用于判断出现的六种特殊规则并做相应的运算，最后一个判断则用于正常规则排序的判断并做相应的运算；判断完之后就使指针p指向下一个字符；
### 代码

```c
int romanToInt(char * s){
int i=1,v=5,x=10,l=50,c=100,d=500,m=1000;
int sum=0;
char *p=s;
char *next=NULL;
while(*p)
{
    next=p+1;
    if((*p=='I' && *next=='V')||(*p=='I' && *next=='X'))
        sum=sum-i;
    else if((*p=='X' && *next=='L')||(*p=='X' && *next=='C'))
        sum=sum-x;
    else if((*p=='C' && *next=='D')||(*p=='C' && *next=='M'))
        sum=sum-c;
    else
    {
        if(*p=='I')
            sum=sum+i;
        else if(*p=='V')
            sum=sum+v;
        else if(*p=='X')
            sum=sum+x;
        else if(*p=='L')
            sum=sum+l;
        else if(*p=='C')
            sum=sum+c;
        else if(*p=='D')
            sum=sum+d;
        else if(*p=='M')
            sum=sum+m;
    } 
    p++;
}
return sum;
}
```