这个题思路简单，但是用c语言写起来很复杂
先定义一个结构体存域名和其访问次数
开辟一个该结构体类型的数组用来存放上述信息
接下来开始遍历题目种给定的数组
每次先把字符串开头的数字存入结构体，再**逆序**对字符串进行遍历（有后缀这种感觉），遇到'.'就把前面的字符串保存，开始查找结构体数组中有没有和他相同的字符串，有就累计访问次数，没有就新加入结构体数组。所有字符串存储完毕后将结果给目标数组并返回（将结构体数组种的字符串逆序输出给目标数组）
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 char* itoa(int x)
 {
     char *str;
     int i;
     str=(char*)malloc(sizeof(char)*10);
     int count=0;
     int cn=0;
     int num[10];
     if(x==0)
     {
         str[0]='0';
         str[1]=0;
         return str;
     }
     while(x!=0)
     {
         num[count++]=x%10;
         x/=10;
     }
     for(i=count-1;i>=0;i--)
     {
         str[cn++]=num[i]+'0';
     }
     str[cn]=0;
     return str;
 }
 typedef struct
 {
     char data[110];
     int count;
 }node;
char ** subdomainVisits(char ** cpdomains, int cpdomainsSize, int* returnSize){
    int i,j,k;
    node num[301];//存储字符串和次数的数组
    char**jg=(char**)malloc(sizeof(char*)*301);
    for(i=0;i<301;i++)
    {
        jg[i]=(char*)malloc(sizeof(char)*102);
    }
    int count=0;//临时计数
    int cn=0;//结构体数组大小
    int cc=0;//结果数组大小
    char temp[101];//存储域名
    int tempnum;//存储次数
    int len;
    int produce=1;
    int start;
    int templen;
for(i=0;i<cpdomainsSize;i++)
{
    tempnum=0;
    count=0;
    produce=1;
    len=strlen(cpdomains[i]);//量取字符串长度
    for(j=0;j<len;j++)
    {
        if(cpdomains[i][j]==' ')//遇到空格停止
        {
            start=j+1;//记录域名开始的位置
            break;
        }
        temp[count++]=cpdomains[i][j];//记录数字
    }
    for(j=count-1;j>=0;j--)//逆序计算数字
    {
        tempnum+=(temp[j]-'0')*produce;
        produce*=10;
    }
    count=0;
    for(j=len-1;j>=start;j--)//逆序开始记录
    {
        if(j==start)//如果是最后一位数字
        {
            temp[count++]=cpdomains[i][j];//加入
            temp[count]=0;//结尾用0封住
            for(k=0;k<cn;k++)//在数组里查找
            {
                if(strcmp(num[k].data,temp)==0)//如果查到有相同的字符串
                {
                    num[k].count+=tempnum;//次数累加
                    break;
                }
            }
            if(k==cn)//没有就新增
            {
                strcpy(num[cn].data,temp);
                num[cn].count=tempnum;
                cn++;
            }
            continue;
        }
        if(cpdomains[i][j]=='.')
        {
            temp[count]=0;
            for(k=0;k<cn;k++)
            {
                if(strcmp(num[k].data,temp)==0)
                {
                    num[k].count+=tempnum;
                    break;
                }
            }
            if(k==cn)
            {
                strcpy(num[cn].data,temp);
                num[cn].count=tempnum;
                cn++;
            }
            temp[count++]='.';//把0改成'.',方便接着记录
            continue;
        }
        temp[count++]=cpdomains[i][j];//记录
    }
}
char*tempstr=(char*)malloc(sizeof(char)*5);
for(i=0;i<cn;i++)
{
    count=0;
    tempstr=itoa(num[i].count);//将数字转化成字符串
    strcpy(jg[cc],tempstr);//存入结果数字
    len=strlen(tempstr);
    count=len;
    jg[cc][count++]=' ';
    templen=strlen(num[i].data);
    for(j=templen-1;j>=0;j--)
    {
        jg[cc][count++]=num[i].data[j];//将字符串逆序存入结果数组
    }
    jg[cc][count]=0;//用0封住字符串
    cc++;
}
*returnSize=cc;
return jg;
}
```
