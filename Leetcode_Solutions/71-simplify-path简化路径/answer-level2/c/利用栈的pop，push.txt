### 解题思路
..看作pop，.不做操作，其他push

### 代码

```c
char * simplifyPath(char * path){
    char *p=strtok(path,"/");
    char stack[100][100];
    char *result=(char *)malloc(sizeof(char)*1000);
    memset(result,0,sizeof(result));
    int i=0;
    while(p!=NULL)
    {
        if(strcmp(p,"..")==0)
        {   
            if(i>=1)
                i--;
        }
        else if(strcmp(p,".")!=0)
        {
            strncpy(stack[i++],p,99);
        }
        p=strtok(NULL,"/");
    }
    result[0]='/';
    int count=1;
    for(int j=0;j<i;j++)
    {
        for(int k=0;k<strlen(stack[j]);k++)
            result[count++]=stack[j][k];
        result[count++]='/';
    }
    if(count>1)
        result[count-1]='\0';
    return result;
}
```