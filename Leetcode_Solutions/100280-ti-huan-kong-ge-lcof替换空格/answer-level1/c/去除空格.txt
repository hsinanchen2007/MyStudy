### 解题思路
把*和++分开写

### 代码

```c
char* replaceSpace(char* s){

    int spaceNum=0,num=0;
    char *iter=s;
    while(*iter!='\0')
    {
        if(*iter==' ')
            ++spaceNum;
        else
            ++num;
        ++iter;
    }

    char* newS=(char*)malloc(sizeof(char)*(num+1+spaceNum*3));

    char *newIter=newS;iter=s;
    while(*iter!='\0')
    {
        if(*iter==' ')
        {
            *newIter='%';
            ++newIter;
            *newIter='2';
            ++newIter;
            *newIter='0';
            ++newIter;
            ++iter;
            continue;
        }
        *newIter=*iter;
        ++newIter;++iter;
    }
    *newIter=*iter;
    return newS;
}
```