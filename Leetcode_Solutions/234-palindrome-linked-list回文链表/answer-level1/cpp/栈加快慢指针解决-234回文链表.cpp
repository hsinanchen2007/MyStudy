### 解题思路
相对我之前的思路，用栈把前半部分保存在栈里面只需要一轮比较就可以完成判断，从而提高效率
基本思路：
一，先用快慢指针法找到中点，边找边进栈
二，（注意奇数偶数链表的栈中元素是否与slow的右边对称）边出栈，边比较，slow后移


### 代码

```cpp
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
    bool isPalindrome(ListNode* head) 
    {
        if(head==NULL||head->next==NULL)    //特殊处理
        return true;

        ListNode *fast=head;
        ListNode *slow=head;
        ListNode *left=head;
            stack<int>s;
            s.push(head->val);                                  //利用快慢指针法让slow找到中心点
        while(fast->next&&fast->next->next)
        {

            fast=fast->next->next;
            slow=slow->next;
            s.push(slow->val);
        }

        if(fast->next==NULL)                             //偶数链做退栈处理，保证栈里面和slow的右边对称
        s.pop();
        while(!s.empty())
        {
            if(s.top()!=slow->next->val)
            {
                return false;
            }

            else
            {
                slow=slow->next;
                s.pop();
            }
        }
        return true;

    }
};
```