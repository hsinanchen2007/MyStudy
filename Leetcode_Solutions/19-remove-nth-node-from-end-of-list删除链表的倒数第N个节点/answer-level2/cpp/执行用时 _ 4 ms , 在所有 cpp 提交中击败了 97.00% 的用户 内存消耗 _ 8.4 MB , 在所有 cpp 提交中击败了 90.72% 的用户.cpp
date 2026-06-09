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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* del_node = head;
        ListNode* run_node = head->next;
        ListNode* fore_node = head;
        int count = 1;
        while(run_node!=NULL){
            if(count<n){
                count++;
                run_node = run_node->next;
            }
            else{
                fore_node = del_node;
                del_node = del_node->next;
                run_node = run_node->next;
            }
        }
        if(fore_node==del_node){
            return head->next;
        }
        else{
            fore_node->next = del_node->next;
            del_node->next = NULL;
            delete del_node;
        }
        return head;
    }
};
```
设置count计数，在count<3时均默认头结点head即为要删除的del_node,当count>=3后，用pre_node记录del_node，然后del_node后移，然后用run_node当前判断到的结点,当run_node==NULL时退出循环，此时的del_node即为要删除的节点。
一次通过，小开心