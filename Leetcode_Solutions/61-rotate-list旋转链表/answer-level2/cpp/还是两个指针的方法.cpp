### 解题思路
我觉得这个题目应该算easy
1. 使用两个指针的方式找到分割点与最后的节点
2. 将最后的节点指向起始节点
3. 分割点指向null

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        ListNode* pre = new ListNode(-1);
        pre->next = head; 
        int len = getListLength(head);
        k %= len;
        ListNode* r = new ListNode(-1); r = pre->next;
        ListNode* l = new ListNode(-1); l = pre->next;
        for(int i = 0; i < k; ++i){
            r = r->next;
        }
        getRightHalfList(l,r);
        r->next = pre->next;
        pre->next = l->next;
        l->next = NULL;
        return pre->next;
    }

    int getListLength(ListNode* head){
        int len = 0;
        while(head){
            ++len; head = head->next;
        }
        return len;
    }

    // l->next is the start point of right half list
    // r is the end point of right half list
    void getRightHalfList(ListNode* &l, ListNode* &r){
        while(r->next){
            r = r->next;
            l = l->next;
        }
    }
};
```

### 结果
执行用时 : 12 ms , 在所有 C++ 提交中击败了 32.12% 的用户 
内存消耗 : 7.2 MB , 在所有 C++ 提交中击败了 100.00% 的用户