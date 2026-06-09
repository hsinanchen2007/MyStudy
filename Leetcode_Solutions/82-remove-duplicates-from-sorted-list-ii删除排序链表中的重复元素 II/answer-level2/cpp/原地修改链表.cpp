### 解题思路
- 设置一个辅助节点`res`，该节点为无重复元素的链表表头
- 从给出链表的第一个节点开始遍历，若当前节点的值与下一个节点值相同，则循环寻找到当前节点值与下一个节点值不同的位置，将该位置的**下一个**节点假如到`res`链表中。如`[3,3,4]`，则当前节点值与下一个节点值不相同的位置为下标`1`，那么，它的下一个节点为`4`，将`4`加入`res`
- 若当前节点值与下一个节点值不相同，直接将其加入到`res`中
- 直到遍历完`head`链表，返回`res->next`即为所求


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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *p = head;
        ListNode *res = new ListNode(0);
        ListNode *cur = res;
        while(p){

            // 如果p->next存在
            if(p->next){
                //如果当前节点与下一个节点值相同
                if(p->next->val == p->val){
                    while(p->next && p->next->val == p->val){
                        p = p->next;
                    }
                    cur->next = p->next;
                    // cur = cur->next;
                    p = p->next;
                }

                //当前节点与下一个节点值不同
                else{
                    cur->next = p;
                    cur = cur->next;
                    p = p->next;
                }
            }

            //如果p->next不存在
            else{
                cur->next = p;
                p = p->next;
            }
        }
        return res->next;
    }
};
```