### 解题思路
该题是对链表进行操作，使用到了递归，解决思路如下:
* 对l1和l2进行入参检查
* 创建一个新的节点
* 比较两个节点的值的大小，并将其放入malloc的节点中
* 进行递归

**Note: 本题使用了malloc和递归，并不是最优解法。该题可将递归改为迭代，同时尽量不要使用malloc，因为会造成内存泄露。**


### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    //入参检查
    if((l1 == NULL) && (l2 == NULL))
    {
        return NULL;
    }

    if((l1 == NULL) && (l2 != NULL))
    {
        return l2;
    }

    if((l1 != NULL) && (l2 == NULL))
    {
        return l1;
    }

	struct ListNode* result= (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode*temp=result;
	if(l1->val>l2->val)
	{
		temp->next=l2;
		l2=l2->next;
	}
	else
	{
		temp->next=l1;
		l1=l1->next;
	}

	temp=temp->next;
	temp->next=mergeTwoLists(l1,l2);

	return result->next;
}
```