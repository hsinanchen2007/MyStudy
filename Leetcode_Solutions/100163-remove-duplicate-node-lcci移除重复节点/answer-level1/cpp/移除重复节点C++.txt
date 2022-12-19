### 解题思路
1. 暴力法
   两次遍历。对于每一个当前节点cur，从头节点head开始遍历到当前节点的上一个节点tail，检查是否出现过tail->val == cur->val：  
   (1) 如果出现，那么tail->next = cur->next,删除cur节点  
   (2) 如果没有出现，那么将tail节点后移，tail = cur;  
   tail指针时钟无重复区的尾部。  
   复杂度：O(n^2) & O(1)  
2. 哈希表  
   一次遍历。使用额外空间，利用哈希表unodered_set来在O(1)的时间内判断cur->val是否出现过。复杂度：O(n) & O(n)。  
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
    //暴力法：O(n^2) & O(1)
    // ListNode* removeDuplicateNodes(ListNode* head) {
    //     if(head == NULL || head->next == NULL) return head;
    //     ListNode * beg = head;
    //     ListNode * tail = head;
    //     ListNode * cur  = head->next;
    //     while(cur != NULL){
    //         beg = head;
    //         while(beg != cur && beg->val != cur->val){
    //             beg = beg->next;
    //         }
    //         if(beg == cur){
    //             tail = cur;
    //         }else{
    //             tail->next = cur->next;
    //             delete cur;
    //         }
    //         cur = tail->next;
    //     }
    //     return head;
    // }
    //哈希表：O(n) & O(n)
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        unordered_set<int> set;
        ListNode * tail = head;
        ListNode * cur = head->next;
        set.insert(tail->val);
        while(cur != NULL){
            if(set.find(cur->val) == set.end()){
                set.insert(cur->val);
                tail = cur;
            }else{
                tail->next = cur->next;
                delete cur;
            }
            cur = tail->next;
        }
        return head;
    }
};
```