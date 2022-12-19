## 思路分析
归并排序

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
ListNode* sortList(ListNode* head)
{
    int length = 0;
    ListNode * p = head;
    while(p!=nullptr){
        p = p->next;
        length++;
    }
    ListNode * leader = new ListNode(0);
    leader->next = head;
    for(int size=1; size<length; size<<=1 ){
        ListNode * temp = leader;
        p = temp->next;
        while(p!=nullptr){
            ListNode *left = p;
            p = cut(left, size);
            ListNode *right = p;
            p = cut(right, size);
            temp->next = merge(left,right);
            while (right!=nullptr) {
                temp = right;
                right = right->next;
            }
        }
    }
    return leader->next;
}

ListNode* cut(ListNode * head, int size)
{
    ListNode *p = head;
    int i = 1;
    while(i++<size&&p!=nullptr){
        p=p->next;
    }
    ListNode *node =nullptr;
    if(p!=nullptr){
        node = p->next;
        p->next = nullptr;
    }
    return node;
}

ListNode * merge(ListNode * left, ListNode * right)
{
    ListNode * head = new ListNode(0);
    ListNode *p = head;
    while(left!=nullptr&&right!=nullptr){
        if(left->val<right->val){
            p->next = left;
            p = left;
            left = left->next;
            p->next = right;
        }else{
            p->next = right;
            p = right;
            right = right->next;
            p->next = left;
        }
    }
    p->next= left==nullptr?right:left;
    return head->next;
}
};
```