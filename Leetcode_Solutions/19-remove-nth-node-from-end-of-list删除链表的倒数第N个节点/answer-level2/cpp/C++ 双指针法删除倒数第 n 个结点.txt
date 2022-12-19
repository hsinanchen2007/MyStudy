***Talk is cheap. Show me the code.***

```cpp
// 没有使用哨兵结点的版本

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	ListNode *pre = head;
    	ListNode *cur = head;
    	
    	for (int i = 0; i < n; i++) {
    		cur = cur->next;
    	}

    	if (cur == nullptr) {
    		head = head->next;
    		delete pre;
    		return head;
    	}

    	while (cur->next != nullptr) {
    		pre = pre->next;
    		cur = cur->next;
    	}
    	
    	ListNode *tmp = pre->next;
    	pre->next = tmp->next;
    	delete tmp;
    	return head;
    }
};
```

``` cpp
// 使用了哨兵结点的版本

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy;
        ListNode *cur = &dummy;

        for (int i = 0; i < n+1; i++) {
            cur = cur->next;
        }

        while (cur != nullptr) {
            cur = cur->next;
            pre = pre->next;
        }

        ListNode *tmp = pre->next;
        pre->next = tmp->next;
        delete tmp;
        return dummy.next;
    }
};

```
- 一般来说，涉及到链表的插入、删除操作，使用哨兵结点可以避免掉某些边界条件的判断，使代码实现变得更简洁