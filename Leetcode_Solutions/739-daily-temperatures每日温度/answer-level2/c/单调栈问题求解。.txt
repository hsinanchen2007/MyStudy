### 解题思路
注意边界问题，尤其是自定义的库。

### 代码

```c
#define MAX_ITEMS       300001


typedef enum{FALSE, TRUE} boolean;

typedef struct
{
    int items[MAX_ITEMS];
    int top;
} Stack;

Stack *stack_create(void)
{
    Stack *s = malloc(sizeof(Stack));
    if(NULL == s)
    {
        return NULL;
    }
    else
    {
        s->top = 0;
        return s;
    }
}
void stack_destroy(Stack **s)
{
    if(NULL != *s)
    {
        free(*s);
    }
}

boolean stack_empty(Stack *s)
{
    if(s->top == 0) return TRUE;
    else return FALSE;
}

boolean stack_full(Stack *s)
{
    if(s->top == MAX_ITEMS) return TRUE;
    else return FALSE;
}

boolean stack_push(Stack *s, int item)
{
    if(stack_full(s)) return FALSE;
    else
    {
        s->items[s->top] = item;
        s->top++;
        return TRUE;
    }
}

int stack_pop(Stack *s)
{
    if(stack_empty(s)) return 0;
    else
    {
        s->top--;
        return s->items[s->top];
    }
}

int stack_get_top(Stack *s)
{
    if(stack_empty(s)) return 0;
    else
    {
        return s->items[s->top - 1];
    }
}

void stack_print(Stack *s)
{
    int top = s->top;

    printf("Stack : ");
    while(top)
    {
        printf("%d ", s->items[--top]);
    }
    printf("\n");
}


int* dailyTemperatures(int* T, int TSize, int* returnSize){
	//单调递减栈解决问题。
	if(T==0 || TSize == 0) {
		*returnSize = 0;
	    return 0;
	}
	Stack * st = stack_create();
	int *ret = malloc(sizeof(int)*TSize);
    memset(ret, 0, sizeof(int)*TSize);
	int pos = 0;
	for(int i = 0; i < TSize;i++) {
       if(stack_empty(st)){
	       stack_push(st, i);
	   }
	   int stacktop = stack_get_top(st);
       if(!stack_empty(st) && T[i] > T[stacktop]){
		   while(!stack_empty(st) && T[i] > T[stacktop])
		   {
			   ret[stacktop] = i - stacktop;
			   stack_pop(st);
			   stacktop = stack_get_top(st);
		   }
	   }
	   stack_push(st,i);
	}
	
	
	stack_destroy(&st);
	*returnSize = TSize;
    return ret;
}
```