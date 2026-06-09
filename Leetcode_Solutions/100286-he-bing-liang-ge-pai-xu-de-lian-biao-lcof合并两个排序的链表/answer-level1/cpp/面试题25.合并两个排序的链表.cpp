### 解题思路
核心思路：设置一个头结点result，将l1和l2从头开始遍历，将较小的连在result之后
执行用时 :28 ms, 在所有 C++ 提交中击败了34.30%的用户
内存消耗 :17.2 MB, 在所有 C++ 提交中击败了100.00%的用户
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode*result=new ListNode(0);
        ListNode*head=result;
        while(l1!=NULL||l2!=NULL){
            if(l1==NULL){
                result->next=l2;
                break;
            }
            if(l2==NULL){
                result->next=l1;
                break;
            }
            if(l1->val<=l2->val){
                result->next=l1;
                l1=l1->next;
                result=result->next;
            }
            else{
                result->next=l2;
                l2=l2->next;
                result=result->next;
            }
        }
        return head->next;
    }
};
```