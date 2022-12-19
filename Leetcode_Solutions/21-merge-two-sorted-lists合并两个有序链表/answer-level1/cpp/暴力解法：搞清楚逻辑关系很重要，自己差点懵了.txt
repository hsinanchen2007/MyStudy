### 解题思路
注意：函数传入的值是两个指针，而不是两个链表。
初始化空指针用nullptr。而不是NULL。
### 代码
```
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode(0); //任意初始化一个firstNode，然后在返回值中返回该节点的下一个节点。
        ListNode *copy = res;
        if (l1==0) copy->next = l2;
        if (l1!=0 && l2==0) copy->next = l1;
        else {
            while (l1!=0 && l2!=0) {
                if (l1->val <= l2->val) {
                    copy->next = l1;
                    copy = copy->next;
                    l1 = l1->next;
                }
                else if (l1->val > l2->val) {
                    copy->next = l2;
                    copy = copy->next;
                    l2 = l2->next;
                }
            }
            copy->next = l1!=0?l1:l2; //谁没空就续接上谁
        }
        return res->next; //返回firstNode的下一个节点
    }
};
```
