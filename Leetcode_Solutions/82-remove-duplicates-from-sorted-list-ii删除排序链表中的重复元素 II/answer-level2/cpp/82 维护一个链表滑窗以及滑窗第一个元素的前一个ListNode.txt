### 解题思路
这道题和83题目的做法类似，唯一的区别是在要维护滑窗第一个元素的前一个ListNode，因为整个滑窗都会被删除

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
        if(!head) return NULL;
        ListNode* pre = new ListNode(-1);
        ListNode* res = new ListNode(-1);
        pre->next = head; res = pre;
        while(head->next){
            int target = head->val;
            if(head->next->val != target){
                head = head->next;
                pre = pre->next;
            }else{
                ListNode* post = new ListNode(-1);
                post = head->next;
                while(post->next && post->next->val == target){
                    post = post->next;
                }
                if(!post->next){
                    pre->next = NULL;
                    return res->next;
                }else{
                    head = post->next;
                    pre->next = head;
                }
            }
        }
        return res->next;
    }
};
```

### 结果
执行用时 : 12 ms , 在所有 C++ 提交中击败了 47.87% 的用户 
内存消耗 : 7.4 MB , 在所有 C++ 提交中击败了 100.00% 的用户