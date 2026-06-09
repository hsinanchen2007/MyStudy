### 解题思路
利用归并排序的方法，先切片至只剩一个链表，再两两合并链表

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
    ListNode* help(vector<ListNode*>& lists,int start,int end){
        if(start == end){
            return lists[start];
        }
        int mid = (start + end) / 2;
        ListNode* l1 = help(lists,start,mid);
        ListNode* l2 = help(lists,mid + 1,end);
        ListNode dummyNode(INT_MIN);
        ListNode* cur = &dummyNode;
        while(l1 && l2){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        while(l1){
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
        }
        while(l2){
            cur->next = l2;
            cur = cur->next;
            l2 = l2->next;
        }
        return dummyNode.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }
        return help(lists,0,lists.size() - 1);
    }
};
```