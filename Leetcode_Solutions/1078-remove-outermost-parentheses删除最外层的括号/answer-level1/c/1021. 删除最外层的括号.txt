### 解题思路
因为括号成对出现所以左右一定会相等，当相等的时候去除外边括号放入malloc里面。重复操作即可。主要缺点就是占用内存过大

### 代码

```c
char * removeOuterParentheses(char * S){

    char *q=S;
    char *x=malloc(sizeof(char)*1024*5);
    char *z=x;
    char *p=NULL;
    int r=0,l=0,num;
    while(*q!='\0')
    {   
        if(*q=='(')
        {
            l++;
        }else
        {
            r++;
        }
        if(l==r)
        {
            num=l+r-2;
            p=q-num;
            while(p!=q)
            {
                *z=*p;
                z++;
                p++;    
            }
            l=0;
            r=0;
        }
        *q++;
    }
    *z='\0';
    return x;
}
```