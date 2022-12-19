惭愧，提交三次才过关，粗心真的害死人
```

typedef struct Node
{
	char data;
	struct Node* pNext;
}NODE, * PNODE;

typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK, * PSTACK;

void init(PSTACK pS)
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	pS->pBottom = pS->pTop;
	pS->pTop->pNext = NULL;
}

bool isempty(PSTACK pS)
{
	if (pS->pTop == pS->pBottom)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void push(PSTACK pS, char val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;
}


bool pop(PSTACK pS, char* val)
{
	if (isempty(pS))
	{
		return false;
	}

	PNODE r = pS->pTop;
	*val = r->data;
	pS->pTop = pS->pTop->pNext;
	free(r);
	r = NULL;
	return true;
}

bool isValid(char* s) {
	int i = 0;
	char a;
	STACK S;
	init(&S);
	while (s[i] != NULL)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			push(&S, s[i]);
		}
		else if (s[i] == ')')
		{
			pop(&S, &a);
			if (a != '(')
			{
				return false;
			}
		}
		else if (s[i] == '}')
		{
			pop(&S, &a);
			if (a != '{')
			{
				return false;
			}
		}
		else if (s[i] == ']')
		{
			pop(&S, &a);
			if (a != '[')
			{
				return false;
			}
		}

		i++;
	}
	if (isempty(&S))
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
```
