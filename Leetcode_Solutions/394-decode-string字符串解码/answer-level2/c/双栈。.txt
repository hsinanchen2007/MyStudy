### 解题思路
水平太菜了，写了很久才写出来。。。。。。。

### 代码

```c

#define MAX_ITEMS       10001

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

//字符串翻转
void reverse(char *str)
{
	char *end = str;
	char tmp;
	if(str)
	{
		while(*end)
		{
			end++;
		}
		end--;
		while(str<end)
		{
			tmp = *str;
			*str++ = *end;
			*end-- = tmp;
		}
	}
}



char * decodeString(char * s){


Stack *numStack = stack_create();
Stack *alpStack = stack_create();
char str[10001];
int i = 0;

char *result1 = malloc(10001);
memset(result1, '\0', 10001);
int k = 0;
char *p =s;
int cnt = 0;
char digti[10]={0};
memset(digti,'\0',10);
int dcnt = 0;
while(*p !='\0')
{
    cnt++;
    
	if(isalpha(*p)) {
        if(stack_empty(numStack))
        {
            result1[k++] = *p;
        }
        else
        {
            stack_push(alpStack,*p);
        }
	}

	else if (isdigit(*p)) {
        digti[dcnt++] = *p;
        digti[dcnt]='\0';
	}
	else if(*p == '[') {
        //转换dig变成栈中的值。
        int num = atoi(digti);
        printf("%d", num);
   	    stack_push(numStack,num);
        dcnt = 0;
		stack_push(alpStack,*p);
	}
	else if(*p == ']')   
	{
		while(!stack_empty(alpStack))
		{
			char c = stack_get_top(alpStack);
			if(c=='[') {
   			    break;
			}
			str[i++] = c;
			stack_pop(alpStack);
		}
		stack_pop(alpStack);
        str[i] = '\0';	

		int num = stack_get_top(numStack);
		stack_pop(numStack);
		reverse(str);
        char result[10001]={0};
		for(int i = 0; i < num ; i++)
		{
			strcat(result,str);
		}
		memset(str,'\0',10001);
		i = 0;
        if(!stack_empty(numStack))
        {
            char *tmp = result;
            while(*tmp !='\0')
            {
                stack_push(alpStack,*tmp);
                tmp++;			
            }
            
        }
        else
        {
       	    strcat(result1,result);
            k+=strlen(result);
        }
       
	}
    
	p++;
}
stack_destroy(&numStack);
stack_destroy(&alpStack);
return result1;


//算法  解析到数字入数字栈
//解析到【入栈，字母，入栈
//3/2
//[a[c
//遇到]
//从栈顶一直取到[,与数字进行倍数后入栈.  比如 c  ->   cc,倍数后再入栈
//[acc 
//遇到】
//取出 "acc" 变成  accaccacc

//情况2
//2[abc]3[cd] ef

//遇到字母入栈 ef遇到数字
//[abcabccdcdcdef
}
//
```