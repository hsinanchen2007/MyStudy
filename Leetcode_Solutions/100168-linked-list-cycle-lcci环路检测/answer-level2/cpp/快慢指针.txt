### 解题思路
[https://michael.blog.csdn.net/article/details/104610303](https://michael.blog.csdn.net/article/details/104610303)

### 代码

```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while(fast && fast->next)
        {
        	fast = fast->next->next;
        	slow = slow->next;
        	if(fast == slow)
        		break;
        }
        if(!fast || !fast->next)
        	return NULL;
        slow = head;
        while(fast != slow)
        {
        	fast = fast->next;
        	slow = slow->next;
        }
        return fast;
    }
};
```