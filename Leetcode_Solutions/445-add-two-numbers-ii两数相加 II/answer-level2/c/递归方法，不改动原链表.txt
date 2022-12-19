```
int addTwoNumbersCore(struct ListNode*, struct ListNode*, int, int);

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	
	if((l1 == NULL) || (l2 == NULL))
	{
		return NULL;
	}
	
	struct ListNode *ptr, *sumPtr, *sumHead, *temp, *longList, *shortList;
	int l1Size, l2Size, sumSize, addSize;
	
	l1Size = 0;
	l2Size = 0;
	sumHead = (struct ListNode*)malloc(sizeof(struct ListNode));
	sumHead->next = NULL;
	sumHead->val = 0;                                      //预留一个最高位
	
	for(ptr = l1; ptr != NULL; ptr = ptr->next, l1Size++);
	for(ptr = l2; ptr != NULL; ptr = ptr->next, l2Size++); //得到两个链表的大小
	
	if(l1Size >= l2Size)
	{
		longList = l1;
		shortList = l2;
		sumSize = l1Size + 1;
		addSize = l2Size;
	}
	else
	{
		longList = l2;
		shortList = l1;
		sumSize = l2Size + 1;
		addSize = l1Size;
	}                                                       //选择较长链表作为sum的底。 
	
	for(ptr = longList, sumPtr = sumHead; ptr != NULL; ptr = ptr->next, sumPtr = sumPtr->next)
	{
		temp = (struct ListNode*)malloc(sizeof(struct ListNode));
		temp->next = ptr->next;
		temp->val = ptr->val;
		sumPtr->next = temp;
	}                                                       //将较长链表接到sumHead之后。
	
    addTwoNumbersCore(sumHead, shortList,sumSize,addSize);  //做加法
    
	if(sumHead->val == 0)
	{
		return sumHead->next;
	}                                                       //如果预留的位没有用上，返回sumHead->next
	
	return sumHead;		
}

int addTwoNumbersCore(struct ListNode* sum, struct ListNode* add, int sumPos, int addPos )
{
	
	if((sumPos == 0)&&(addPos == 0))
	{
		return 0;
	}                                                       //基线条件
		
	int tempSum;
		
	if(sumPos > addPos)
	{
		tempSum = sum->val + addTwoNumbersCore(sum->next,add,sumPos-1,addPos);
	}                                                       //如果两个结点的数位不同（只有可能sumPos>addPos），只用给sum->val加一个递归的进位值
	else if(sumPos = addPos)
	{
		tempSum = sum->val + add->val + addTwoNumbersCore(sum->next,add->next,sumPos-1,addPos-1);
	}
	else
	{
		printf("There is an error! while digital position %d + %d",sumPos, addPos);
		return -1;
	}
	
	sum->val = tempSum%10;   
	return tempSum/10;		
			
}
```
感觉变量名太乱了。