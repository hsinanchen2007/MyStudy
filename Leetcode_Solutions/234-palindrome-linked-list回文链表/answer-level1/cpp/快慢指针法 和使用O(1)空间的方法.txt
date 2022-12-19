解法1：先用快慢指针法找出链表中点，，慢指针每走一步，都把值存入栈中，等慢指针到达中点时，再根据栈后进先出的性质让其和后半段链表的值相比较。

```
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next) return true;
        ListNode *slow=head;
        ListNode *fast=head;
        
        stack<int>s;
        s.push(head->val);
        while(fast->next&&fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            s.push(slow->val);
        }
        
        if(!fast->next) s.pop();
        while(slow->next)
        {
            slow=slow->next;
            int tmp=s.top();
            s.pop();
            if(tmp!=slow->val)
                return false;
        }
        return true;
        
        
        
    }
};

```


解法2：这道题的Follow Up让我们用O(1)的空间，那就是说我们不能使用stack了，那么如果代替stack的作用呢，用stack的目的是为了利用其后进先出的特点，好倒着取出前半段的元素。那么现在我们不用stack了，如何倒着取元素呢。我们可以在找到中点后，将后半段的链表翻转一下，这样我们就可以按照回文的顺序比较了，参见代码如下：
```
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next) return true;
        ListNode *slow=head, *fast = head;
        while(fast->next&&fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *last=slow->next, *pre=head;
        while(last->next)
        {
            ListNode *tmp=last->next;
            last->next=tmp->next;
            tmp->next=slow->next;
            slow->next = tmp;
        
        }
        while (slow->next) {
            slow = slow->next;
            if (pre->val != slow->val) return false;
            pre = pre->next;
        }
        return true;
    }
};

```

