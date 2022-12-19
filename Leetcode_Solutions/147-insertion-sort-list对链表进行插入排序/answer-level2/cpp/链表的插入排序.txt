思路：
1、与数组的插入排序不一样，数组可以找到某一元素前面的数据，但链表只能找到后一个
2、通过更改指针的指向可以排序。不要在原链表中进行链表顺序的调整，这会打乱链表原有的顺序，给链表的继续遍历带来麻烦。
3、新建一个空的头指针L来帮助建立有序的链表，将原链表中的单元，一个个的有序插入到L中。
4、不能用p++遍历原链表，新建一个指针cur指向正在处理的单元p后一个单元，避免p插入到L适合位置后，p在原链表中后一个位置找不到。
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
    ListNode* insertionSortList(ListNode* head);
};

ListNode* Solution::insertionSortList(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode L(0);           //建立一个头节点
    L.next = head;
    ListNode* p = head->next;
    head->next = nullptr;
    while (p)               //从第二个元素开始扫描链表
    {
        ListNode* cur = p->next;  //记录p后元素的位置，以免将p插入到新链表
        //后找不到
        ListNode* t = &L;       
        while (t->next != nullptr && t->next->val < p->val) //找到p在新的链表
        //中应插入的位置
        t = t->next;        //将p插入
        p->next = t->next;
        t->next = p;
        p = cur;
    }
    return L.next;
}
```
