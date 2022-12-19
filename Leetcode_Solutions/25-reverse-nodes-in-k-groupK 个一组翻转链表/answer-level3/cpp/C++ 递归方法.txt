

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
            return NULL;
        ListNode* cur = head; 
        ListNode* pre = NULL;
        int count = k;
        while(count && cur) { //判断剩余节点数量是否足够k个
            cur = cur->next;
            count--;
        }
        if(count != 0) //不足k个，返回当前表头
            return head;  
        else{ //足够k个节点，进行递归操作
            pre = reverseKGroup(cur, k); //cur指向k+1节点，返回后续链表处理后的表头
            while(count != k) { //k个节点依次反转
                cur = head;
                head = head->next;
                cur->next = pre;
                pre = cur;
                count++;
            }
        }
        return cur;
    }
};