### 解题思路
首先在head前添加一个头节点，目的是为了更加易于操作
每次交换两个相邻的结点，因此将此两个结点视为一个整体，并定义指针p指向整体前的结点
循环终止条件为p的后一个或后两个结点为空指针
定义tmp1和tmp2,交换时令tmp1->next=tmp2->next
tmp2->next=tmp1则完成了两个节点的交换
再连接在p上
不断重复此过程
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
    ListNode* swapPairs(ListNode* head) {
       ListNode *prev=new ListNode(1);
        prev->next = head;
        ListNode *p=prev;
        while(p->next!=nullptr && p->next->next!=nullptr){
            ListNode *tmp1=p->next;
            ListNode *tmp2=tmp1->next;
            tmp1->next = tmp2->next;
            tmp2->next = tmp1;
            p->next = tmp2;
            p = tmp1;
        }
        return prev->next;
    }
};
```