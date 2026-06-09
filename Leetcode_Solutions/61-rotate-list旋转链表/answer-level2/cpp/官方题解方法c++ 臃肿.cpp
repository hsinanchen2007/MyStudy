加油

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
    ListNode* rotateRight(ListNode* head, int k) {
        // ListNode* dummyHead = new ListNode(0);
        // dummyHead->next = head;
        // // 计算长度，如果k大于链表长度，直接取模。
        // int len =0;
        // ListNode* cur = dummyHead->next;
        // while(cur != NULL){
        //     len++; cur = cur->next;
        // }
        // if(len == 0) return dummyHead->next;
        // k = k % len; // 粗心，除法的时候一定要注意除零错误
        // while(k--){
        //     ListNode* cur = dummyHead->next;
        //     while(cur ->next != NULL){
        //         if(cur->next->next == NULL){
        //             ListNode* tmp = cur->next;// 最后一个
        //             cur->next = NULL; // 倒数第二个的next = NULL
        //             ListNode* phead = dummyHead->next;// 头结点
        //             dummyHead->next = tmp; // 头结点换成最后一个
        //             tmp->next = phead; // 最后一个的下一个 等于之前的头结点
        //             break;
        //         }
        //         cur = cur->next;
        //     }
        // }
        // return dummyHead->next;


        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        // 计算长度，如果k大于链表长度，直接取模。
        int len =0;
        ListNode* cur = dummyHead->next;
        while(cur != NULL){
            len++; 
            if(cur -> next == NULL){
                cur->next = dummyHead->next; // 形成环
                break;
            }
            cur = cur->next;
            // if(cur)
        }
        if(len == 0) return NULL;
        k = k % len;
        int cnt = 0;
        cur = dummyHead->next;
        while(cur != NULL){
            cnt ++;
            if(cnt == len - k ){
                dummyHead->next = cur->next;
                cur->next = NULL;
                break;
            }
            cur = cur->next;
        }
        
        return dummyHead->next;

    }
};
```
