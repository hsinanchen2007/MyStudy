### 解题思路
第一个解法是迭代，  第二个解法是递归。
每次都感觉递归很难写。。。

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
    // 执行用时 :8 ms, 在所有 C++ 提交中击败了70.25% 的用户
    // 内存消耗 :7.7 MB, 在所有 C++ 提交中击败了100.00%的用户
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        ListNode* pre = nullptr;
        ListNode* pNext = head, *temp = nullptr;
        while(pNext->next){
            temp = pNext->next;
            pNext->next = pre;
            pre = pNext;
            pNext = temp;
        }
        pNext->next = pre;
        return pNext;
    }



    // 执行用时 :8 ms, 在所有 C++ 提交中击败了70.25% 的用户
    // 内存消耗 :8.1 MB, 在所有 C++ 提交中击败了100.00%的用户
    ListNode* reverseList(ListNode* head){
        if(!head||!head->next) return head;//返回head
        ListNode* p = reverseList(head->next);//递归。 直到最里面一层 p就为最后一个节点指针，此时head为倒数第二个指针，
        head->next->next = head;//head->next为当前节点，把它的下一个节点指向head。
        head->next = nullptr; //把前一个节点的Next指向null
        return p;
    }

};
```