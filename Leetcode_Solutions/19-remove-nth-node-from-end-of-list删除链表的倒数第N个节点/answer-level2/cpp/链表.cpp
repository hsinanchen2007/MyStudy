### 解题思路
具体的解释已经在代码中注释了，我想说一下有一坑，就是head没有头节点，所以如果只有一个节点的话用循环找到以n为间隔的j2会直接指向null报错，当然也可以用一个特判判断j2直接出答案。

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p=new ListNode(0);//创建一个头节点为0的链表
        p->next=head;//接上head链表
        ListNode *j1=p;//定义移动指针从头节点开始
        ListNode *j2=p;
        for(int k=0;k<=n;k++) j2=j2->next;//间隔选取为n
        while(j2)
        {
            j1=j1->next;
            j2=j2->next;
        }//此时j2已经为NULL，j1->next即要删除的节点
        j1->next=j1->next->next;//跳过要删的节点即可
        return p->next;//不要记入头节点
    }
};
```