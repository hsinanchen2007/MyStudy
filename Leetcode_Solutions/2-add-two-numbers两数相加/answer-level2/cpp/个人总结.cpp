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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        bool flag = true;
        ListNode* newlisthead = new ListNode(-1);
        ListNode* listnode_tmp = newlisthead;
        while(l1 != nullptr || l2 != nullptr){
            int val_l1;
            int val_l2;
            if(l1 == nullptr){
                val_l1 = 0;
                val_l2 = l2->val;
            }else if(l2 == nullptr){
                val_l2 = 0;
                val_l1 = l1->val;
            }else{
                val_l1 = l1->val;
                val_l2 = l2->val;
            }
            
            
            listnode_tmp->next = new ListNode((val_l1 + val_l2 + carry) % 10);
            carry = (val_l1 + val_l2 + carry) / 10;
            if(l1 == nullptr){
                l2 = l2->next; 
            }else if(l2 == nullptr){
                l1 = l1->next;
            }else{
                l1 = l1->next;
                l2 = l2->next;
            }
            listnode_tmp = listnode_tmp->next;
        }
        if(carry == 1){
            listnode_tmp->next = new ListNode(1);
        }
        return newlisthead->next;
    }
};
```
修修补补===

总结：
1.生成新链表最好都是创造一个无关的链表头，然后返回->next
2.创造链表的下一个节点，一定要new Listnode，直接->next是不行的，会是一个空指针