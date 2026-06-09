
首先，将两个链表各建立一个栈。 <br>
之后在循环中，每次拿到栈顶的数据，并相加，处理好进位问题之后，进行下一轮计算。

```
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        buildStack(s1, l1);
        buildStack(s2, l2);
        // 要被返回的List
        ListNode* head = new ListNode(-1);
        // 进位
        int carry = 0;
        
        // 两个栈任意一个不为空，或进位数据不为0，即可进行下一轮循环。
        while(!s1.empty() || !s2.empty() || carry != 0) {
            int n1, n2, sum;
            if(s1.empty()) { n1 = 0; } else {
                n1 = s1.top(); s1.pop();
            }
            if(s2.empty()) { n2 = 0;} else {
                n2 = s2.top(); s2.pop();
            }
            sum = n1 + n2 + carry;
            // 将下个节点插入到将返回的链表中
            ListNode* nextNode = new ListNode(sum%10);
            nextNode -> next = head->next;
            head->next = nextNode;
            carry = sum / 10;
        }
        return head->next;
    }
    static void buildStack(stack<int>& s, ListNode* head) {
        while(head != NULL) {
            s.push(head->val);
            head = head->next;
        }
    }
};
```