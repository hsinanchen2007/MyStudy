### 解题思路
# 主要问题是字符串末尾出现空格或连续空格的问题，利用两个数字计数器即可

### 代码

```c
int lengthOfLastWord(char * s){
int count=0;
int len;
len=strlen(s);
if(len==0) return 0;
else
{
    int i,count1=0,count2=0;
    for(i=0;i<len;i++)
    {
        if(s[i]==' '&&count1!=0)
        {
            count2=count1;
            count1=0;
        }
        else if(s[i]==' '&&count1==0) continue;
        else count1++;
    }
    if(count1==0) return count2;
    else return count1;
}
}
```