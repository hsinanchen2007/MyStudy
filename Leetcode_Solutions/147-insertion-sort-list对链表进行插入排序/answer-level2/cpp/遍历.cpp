### 解题思路
从链表头部开始遍历，记录当前要插入排序的节点和其上一个节点，对每个节点执行如下操作：
1.从头部开始找到当前节点之前第一个不大于它的节点，记录找到的节点以及它前一个节点
2.如果它前一个节点为空，说明要插入到头节点之前，若不为空，则插入到该节点之后
3.继续进行下一次插入排序，直到遍历到链表尾部

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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL) return NULL;

        ListNode *now = head->next, *pre = head;

        while(now)
        {
            ListNode *loc = head, *insert = NULL;

            while(loc != now && loc->val <= now->val)
            {
                insert = loc;
                loc = loc->next;
            }
            if(loc != now){
                pre->next = now->next;
                if(insert == NULL)
                {
                    now->next = head;
                    head = now;
                }
                else
                {
                    now->next = insert->next;
                    insert->next = now;
                }
            }
            else pre = pre->next;
            now = pre->next;
        }
        return head;
    }
};
```