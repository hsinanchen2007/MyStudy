### 解题思路
此处撰写解题思路

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
    ListNode * compare;
public: //四种方法：递归 快慢指针 堆栈 数组
        //强烈推荐递归  太棒了（递归变相的就是回溯，本体就是用到递归回溯的功能）
    
    bool isPalindrome(ListNode *head){
        if(!head) return true;
        compare=head;
        return check(head);
    }
    bool check(ListNode *head){
        if(!head) return true;
        bool front=check(head->next);//我这里是有变量来判定，官方的是直接使用if(!check()) return 只要返回的不对，直接跳过
        if(head->val==compare->val){
            compare=compare->next;
            return true&&front;
        }
        return false&&front;
    }
        /*
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next) return true;
        ListNode *fast=head;
        ListNode *slow=head;
        ListNode *pre=nullptr,*current,*last;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        current=slow->next;
        //last=slow->next->next;
        while(current){
            last=current->next;   //三指针，四步反转
            current->next=pre;
            pre=current;
            current=last;
        }
        while(head&&pre){
            if(head->val!=pre->val) return false;
            head=head->next;
            pre=pre->next;
        }
     return  true;
    }
    */
};
```