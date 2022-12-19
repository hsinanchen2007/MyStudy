### 解题思路
此处撰写解题思路

### 代码

```c
char* replaceSpaces(char* S, int length){

int j=0;
int i;

for(i=0;i<length;i++)
{
    if(S[i]==' ')
    {
        j++;    
    }
}
int len=length+2*j;

if(strlen(S)>len)
    S[len]='\0';
    len--;
for(i=length-1;i>=0;i--)
{
    if(S[i]!=' ')
    {
        S[len--]=S[i];
    }
    else{
        S[len--]='0';
        S[len--]='2';
        S[len--]='%';
    }
}
    return S;
}

```