### 解题思路
题目意思：将小于x的节点放在链表前部
partTail是小于x的部分的尾巴
建立空头节点哨兵，用head遍历，prev记录前置节点

### 代码

```cpp
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
    	ListNode *emptyHead = new ListNode(-1), *prev, *partTail;
    	emptyHead->next = head;
    	partTail = prev = emptyHead;
    	while(head)
    	{
    		if(head->val < x && partTail != prev)
    		{
    			prev->next = prev->next->next;
    			head->next = partTail->next;
    			partTail->next = head;
    			head = prev->next;
    		}
    		else
    		{
    			prev = head;
    			head = head->next;
    		}
    	}
    	return emptyHead->next;
    }
};
```