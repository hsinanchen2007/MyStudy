遍历字符串，统计出'b','a','l','o','n'的个数，根据短板效应返回最小值（'l'和'o'的个数应除以2）。
```c
int maxNumberOfBalloons(char * text){
    unsigned short index=0,b=0,a=0,l=0,o=0,n=0;
    while(text[index]!=0){
        switch (text[index]){
            case 'b':b++;break;
            case 'a':a++;break;
            case 'l':l++;break;
            case 'o':o++;break;
            case 'n':n++;break;
        }
        index++;
    }
    index=b>a?a:b;
    index=index>(l/2)?(l/2):index;
    index=index>(o/2)?(o/2):index;
    return index>n?n:index;
}
```