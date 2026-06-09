![)9NF0S~IU~K_U(K853A8OQI.png](https://pic.leetcode-cn.com/d2c11b79eb3b9f7865c9d2502737addb9190c893fe96e74507d7a150fcc25d94-\)9NF0S~IU~K_U\(K853A8OQI.png)

```
/**
* 整体思路：利用两层循环，第一层循环用于确定合值为0的起始结点，
*           第二层循环用于确定合值为0的结束结点
* 
*   1.由头结点开始判断，
*       如果头结点为0，立即删掉结点，头结点指针指向下一个结点，把当前结点指针指向下个结点
*       循环判断，直到头结点不为0
*   2.移动当前结点累加求和，
*       如果和为0，删除起始结点和结束结点之间的所有结点，
*       如果合值结束结点指针指向链表最后一个结点，结束内层循环
*   3.移动当前结点到下一个结点，循环1步骤，直到为NULL，退出循环
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
* removing the elements that the result of summarise is zero
* @param: struct ListNode* head, the pointer of the link's header
* return: struct ListNode*, the pointer of the link's header
*/
struct ListNode* removeZeroSumSublists(struct ListNode* head){

       /*if the link is NULL return NULL.*/
    if( head == NULL ){

        return NULL;

    }

    struct ListNode * curr = head;
    /*if the current node is not head node, linking former node
    with the next node. */
    struct ListNode * form = curr ;

    while( curr != NULL ){

        struct ListNode * subCurr = curr ;
        int sum = 0 ;

        while( subCurr != NULL ){

            sum += ( subCurr -> val ) ;

            if( sum == 0 ){

                if( curr == head ){

                    /*when delete the head node, you should meake                       sure the current pointer points the head node*/
                    head = subCurr -> next;
                    curr = subCurr -> next;

                } else {

                    /*linking the former node with next node*/
                    form -> next = subCurr -> next;

                }

            }

            /*moving subcurrent node to the next*/
            subCurr = subCurr -> next;

        }

        if( curr != NULL ){

            /*before moving to next node, you sure make sure                                    current not NULL,then, former pointer points current*/
            form = curr ;
            curr = curr -> next;

        }

    }

    return head;

}
```
