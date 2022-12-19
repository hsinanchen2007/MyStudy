### 解题思路
使用合并2个排序链表，进行多次合并；
一开始合并2个排序链表是递归的，结果函数没法被调用，改成使用while合并的
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len=lists.size();
        if (len == 0) return NULL;
        int step=2;
        while(step/2<len){
            for(int i=0;i<len-step/2;i+=step){
                lists[i]=mergeTwoLists(lists[i],lists[i+step/2]);
            }
            step*=2;
        }
        return lists[0];
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode* pre = new ListNode(0);
        ListNode* cur = pre;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        cur->next = l1 != NULL ? l1 : l2;

        return pre->next;
    }
};
```