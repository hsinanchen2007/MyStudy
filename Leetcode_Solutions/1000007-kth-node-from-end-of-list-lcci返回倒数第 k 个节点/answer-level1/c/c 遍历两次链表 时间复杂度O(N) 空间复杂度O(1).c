```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
*
*整体思路：
*1.第一次遍历链表，计算出链表长度len
*2.第二次遍历时，计算当前序号count加上k是否等于len，如果等于，直接返回t -> val
*/

int kthToLast( struct ListNode * head , int k ){

    int len = 0 , count = 0;
    struct ListNode * t = head;

    while( t != NULL ){

        len++;
        t = t -> next;

    }

    t = head;

    while( t != NULL ){

        if( count + k == len ){

            return t -> val;

        }

        count++;
        t = t -> next;

    }

    return 0;


}
```
