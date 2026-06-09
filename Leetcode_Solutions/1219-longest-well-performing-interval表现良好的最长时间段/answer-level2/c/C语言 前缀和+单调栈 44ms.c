    与其他语言的题解类似，先求前缀和，前缀和数组比输入数组的尺寸大一，第一个元素值为0。然后根据输入数组中的元素值，大于8的+1，小于等于8的-1。如输入数组为{9,9,6}，前缀和数组则为{0,1,2,1}。
    求出前缀和数组后，则转化为最大上坡问题（962题）。使用单调栈，从第一个元素开始，将小的元素对应索引进行压栈。然后从数组的最后一个元素开始遍历，与占中的元素进行比较，当前元素如果大于等于栈顶元素，则删除栈顶元素，与下一个元素进行比较。当遇到比当前元素大的值则计算一次结果，直到栈中元素全部弹出，则输出结果。
```
typedef struct HeapList {
	int num;
	struct HeapList *next;
}HeapList;

HeapList* StackCreat(void)
{
	HeapList *Head;
	Head = (HeapList *)malloc(sizeof(HeapList));
	if ((Head == NULL)) {
		return NULL;
	}
	Head->next = NULL;
	return Head;
}

int StackPush(HeapList *Head, int x)
{
	HeapList *Top = (HeapList *)malloc(sizeof(HeapList));
	if (Top == NULL) {
		return -1;
	}
	Top->num = x;
	Top->next = Head->next;
	Head->next = Top;
	return 0;
}

int StackPop(HeapList *Head)
{
	int num;
	HeapList *Top = Head->next;
	Head->next = Top->next;
	num = Top->num;
	free(Top);
	Top = NULL;
	return num;
}

int StackTop(HeapList *Head)
{
	HeapList *Top = Head->next;
	return Top->num;
}

int StackFree(HeapList *Head)
{
	HeapList *Top;
	while (Head->next != NULL) {
		Top = Head;
		Head = Head->next;
		free(Top);
	}
	Top = NULL;
	free(Head);
	Head = NULL;
	return 0;
}
int longestWPI(int* hours, int hoursSize) {
	int *sum = (int*)malloc(sizeof(int)*(hoursSize + 1));
	sum[0] = 0;
	//大于8小时的加一，小于八小时的减一
	for (int i = 0; i < hoursSize; i++) {
		if (hours[i] > 8) {
			sum[i + 1] = sum[i] + 1;
		}
		else {
			sum[i + 1] = sum[i] - 1;
		}
	}
	//转成962最长上坡问题
	int max = 0;
	int top = 0;
	HeapList *Head = StackCreat();
	StackPush(Head, 0);
	for (int i = 1; i <= hoursSize; i++) {
		if (sum[i] < sum[StackTop(Head)]) {
			StackPush(Head, i);
		}
	}
	for (int i = hoursSize; i >= 0; i--) {
		if (i < hoursSize) {
			if (sum[i] <= sum[i + 1]) {	//当前元素小于前面的元素，直接跳过
				continue;
			}
		}
		if (i < StackTop(Head)) {		//当前索引小于栈顶索引，直接跳过并删除栈顶元素
			StackPop(Head);
			continue;
		}
		while (Head->next != NULL) {
			if (sum[i] > sum[StackTop(Head)]) {
				if (max < (i - StackTop(Head))) {
					max = i - StackTop(Head);
				}
				StackPop(Head);         //出栈
				if (Head->next == NULL) {
					if (max < i) {
						max = i;
					}
					return max;
				}
			}
			if (sum[i] <= sum[StackTop(Head)]) {
				break;
			}
		}
	}
	StackFree(Head);
	free(sum);
	sum = NULL;
	return max;
}
```
