```
/**
*
*整体思路：双指针
*1.令A、B指针分别指向自己的链表头，同时暂存各自头结点
*2.遍历A、B链表，两者都不为NULL时遍历，如果其中一个为NULL，则指向另一个链表头继续遍历
*3.当两者当前节点相同，则证明找到相交的节点
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode * getIntersectionNode( struct ListNode * headA 
                                            , struct ListNode * headB ) {
    
    //if one of the link is NULL, return NULL
    if( headB == NULL || headA == NULL ){

        return NULL;

    }

    //saving the first node of each link
    struct ListNode * tmp_A = headA;
    struct ListNode * tmp_B = headB;

    //if headA and headB neither NULL, continuing visiting
    while( headA != NULL || headB != NULL ){

        //if headA is NULL, but headB is not NULL
        if( headA == NULL ){

            headA = tmp_B;

        }

        //if headB is NULL, but headA is not NULL
        if( headB == NULL ){

            headB = tmp_A;

        }

        //if we find the node both in link A and B
        if( headA == headB ){

            return headA;

        }

        headA = headA -> next;
        headB = headB -> next;

    }

    return NULL;
    
}
```
