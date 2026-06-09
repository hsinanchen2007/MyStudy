### 解题思路
很简单的思路，就是用一个数组存放不重复的结果。
然后去比较就好了
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
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode* op=head;
        ListNode* result_node=head;
        vector <int> result;
        if(head==NULL){
            return NULL;
        }
        while(op){
            if(op==head){
                result.push_back(op->val);
                op=op->next;
            }
            else{
                int j=0;
                for(int i=0;i<result.size();i++){
                    if(result[i]!=op->val){
                        j++;
                    }
                }
                if(j==result.size()){
                    head->next=op;
                    head=head->next;
                    result.push_back(op->val);
                    op=op->next;
                }
                else{
                    op=op->next;
                }
            }
        }
        head->next=NULL;
        return result_node;



    }
};
```