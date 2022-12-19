### 解题思路
上代码

### 代码

```c
typedef struct stack {
	int *items;
	int maxSize;
	int top;
} Stack;

void initializeStack (Stack * ps, int maxSize) {
	int *items = (int *) malloc (sizeof(int) * maxSize);
	ps->top = 0;
	ps->maxSize = maxSize;
	ps->items = items;
}

bool fullStack (const Stack * ps) {
	return ps->top == ps->maxSize;
}

bool emptyStack (const Stack * ps) {
	return ps->top == 0;
}

bool push (int item, Stack * ps) {
	if (ps->top == ps->maxSize) {
		return false;
	} else {
		ps->items[ps->top++] = item;
		return true;
	}
}

bool pop (int * pitem, Stack * ps) {
	if (ps->top == 0) {
		return false;
	} else {
		ps->top--;
		*pitem = ps->items[ps->top];
		return true;
	}
}

int peek (const Stack * ps) {
	if (ps->top > 0) {
		return ps->items[ps->top - 1];
	} else {
		return INT_MIN;
	}
}

typedef struct {
	Stack* stack;
	Stack* maxIndexStack;
} MaxStack;

/** initialize your data structure here. */
MaxStack* maxStackCreate(int maxSize) {
	MaxStack *maxStack = (MaxStack*) malloc (sizeof(MaxStack));
	Stack *stack = (Stack*) malloc (sizeof(Stack));
	initializeStack(stack, maxSize);
	Stack *maxIndexStack = (Stack*) malloc (sizeof(Stack));
	initializeStack(maxIndexStack, maxSize);
	maxStack->stack = stack;
	maxStack->maxIndexStack = maxIndexStack;
	return maxStack;
}

void maxStackPush(MaxStack* obj, int x) {
	if (!fullStack(obj->stack)) {
		push (x, obj->stack);
	}
	if (emptyStack(obj->maxIndexStack) || x >= obj->stack->items[peek(obj->maxIndexStack)]) {
		push (obj->stack->top - 1, obj->maxIndexStack);
	}
}

int maxStackPop(MaxStack* obj) {
	if (peek(obj->maxIndexStack) == obj->stack->top - 1) {
		int i = 0;
		pop(&i, obj->maxIndexStack);
	}
	int x = 0;
	if (!emptyStack(obj->stack)) {
		pop(&x, obj->stack);
	}
	return x;
}

int maxStackTop(MaxStack* obj) {
	return peek(obj->stack);
}

int maxStackPeekMax(MaxStack* obj) {
	return obj->stack->items[peek(obj->maxIndexStack)];
}

int maxStackPopMax(MaxStack* obj) {
	int mx = maxStackPeekMax(obj);
	Stack* temp = (Stack*) malloc (sizeof(Stack));
	initializeStack(temp, obj->stack->maxSize);
	int x = 0;
	while (maxStackTop(obj) != maxStackPeekMax(obj)) {
		push(maxStackTop(obj), temp);
		pop(&x, obj->stack);
	}
	pop(&x, obj->stack);
	pop(&x, obj->maxIndexStack);
	while (!emptyStack(temp)) {
		maxStackPush(obj, peek(temp));
		pop(&x, temp);
	}
	free(temp);
	return mx;
}

void maxStackFree(MaxStack* obj) {
	free(obj->stack->items);
	free(obj->maxIndexStack->items);
	free(obj->stack);
	free(obj->maxIndexStack);
	free(obj);
}

typedef struct {
	MaxStack *s1;
	MaxStack *s2;
} MaxQueue;


MaxQueue* maxQueueCreate() {
	MaxQueue *maxQueue = (MaxQueue *) malloc (sizeof(MaxQueue));
	MaxStack *s1 = maxStackCreate(1024);
	MaxStack *s2 = maxStackCreate(1024);
	maxQueue->s1 = s1;
	maxQueue->s2 = s2;
	return maxQueue;
}

int maxQueueMax_value(MaxQueue* obj) {
	if (emptyStack(obj->s1->stack) && emptyStack(obj->s2->stack)) {
		return -1;
	} else {
		int max1 = INT_MIN;
		int max2 = INT_MIN;
		if (!emptyStack(obj->s1->stack)) {
			max1 = maxStackPeekMax(obj->s1);
		}
		if (!emptyStack(obj->s2->stack)) {
			max2 = maxStackPeekMax(obj->s2);
		}
		return max1 > max2 ? max1 : max2;
	}
}

void maxQueuePush_back(MaxQueue* obj, int value) {
	maxStackPush(obj->s1, value);
}

int maxQueuePop_front(MaxQueue* obj) {
	if (emptyStack(obj->s1->stack) && emptyStack(obj->s2->stack)) {
		return -1;
	} 
	if (emptyStack(obj->s2->stack)) {
		while (!emptyStack(obj->s1->stack)) {
			maxStackPush(obj->s2, maxStackPop(obj->s1));
		}
	}
	return maxStackPop(obj->s2);
}

void maxQueueFree(MaxQueue* obj) {    
	maxStackFree(obj->s1);
	maxStackFree(obj->s2);
	free(obj);
}


/**
 * Your MaxQueue struct will be instantiated and called as such:
 * MaxQueue* obj = maxQueueCreate();
 * int param_1 = maxQueueMax_value(obj);
 
 * maxQueuePush_back(obj, value);
 
 * int param_3 = maxQueuePop_front(obj);
 
 * maxQueueFree(obj);
*/
```