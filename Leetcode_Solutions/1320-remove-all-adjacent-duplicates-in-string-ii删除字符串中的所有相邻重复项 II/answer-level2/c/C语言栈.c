typedef struct STACKNODE_S
{
char data; //可以根据实际应用，调整data的数据类型
int count;
struct STACKNODE_S *pNext;
}STACKNODE_S, STACK;

int g_stackLen = 0;

void Pop(STACK *stack, char *popchar, int *count)
{
STACKNODE_S *pstTemp = NULL;

if (stack->pNext == NULL)
{
    *popchar = '\0';
    return ;
}

pstTemp = stack->pNext;
stack->pNext = pstTemp->pNext;
*popchar = pstTemp->data;
*count = pstTemp->count;
    
g_stackLen = g_stackLen-pstTemp->count;

free(pstTemp);
   
return ;
}

void Push(STACK *stack, char pushChar, int count)
{
STACKNODE_S *pstNewNode = (STACKNODE_S *)malloc(sizeof(STACKNODE_S));

pstNewNode->data = pushChar;    
pstNewNode->count = count;
pstNewNode->pNext = stack->pNext;
stack->pNext = pstNewNode;
    
g_stackLen = g_stackLen+count;

return;
}

char * removeDuplicates(char * s, int k){
    
    char *pst = s;    
    STACK stack = {0};
    char popchar = '\0';
    int count = 0;
    int i ;
    char *res ;
    
    if (k > strlen(s))
    {
        return NULL;
    }

    while(*pst != '\0')
    {
        Pop(&stack, &popchar, &count);
        if (popchar == '\0')
        {
            Push(&stack, *pst, 1);
            pst++;
            continue;
        }
        
        if (popchar == *pst)
        {
            if (count == k - 1)
            {
                ;
            }
            else
            {                
                Push(&stack, *pst, count+1);                
            }            
        }
        else
        {
            Push(&stack, popchar, count);
            Push(&stack, *pst, 1);
        }
                
        pst++;
    }            
        
    res = (char *)malloc(sizeof(char) * (g_stackLen+1));
    res[g_stackLen] = '\0';
    
    i =  g_stackLen - 1;
           
    Pop(&stack, &popchar, &count);
    
    while (popchar != '\0' && i >= 0)
    {         
        for (int j = 0; j < count; j ++)
        {
            res[i-j] = popchar;
        }        
        
        i = i - count;
        
        Pop(&stack, &popchar, &count);
    }
        
    return res;
        
}