### 解题思路
本题的难点在于性能的要求，尤其是最后一个用例。这题应该算到困难里，对性能要求比较高。
想法：
1.push函数：为了减少频繁分配内存对性能的影响，因此，不考虑使用链表来实现栈，改用数组来实现，因此数组一次可以分配大空间内存，不用每次push都去分配（链表的实现就需要每次push都去malloc）。
2.push函数：由于push量的大小不确定，因此，设置一个动态内存分配机制：当栈内存不够时，从新分配一个比现有栈空间大SPACE_EXPAND_FACTOR倍的空间。这种实现方式有点类似于android系统中的arraymap（哈希表的一个变种）的实现方式。
3.TOP指针：为了降低寻址时间，在栈数据结构中引入一个top指针，时刻指向数组最后一个元素，作为栈顶。为了避免频繁memcpy（top在数组开头时），本实现把top放在数组末尾。
4.getMin函数：为了避免getMin遍历栈取最小值的耗时，在栈数据结构中引入一个minVal的域，用于记录栈中最小值。并在每次push操作时，都去更新该minVal。pop时亦如此。
5.可以通过INIT_SIZE和SPACE_EXPAND_FACTOR的不同值来调节算法的快慢和空间快慢。貌似100 、2 最快。

后记：
C语言实现起来比较繁琐，没有其他语言实现起来方便。
源代码汇总带了很多调试的for循环，导致提交老是没通过，浪费了很多时间。mark~

![image.png](https://pic.leetcode-cn.com/2d46fbb149781842df313af3082421b8af9c49e66ebdde9c2ad613297abc6215-image.png)


### 代码

```c

#define MIN_VAL -65536
#define INVALID_VAL 65535
#define INVALID_POINTER -1
#define INIT_SIZE 100
#define SPACE_EXPAND_FACTOR 2

typedef struct {
    int *vals;
    int top; //top pointer
	int spaceSize;
	int minVal;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *stack = (MinStack *)malloc(sizeof(MinStack));
    stack->vals = NULL;
    stack->spaceSize = 0;
	stack->top = INVALID_POINTER;
	stack->minVal = MIN_VAL;
    return stack;
}

void minStackPush(MinStack* obj, int x) {
    MinStack *stack = obj;
    if(stack == NULL) {
		printf("stack == NULL\n");
        return;
    }

	if(stack->spaceSize == 0) {
		stack->vals = (int *)malloc(INIT_SIZE * sizeof(int));
		stack->spaceSize = INIT_SIZE;
		stack->top = 0;
		stack->vals[stack->top] = x;
		stack->minVal = x;		
	}
	else {
		if (stack->top < stack->spaceSize - 1) {
			stack->top++;
			stack->vals[stack->top] = x;
			stack->minVal = stack->minVal < x ? stack->minVal : x;
		}
		else {
			int oldSpaceSize = stack->spaceSize;
			stack->spaceSize = SPACE_EXPAND_FACTOR * stack->spaceSize;
			int *temp1 = (int *)malloc(stack->spaceSize * sizeof(int));
			memcpy(temp1, stack->vals, oldSpaceSize * sizeof(int));
			stack->top++;
			temp1[stack->top] = x;
			stack->minVal = stack->minVal < x ? stack->minVal : x;
			free(stack->vals);
			stack->vals = temp1;		
		}
	}
#if 0
	printf("push:stack = ");
	for(int i = stack->top; 0 <= i; i--) {
		printf("%d->",stack->vals[i]);
	}
	printf("\n");	
#endif
    return;
}

void minStackPop(MinStack* obj) {
    MinStack *stack = obj;
    if(stack == NULL) {
		printf("stack == NULL\n");
        return;
    }    
    int *temp1 = NULL;
    int *temp2 = NULL;
	if(stack->top == INVALID_POINTER) {
		printf("top is invalid\n");
        return;
    }
	else if(stack->top == 0) {
         free(stack->vals);
         stack->spaceSize = 0;
		 stack->vals = NULL;
         stack->top = INVALID_POINTER;
		 stack->minVal = MIN_VAL;
    }
    else if(stack->top > 0) {
		if(stack->minVal == stack->vals[stack->top]) {
			stack->minVal = stack->vals[stack->top - 1];
			for(int i = stack->top - 1; 0 <= i; i--) {
				stack->minVal = stack->minVal < stack->vals[i] ? stack->minVal :stack->vals[i];
			}
		}
		stack->vals[stack->top] = INVALID_VAL;
		stack->top--;
    }
	
	if(stack->top == INVALID_POINTER) {
		printf("pop:stack is null\n");
	}
	else {
	    printf("pop:stack = ");
	    for(int i = stack->top; 0 <= i; i--) {
	    	printf("%d->",stack->vals[i]);
	    }
	    printf("\n");	
	}

    return;  
}

int minStackTop(MinStack* obj) {
    MinStack *stack = obj;
    if(stack == NULL) {
		printf("stack == NULL\n");
        return 0;
    }

	if(stack->top == INVALID_POINTER) {
		printf("top is invalid\n");
        return 0;
    }

	printf("top:%d\n",stack->vals[stack->top]);
	return stack->vals[stack->top];  
}

int minStackGetMin(MinStack* obj) {
    MinStack *stack = obj;
    int min = 0;
    int i = 0;
    if(stack == NULL) {
		printf("stack == NULL\n");
        return 0;
    }
	printf("getmin:%d\n",stack->minVal);
	return stack->minVal;  
}

void minStackFree(MinStack* obj) {
        MinStack *stack = obj;
        if(stack == NULL) {
		   printf("stack == NULL\n");
           return;
        }          
        free(stack->vals);
        stack->vals = NULL;
        free(stack);
		stack = NULL;
        return;
}
```