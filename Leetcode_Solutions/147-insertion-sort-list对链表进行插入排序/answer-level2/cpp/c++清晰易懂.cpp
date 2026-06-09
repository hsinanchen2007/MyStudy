### 解题思路
1. 定义新的头结点
2. 定位有序链表的最后一个结点
3. 对需要插入结点对有序链表进行由左向右判断可插入位置
4. 若到有序链表的最后一个结点，则插入到最后并更新最后一个结点的指向
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
        if(!head) return head;
        ListNode* front = new ListNode(NULL);
        front->next = head;
        ListNode* q = head;
        ListNode* p;
        while(q->next){
            ListNode* inNode = q->next;
            q->next = inNode->next;
            inNode->next = NULL;

            p = front;
            while(1){
                if(p == q){
                    inNode->next = p->next;
                    p->next = inNode;
                    q = inNode;
                    break;
                }else if(p->next->val >= inNode->val){
                    inNode->next = p->next;
                    p->next = inNode;
                    break;
                }else{
                    p = p->next;
                }
            }
        }
        return front->next;
    }
};
```