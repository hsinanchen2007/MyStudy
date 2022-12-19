### 解题思路
核心思路：双指针，前一个提前走k-1步，然后一起走，检测前指针的next为空时停止
执行用时 :4 ms, 在所有 C++ 提交中击败了82.90%的用户
内存消耗 :10.2 MB, 在所有 C++ 提交中击败了100.00%的用户
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode*pre=head;
        ListNode*cur=head;
        for(int i=0;i<k-1;i++){
            cur=cur->next;
        }
        while(cur->next!=NULL){
            pre=pre->next;
            cur=cur->next;
        }
        return pre;
    }
};
```