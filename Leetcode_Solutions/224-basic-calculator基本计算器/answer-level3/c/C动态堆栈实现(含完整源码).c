算法的思路是非常简单的，就是考察对栈的应用。
先把字符压栈(S1)，当遇到")"字符的时候，就开始弹出栈，直到遇到"("字符为止。
把弹出来的内容压到另外的一个栈中(S2)，然后运算这个栈---这个也很简单，就把内容一次弹出来，根据是符号还是数值，做个运算，运算的结果，在压入第一个堆栈中(S1)。

看了下，使用C语言来写，需要自己去实现一个堆栈，这个本身不难。
但是，这道题的测试案例过于变态，最后的一个测试例子，字符数为21万，导致采用静态数组做堆栈数据区的话，使用的内存会过高（实际测试了下，定了一个20万大小的固定数组，内存使用136M）。
![lc3.png](https://pic.leetcode-cn.com/2ed2d0d0c4f9c0b211b3fe690311f0212de92d6a939faadc455bb88bacebd5cf-lc3.png)
![lc1.png](https://pic.leetcode-cn.com/530eecda312a224f30a62d8b5d6b22571a1b493cba6faee757587fb85126b45e-lc1.png)

为了解决这个问题，需要把堆栈的数据去写成动态的双向链表。实际测试，最终的内存消耗为36M，但是时间消耗上去了。
相比C++的stack库，效能还是有待优化。
![lc2.png](https://pic.leetcode-cn.com/20334adc7782d84ced708be00d2b54865f6e366822daa1bea84963f5c5a850bd-lc2.png)

附上完整代码如下：
```
#define STACK_MAX 200000

enum ElmType {  //元素类型
    VALUE,
    SYM
};

typedef struct tagElm  //元素
{
    int val;
    char type;
    struct tagElm *pre;
    struct tagElm *next;    
}Element;

typedef struct tagStack {
    int index;
    Element *data;   //当前元素指针
}Stack;

int IsFull(Stack *st) 
{
    return (st->index == STACK_MAX) ? 1 : 0;
}

int IsEmpty(Stack *st)
{
    return (st->index == 0) ? 1 : 0;
}

//初始化
void IniStack(Stack *st)
{
    st->index = 0;
    st->data = NULL;
}

//入栈
int Push(Stack *st, int c, char type)
{
    if (IsFull(st)) {
        return 0;
    }
    Element * el = (Element *)malloc(sizeof(Element));
    el->type = type;
    el->val = c;
    el->next = NULL;
    if(st->index == 0) {
        el->pre = NULL;
        st->data = el;
    } else {
        st->data->next = el;
        el->pre = st->data;
        st->data = el;
    }
    st->index++;
    return 1;
}

//出栈
int Pop(Stack *st, int *c, char *et)
{
    if(IsEmpty(st)) {
        return 0;
    }
    *c = st->data->val;
    *et = st->data->type;
    Element *tmp = st->data;
    if(st->index > 1) {
        st->data = st->data->pre;
        st->data->next = NULL;
    } else {
        st->data = NULL;
    }    
    free(tmp);
    st->index--;
    return 1;
}

void FreeStack(Stack *st)
{
    int val;
    char type;
    while (!IsEmpty(st))
    {
        Pop(st, &val, &type);
    }
}

int CalcStack(Stack *st)
{
    int res = 0;
    int tmp = 0;
    char et = VALUE;
    char sym = '+';
    while (Pop(st, &tmp, &et) == 1) {
        if(et == SYM && (tmp == '+' || tmp == '-')) {
            sym = (char) tmp;
        } else {
            if(sym == '+') {
                res += tmp;
            } else {
                res -= tmp;
            }
        }
    }
    return res;
}

int calculate(char * s){
    int i, intLen = 0, elTmp;
    int len = strlen(s);
    char et = VALUE;
    char intTmp[30] = {0};
    Stack * st = (Stack *)malloc(sizeof(Stack));
    Stack * stTmp = (Stack *)malloc(sizeof(Stack));
    IniStack(st);
    IniStack(stTmp);  
    for ( i = 0; i < len; i++)
    {
        if (s[i] == '(' || s[i] == '+' || s[i]=='-') {  
            Push(st, s[i], SYM);
        } else if (s[i] == ' ') {  //如果是空格，则跳过
            continue;
        } else if (s[i] == ')') {  //如果是)，则计算前面的一个小的运算结构，再回压堆栈
            while (Pop(st, &elTmp, &et)) {
                if (elTmp == '(' && et == SYM) {
                    break;
                }
                Push(stTmp, elTmp, et);
            }
            elTmp = CalcStack(stTmp);           
            Push(st, elTmp, VALUE);
        } else {    //处理数值
            intTmp[intLen++] = s[i];
            if((i+1 == len) || (s[i+1] < '0' || s[i+1] > '9')) {
                Push(st, atoi(intTmp), VALUE);
                intLen = 0;
                memset(intTmp, 0 ,10);
            }
        }        
    }
    while (Pop(st, &elTmp, &et)) {  //计算最后的表达式
        Push(stTmp, elTmp, et);
    }    
    elTmp = CalcStack(stTmp);
    FreeStack(st);
    free(st);
    FreeStack(stTmp);
    free(stTmp);
    return elTmp;
}
```

