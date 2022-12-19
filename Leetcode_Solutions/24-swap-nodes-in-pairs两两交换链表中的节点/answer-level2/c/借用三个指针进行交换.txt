思路：借用三个指针记录指针对应位置，进行交互，比较简单

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* pre = head;
    struct ListNode* left = head;
    struct ListNode* right = NULL;

    if(head == NULL)
        return NULL;
    if(head->next == NULL){
        return head;
    }else{
        right = left->next;
    }
    head = right;
     while(right != NULL){
         //先把pre放到第二组的头上
         if(right->next == NULL){
             left->next = NULL;
             right->next = left;
             break;
         }
         if(right->next != NULL && right->next->next == NULL){
            left->next = right->next;
            right->next = left;
            break;  
         }
         pre = right->next;
        //让前两个反转
         right->next = left;
         left->next = pre->next;
         //移动到下一组数据
         left = pre;
         right = pre->next;
     }
    return head;
}