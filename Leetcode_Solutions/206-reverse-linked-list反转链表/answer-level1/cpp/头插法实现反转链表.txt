### 解题思路
可以通过头插法反转链表
依次将节点放置链表头节点的位置，并保持链表的链关系，即可实现逆转链表
每一步需要存下temp节点（cur节点的next节点），将cur节点的next设为pre节点，更新pre节点为cur节点，更新cur节点为temp节点
直至cur为空，返回链表头节点（此时是pre节点）
example:
初始：A->B->C->NULL
第一步：A->NULL
第二步: B->A->NULL
第三步：C->B->A->NULL
结束

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
        ListNode* cur = head;
        ListNode* pre = NULL;
        while(cur != NULL){
            ListNode* temp = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};
```