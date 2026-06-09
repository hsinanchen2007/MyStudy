### 解题思路
拿题给`[7,8,4,3]`和`[5,6,4]`作为例子：
1. 先将两个链表反转，得到`[3,4,8,7]`和`[5,6,4]`
2. 逐位相加，使用变量`carry`记录当前节点的相加是否会产生进位。若有，下对节点相加要加上这个进位
3. 将得到的结果反转即所求

【注意】[9,9,9]和[1]这样的节点会产生新的节点，该节点的值为1。即最后结果[1,0,0,0]

**时间复杂度：O(n)，空间复杂度O(1)**

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
        // 翻转l1
        ListNode *p1 = l1; ListNode *p2 = l2;
        ListNode *pre = NULL, *p_next;
        while(p1){
            p_next = p1->next;
            p1->next = pre;
            pre = p1;
            p1 = p_next;
        }
        l1 = pre;
        pre = NULL;
        while(p2){
            p_next = p2->next;
            p2->next = pre;
            pre = p2;
            p2 = p_next;
        }
        l2 = pre;
        int carry = 0;
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while(l1 && l2){
            l1->val = l1->val + l2->val + carry;
            if(l1->val >= 10){
                l1->val = l1->val % 10;
                carry = 1;
            }
            else{
                carry = 0;
            }
            p->next = l1;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 == NULL && l2 == NULL){
            if(carry == 1){
                ListNode *add = new ListNode(1);
                p->next = add;
            }
        }
        else if(l1 == NULL){
            l2->val = l2->val + carry;
            if(l2->val >= 10){
                carry = 1;
                l2->val = l2->val % 10;
            }
            else carry = 0;
            p->next = l2;
            while(l2->next){
                l2 = l2->next;
                if(carry == 1){
                    l2->val = l2->val + carry;
                    if(l2->val >= 10){
                        carry = 1;
                        l2->val = l2->val % 10;
                    }
                    else{
                        carry = 0;
                        break;
                    } 
                }
                else{
                    carry = 0;
                    break;
                }
            }
            if(carry){
                ListNode *add = new ListNode(1);
                l2->next = add;
            }
        }
        else {
            l1->val = l1->val + carry;
            if(l1->val >= 10){
                carry = 1;
                l1->val = l1->val % 10;
            }
            else carry = 0;
            p->next = l1;
            while(l1->next){
                l1 = l1->next;
                if(carry == 1){
                    l1->val = l1->val + carry;
                    if(l1->val >= 10){
                        carry = 1;
                        l1->val = l1->val % 10;
                    }
                    else{
                        carry = 0;
                        break;
                    } 
                }
                else{
                    carry = 0;
                    break;
                }
            }
            if(carry){
                ListNode *add = new ListNode(1);
                l1->next = add;
            }
        }
        pre = NULL;
        head = head->next;
        while(head){
            p_next = head->next;
            head->next = pre;
            pre = head;
            head = p_next;
        }
        head = pre;
        return head;
    }
};
```