使用两个栈，一个栈保存(，一个栈保存*；
遍历字符串，遇到右括号，先去(栈中，弹出(，如果为空，则再去*栈中弹出*；
字符串遍历完之后，再处理(栈和*栈；
技术点：(在字符串中的位置，要小于*在字符串中的位置，否则直接报错。
typedef struct STACKNODE_S
{
char data; //可以根据实际应用，调整data的数据类型
int index; /* 字符在字符串中的位置 */
struct STACKNODE_S *pNext;
}STACKNODE_S, STACK;

void Pop(STACK *stack, STACKNODE_S *popnode)
{
STACKNODE_S *pstTemp = NULL;
char popchar = 0;

if (stack->pNext == NULL)
{
    popnode->data = '\0';
    return ;
}

pstTemp = stack->pNext;
stack->pNext = pstTemp->pNext;

popnode->data = pstTemp->data;
popnode->index = pstTemp->index;

free(pstTemp);

return ;

}

void Push(STACK *stack, char pushChar, int index)
{
STACKNODE_S *pstNewNode = (STACKNODE_S *)malloc(sizeof(STACKNODE_S));

pstNewNode->data = pushChar;
pstNewNode->index = index;
pstNewNode->pNext = stack->pNext;
stack->pNext = pstNewNode;

return;
}

bool checkValidString(char * s){
    STACK stleft;
    STACK ststar;
    STACKNODE_S stleftpopnode;
    STACKNODE_S ststarpopnode;
    char popleftchar = '\0';
    char popstartchar = '\0';
    
        
    memset(&stleft, 0, sizeof(STACK));
    memset(&ststar, 0, sizeof(STACK));
    
    if(*s == '\0')
    {
        return true;
    }
    
    for(int i = 0; i < strlen(s); i ++)
    {
        if(s[i] == '(')
        {
            Push(&stleft, s[i], i);
        }
        else if (s[i] == '*')
        {
            Push(&ststar, s[i], i);
        }
        else if (s[i] == ')')
        {
            Pop(&stleft, &stleftpopnode);
            if(stleftpopnode.data == '\0')
            {
                Pop(&ststar, &ststarpopnode);
                if(ststarpopnode.data == '\0')
                {
                    return false;
                }
            }
        }        
    }
    
    Pop(&stleft, &stleftpopnode);
    Pop(&ststar, &ststarpopnode);
    
    while(stleftpopnode.data != '\0')
    {        
        if (ststarpopnode.data == '\0')
        {
            return false;
        }
        
        if(stleftpopnode.index < ststarpopnode.index)
        {
            Pop(&stleft, &stleftpopnode);
            Pop(&ststar, &ststarpopnode);
        }        
        else
        {
            return false;
        } 
    }
    
    Pop(&stleft, &stleftpopnode);
    if(stleftpopnode.data != '\0')
    {
        return false;
    }

    return true;
}

