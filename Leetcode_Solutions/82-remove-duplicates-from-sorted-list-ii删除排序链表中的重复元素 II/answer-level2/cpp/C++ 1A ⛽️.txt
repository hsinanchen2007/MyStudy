裸体思路。  直接

```
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
        ListNode * dummyhead = new ListNode(0);
        dummyhead->next = head;
        /*
            最初的思路：
            记录前驱结点。
            如果当前与前驱结点相同，则记录前驱结点的前一个结点。然后继续找，直到不同为止，连接前后。
            
            写代码之后，直接往前找，而不是往回找
        */
        ListNode * cur = head;
        ListNode * pre = dummyhead;
        while(cur != NULL){
           
           if(cur->next!= NULL && cur->next->val == cur->val){
               
              // 走到头，或者走到不一样的值。 
               while(cur->next!= NULL && cur->next->val == cur->val){
                    cur = cur->next; 
               }
                pre->next = cur->next;
                cur = cur->next;
           }else{
                pre = cur;// 前一个结点，与自己不同的结点。
                cur = cur->next;
           }
        
        }
        return dummyhead->next;
    }
};
```
