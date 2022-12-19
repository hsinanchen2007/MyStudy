### 解题思路
首先，leetcode的链表都是没有额外的头节点的，即头节点直接是保存数据的。
然后，开始理清思路：
申请一个新的节点叫new_head，并把它的next设置为NULL。
依次遍历原来的链表，(使用head作为当前节点)每到一个节点，完成4个操作
①记录head(当前节点)的下一个节点，叫next。
②让head(当前节点)指向new_head。(辅助理解，此时head(当前节点)已经和原链表断开了)
③现在把new_head指向head，也就是可以理解为new_head为尾插法。
④head此时再更新为next，继续往下遍历节点。
代码如下:(第一次写题解，还有很多不足，如果还可以优化等，欢迎拍砖哦)
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
    ListNode* reverseList(ListNode* head) {
        ListNode * new_head=NULL;
        while(head)
        {
            ListNode* next= head->next;
            head->next=new_head;
            new_head=head;
            head=next;
        }
        return new_head;
    }
};
```