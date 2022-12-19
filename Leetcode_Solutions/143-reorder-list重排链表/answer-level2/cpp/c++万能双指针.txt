### 解题思路
1. 定义q指向需要插入结点的前驱结点，p指向链表的最后一个结点
2. 将p结点插入到q结点的后面，插入完成后，q向前走两步，p从插入位置继续向后遍历到最后一个结点
3. 重复第二步操作

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
    void reorderList(ListNode* head) {
        ListNode* q = head;
        ListNode* p = head;
        while(q && q->next && q->next->next){
            ListNode* lastNode;
            while(p->next){
                lastNode = p;
                p = p->next;
            }
            lastNode->next = NULL;
            p->next = q->next;
            q->next = p;
            q = q->next->next;
        }
    }
};
```