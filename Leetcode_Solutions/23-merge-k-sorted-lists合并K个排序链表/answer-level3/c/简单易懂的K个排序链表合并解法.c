### 解题思路
效率很低，但是符合人的常规思路。
总体思想：每次从几个链表中取出最小的元素添加到新列表的末尾，直至所有的链表都为空位置。
需要解决的问题：
    1. 如何判断所有链表都为空；
    2. 如何取出所有链表当前元素中的最小值并插入到新链表；
    
- 对于问题1，首先最外层为一个while(1)循环，每次先遍历所有链表，并统计其中有多少个链表为空了，当为空的链表数等于总链表数时，表示所有链表为空，直接break;
- 对于问题2，首先另变量值min = INT_MAX，然后遍历每个链表的当前结点，若某个链表的当前结点为空则表示该链表为空，看下一个链表的当前结点，当该结点不为空且其值val小于min时，将这个值赋给min并保存其索引到index，在找到所有链表当前结点的最小值后，然后即可创建一个值为该最小值的结点，连接到新链表的后面。
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
	struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p ,*rear;
	int index, count, min,i;
    index = 0;
	newhead->next = NULL;
    rear = newhead;
	while (1)
	{
		count = 0;
		for (i = 0; i < listsSize; i++)
			if (!lists[i])
				count++;
		if (count == listsSize)
			break;
		min = INT_MAX;
		for (i = 0; i < listsSize; i++)
		{
			if(!lists[i])
                continue;
            else
            {
                if(min>lists[i]->val)
                {
                    min = lists[i]->val;
                    index = i;
                }
            }

		}
        if(min != INT_MAX)
        {
            p = (struct ListNode*)malloc(sizeof(struct ListNode));
            p->val = lists[index]->val;
            p->next = NULL;
            rear->next = p;
            rear = p;
            lists[index] = lists[index]->next;
        }
	}

	return newhead->next;
}
```