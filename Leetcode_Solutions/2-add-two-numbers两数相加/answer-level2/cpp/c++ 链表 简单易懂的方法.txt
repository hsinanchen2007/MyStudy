### 解题思路
首先遍历两个链表，两个链表公共部分相加进位，最后最多有一个链表没有完全遍历，继续遍历，将这个链表的值和进位符相加。
变量carry的作用是进位符。
变量isCarry的作用是最后一位是否需要进位填1。
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newHeader=new ListNode(0);
        ListNode* newHead=newHeader;
        int carry=0;
        bool isCarry = false;
        while(l1!=nullptr&&l2!=nullptr){         
            ListNode *temp=new ListNode((l1->val+l2->val+carry)%10); 
            newHeader->next=temp;
            newHeader=newHeader->next;    
            carry=(l1->val+l2->val+carry)/10;
            if(carry==0)
                isCarry=false;
            else
                isCarry=true;                  
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=nullptr){
            ListNode *temp=new ListNode((carry+l1->val)%10);
            carry=((carry+l1->val)/10);
            newHeader->next=temp;
            l1=l1->next;
            newHeader=newHeader->next;
            if(carry==1)
                isCarry=true;
            else
                isCarry=false;            
        }
        while(l2!=nullptr){
            ListNode *temp=new ListNode((carry+l2->val)%10);
            newHeader->next=temp;
            carry=((carry+l2->val)/10);
            l2=l2->next;
            newHeader=newHeader->next;
            if(carry==1)
                isCarry=true;
            else
                isCarry=false;
        }        
        if(isCarry){
            ListNode* temp=new ListNode(1);
            newHeader->next=temp;
            newHeader=newHeader->next;
        }
        return newHead->next;
    }
};
```