### 解题思路
核心思路：第一遍遍历求链表长度count，第二次遍历在count/2+1处停止
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8 MB, 在所有 C++ 提交中击败了100.00%的用户
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
    ListNode* middleNode(ListNode* head) {
        int count=0;
        ListNode*node=head;
        ListNode*result=head;
        while(node!=NULL){
            count+=1;
            node=node->next;
        }
        for(int i=1;i<count/2+1;i++){
            result=result->next;
        }
        return result;
    }
};
```