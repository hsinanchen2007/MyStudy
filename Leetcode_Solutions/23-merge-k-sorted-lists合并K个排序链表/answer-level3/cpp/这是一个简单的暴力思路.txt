### 解题思路
1. 实现合并两个链表的方法
2. 循环合并k个链表

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
    // 合并两个有序链表
    ListNode* mergeKLists_two(ListNode* l1, ListNode* l2){
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* head = l1 -> val < l2 -> val ? l1 : l2;
        ListNode* p = head;
        if (head == l1){ l1 = l1 -> next;}
        else{ l2 = l2 -> next;}

        while (l1 && l2){
            if (l1 -> val < l2 -> val){
                p->next = l1;
                p = l1;
                l1 = l1 -> next;
            }else{
                p->next = l2;
                p = l2;
                l2 = l2 -> next;
            }
        }

        if (l1 == NULL && l2 == NULL){
            p -> next = NULL;
            return head;
        }
        if (l1 == NULL){
            p->next = l2;
            return head;
        }
        if (l2 == NULL){
            p->next = l1;
            return head;
        }
        return head;
    }
    // 遍历合并链表
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        if (lists.size() == 1) return lists[0];
        ListNode* res = lists[0];
        for (int i=1; i<lists.size(); ++i){
            res = mergeKLists_two(res, lists[i]);
        }
        return res;
    }
};
```