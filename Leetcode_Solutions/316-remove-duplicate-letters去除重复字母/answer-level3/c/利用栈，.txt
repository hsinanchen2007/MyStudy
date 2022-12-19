从字符串依次取一个字符，若当前栈为空或者大于栈顶字符（且栈中不存在该字符），就放入，否则小于栈顶元素，就查看栈顶元素在字符串后面有没有存在的，有的话就弹出，直到栈为空或字符串没有存在相同元素，然后放入新字符。

typedef char eType;
typedef struct {
    int cap;
    int top;
    eType *array;
}STACK;
int isEmpty(STACK *s)
{
    if (-1 == s->top) {
        return 1;
    }
    else {
        return 0;
    }
}
STACK *creatStack(int size)
{
    STACK *st = (STACK *)malloc(sizeof(STACK));
    st->cap = size;
    st->top = -1;
    st->array = (eType*)malloc(sizeof(eType)*size);
    return st;
}
void destoryStack(STACK *s)
{
    if (NULL != s) {
        free(s->array);
        free(s);
    }
    return;
}
void push(eType e, STACK *s)
{
    s->top++;
    s->array[s->top] = e;
    return;
}
eType pop(STACK *s)
{
    eType top;
    if (isEmpty(s)) {
        return -1;
    }
    top = s->array[s->top];
    s->top--;
    return top;
}
eType getTop(STACK *s)
{
    if (isEmpty(s)) {
        return -1;
    }
    return s->array[s->top];
}
void inverse(char *a,int len)
{
    for(int i=0;i<len/2;i++) {
        char temp;
        temp=a[i];
        a[i]=a[len-i-1];
        a[len-i-1]=temp;
    }
}
char * removeDuplicateLetters(char * s){
    int use[2000] = {0};
    int rec[2000] = {0};
    int len = strlen(s);
    char *res = (char *)malloc(2000);
    memset(res, 0, 2000);
    STACK *st = creatStack(2000);
    for (int i = 0; i < len; i++) {
        use[s[i]]++;
    }
    for (int i = 0; i < len; i++) {
        use[s[i]]--;
        if (isEmpty(st) || (getTop(st) < s[i] && !rec[s[i]])) {
            char cc = getTop(st);
            push(s[i], st);
            rec[s[i]] = 1;
            cc = getTop(st);
        }
        else {
            if (!rec[s[i]]) {
                char c = getTop(st);
                while ((!isEmpty(st)) && (getTop(st) > s[i]) && (use[getTop(st)] > 0)) {
                    rec[getTop(st)] = 0;
                    pop(st);
                }
                push(s[i], st);
                rec[s[i]] = 1;
                c = getTop(st);
            }
        }
    }
    int k = 0;
    while (!isEmpty(st)) {
        res[k] = getTop(st);
        pop(st);
        k++;
    }
    res[k] = '\0';
    int len1 = strlen(res);
    inverse(res, len1);
    return res;
}