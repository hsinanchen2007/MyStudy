


//每当插入一个元素的时候
//先看下它的元素和之前的元素是否配对
//如果配对,移除元素，否则加入元素
```
//定义
typedef struct {
    char *bracket;
    int count ; //当前括号
    int size; //数据大小

} Bracket;
```

```
//创建栈
Bracket *CreateBracket( int n)
{
    Bracket *b;
    b = (Bracket *)malloc( sizeof(Bracket) );
    b->bracket = (char *)malloc( sizeof(char) * n);
    b->count = 0;
    b->size = n;
    return b;
}
```
```
// 看一眼
char peek(Bracket *b)
{
    if (b->count == 0 ) return ' ';
    char out = b->bracket[b->count-1];
    return out;

}
```

```
//移除
char pop(Bracket *b)
{
    b->count-=1;
    char out = b->bracket[b->count];
    return out;

}
```

```
//增加
bool add( Bracket *b, char ele )
{
    if (b->count == b->size ) return false;
    b->bracket[b->count] = ele;
    b->count+=1;
    return true;
}
```
检查是否配对
```
bool checkMate( char a, char b){
    if ( a == '(' && b == ')') return true;
    if ( a == '{' && b == '}') return true;
    if ( a == '[' && b == ']') return true;

    return false;

}
```
```
bool isValid(char * s){

    int slen = strlen(s);
    Bracket *b = CreateBracket(slen);

    char ele;
    char tmp;
    int i ;
    for ( i = 0; i < slen; i++){
        ele = s[i];
        tmp = peek( b );
        if (checkMate( tmp, ele )){
            pop(b);
        } else{
            add(b, ele);
        }
        
    }
    if ( b->count != 0) return false;
    return true;

}
```