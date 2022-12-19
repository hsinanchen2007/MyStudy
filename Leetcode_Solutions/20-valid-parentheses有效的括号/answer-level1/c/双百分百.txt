参考了官方和各位大佬的题解，效率和内存占用方面的表现还是很不错的。
```
bool isValid(char * s){
    int len=strlen(s);
    if(len==1){
        return false;
    }
    char *stack=(char *)calloc(len+1,sizeof(char));
    int i=0,top=0;
    for(i=0;i<len;i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{'){
            stack[top]=s[i];
            top++;
        }
        else if((s[i]==')'&&top!=0&&stack[top-1]=='(')||(s[i]==']'&&top!=0&&stack[top-1]=='[')||(s[i]=='}'&&top!=0&&stack[top-1]=='{')){    //注意top!=0这个条件，如果等于零也是不行的，没有这个条
            top--;                          //会字符数组索引溢，除了这三种情况直接返回false,还要注意
        }                                   //top!=0这个条件要在stack[top-1]前面！
        else{
            return false;
        }
    }
    //如果循环最后结束了，进行一下判断
    if(top==0){
        return true;
    }
    else{
        return false;
    }     
}
```
![image.png](https://pic.leetcode-cn.com/ff9d63b5a45f6be1e7ca247c93c379bbe2a291ae5455db11f2e8fc4d402f083c-image.png)
