初学者，比较规规矩矩😂😂

```

//入栈为字符串
typedef struct stack{
    char **array;
    int top;
}stack;

//栈初始化
void stackInit(stack *ps){
    ps->top=0;
    ps->array=NULL;
}
//入栈
void stackPush(stack *ps,char *input){
    int len=strlen(input);
    ps->array[ps->top]=malloc(sizeof(char)*(len+1));
    strcpy(ps->array[ps->top],input);
    (ps->top)++;
}

//出栈
char *stackPop(stack *ps){
    
    char *out=ps->array[ps->top-1];
    (ps->top)--;
    return out;

}
//判断栈空

int stackEmp(stack *ps){
    return (ps->top==0)? 1:0;
}


//尾部加字符
char *inchar(char *news,char a){
    int len=strlen(news);
    news=realloc(news,sizeof(char)*(len+2));
    news[len]=a;
    news[len+1]='\0';
    return news;
}

//反转字符串
char *rechar(char *news){
    int len=strlen(news);
    int i;
    for(i=0;i<len/2;i++){
        news[i]=news[i]^news[len-1-i];
        news[len-i-1]=news[i]^news[len-1-i];
        news[i]=news[i]^news[len-1-i];
    }
    return news;
}

//拼接字符串
char *stos(char *a,char *b){
    int len=strlen(a)+strlen(b)+1;
    a=realloc(a,sizeof(char)*len);
    strcat(a,b);
    b=malloc(sizeof(char)*len);
    strcpy(b,a);

    return b;
}


char * reverseParentheses(char * s){
    int lens=strlen(s);
    //设计一个字符串每次存入字母
    char *news=malloc(sizeof(char)*lens);
    news[0]='\0';

    //初始化栈
    stack *sq=malloc(sizeof(stack));
    stackInit(sq);
    sq->array=(char**)malloc(sizeof(char*)*lens);

    //存入出栈数据
    char  *out;
    //printf("初始化完成");
    //遍历打入数据
    int i;
    for(i=0;i<lens;i++){
        //遇到'('入栈news
        if(s[i]=='('){
            //printf("入栈时的news=%s\n",news);
            stackPush(sq,news);
            news[0]='\0';

        }
        //遇到')',先反转再接头
        else if(s[i]==')'){
            //printf("反转时的news=%s\n",news);
            news=rechar(news);
            out=stackPop(sq);
            news=stos(out,news);
        }

        else{
            news=inchar(news,s[i]);
            //printf("打入数据后的news=%s\n",news);
        }
    }

    return news;
}
```
