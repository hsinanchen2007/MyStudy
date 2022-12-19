### 解题思路
先快慢指针找到中点，断开（注意快指针要先走一步，偶数节点的时候保证均分）
反转后半段，跟前半段比较即可
[https://blog.csdn.net/qq_21201267/article/details/104609526](https://blog.csdn.net/qq_21201267/article/details/104609526)

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(ListNode* head) {
    	if(!head || !head->next)
    		return true;
    	ListNode *halfhead = NULL, *fast = head->next, *slow = head;
    	while(fast && fast->next)
    	{
    		fast = fast->next->next;
    		slow = slow->next;
    	}
    	halfhead = slow->next;
    	slow->next = NULL;
    	halfhead = reverseList(halfhead);
    	while(head && halfhead)
    	{
    		if(head->val != halfhead->val)
    			return false;
            head = head->next;
            halfhead = halfhead->next;
    	}
    	return true;
    }

    ListNode* reverseList(ListNode *head)
    {
    	ListNode *prev = NULL, *cur = head, *nt = cur->next;
    	while(cur && cur->next)
    	{
    		cur->next = prev;
    		prev = cur;
    		cur = nt;
    		nt = nt->next;
    	}
    	cur->next = prev;
    	return cur;
    }
};
```