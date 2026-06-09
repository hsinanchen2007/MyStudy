```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int getListLenth(struct ListNode* lst){
    struct ListNode* tmp = lst;
    int len = 0;
    while(tmp != NULL){
        len ++;
        tmp = tmp ->next;
    }
    return len;
}
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* p = head;
    node -> next = NULL;
    while(p != NULL){
        struct ListNode* tmp = p -> next;
        p -> next = node -> next;
        node -> next = p;
        p = tmp;
    }
    return node ->next;
}
bool isPalindrome(struct ListNode* head){
    int len = getListLenth(head);
    int mid = len / 2;
    if(len % 2 != 0){
        mid += 1;
    }
    struct ListNode* p = head;
    struct ListNode* q = head;
    while(mid > 0){
        q = q -> next;
        mid --;
    }
    q = reverseList(q);
    mid = len / 2;
    while(mid > 0){
        if(p -> val != q -> val){
            return false;
        }
        p = p -> next;
        q = q -> next;
        mid --;
    }
     return true;
}
```
