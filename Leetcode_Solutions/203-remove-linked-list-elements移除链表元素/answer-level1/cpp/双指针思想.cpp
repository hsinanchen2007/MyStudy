## 思路分析
- 使用双指针思想删除节点；
- 注意需要删除连续节点的情况；

## 代码实现
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *start = new ListNode(0), *p = head;
        start->next = head;
        ListNode *pre = start;
        while(p!=nullptr){
            if(p->val==val){
                pre->next = p->next;
            }else{
                pre = pre->next;
            }
            p=p->next;
        }
        return start->next;
    }
};
```