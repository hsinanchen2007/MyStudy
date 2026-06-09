
## 思路分析
 链表对折，假设对折截取后的链表分为left 和right，right 进行翻转，最后按规则进行交叉合并： L0->Ln->L1->Ln-1......；当链表的长度为偶数的时候，left.length =  right.length ，当链表的长度为奇数的时候，left.length =  right.length + 1。

## 代码实现
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
    void reorderList(ListNode* head) {
        ListNode * p = head;
        int length = 0;
        while(p!=nullptr){
            length++;
            p = p->next;
        }
        if(length<=1) return;
        // 链表截取
        int cut = length/2;
        ListNode *left = head, *right = nullptr;
        p = head;
        while(--cut>0) p = p->next;
        if(length%2!=0) p = p->next;
        // right 翻转
        right =this->reverse(p->next);
        p->next = nullptr;
        // 两个链表合并
        while(left!=nullptr&&right!=nullptr){
            ListNode * temp = left->next;
            left->next = right;
            right = right->next;
            left->next->next = temp;
            left =temp;
        }
    }
private:
    ListNode*  reverse(ListNode * head){
        ListNode* p = new ListNode(0);
        while(head!=nullptr){
            ListNode * temp = p->next;
            p->next = head;
            head = head->next;
            p->next->next = temp;
        }
        return p->next;
    }
};
```