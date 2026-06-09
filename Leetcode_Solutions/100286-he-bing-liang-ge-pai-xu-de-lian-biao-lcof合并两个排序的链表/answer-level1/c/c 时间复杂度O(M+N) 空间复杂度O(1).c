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
*整体思路：将l2结点依次插入l1中
*1.如果l1为NULL，直接返回l2
*2.如果l2为NULL，直接返回l1
*3.判断l1和l2的头结点大小，如果l2头结点小于l1头结点，更新l1头结点，更新form指向的位置
*4.循环遍历l1和l2，满足两者均不为NULL，则进入步骤5，否则进入步骤7
*5.如果当前的结点curr->val大于等于l2->val，则将l2暂存tmp,插入curr位置，同时更新l2 = l2 -> next , * form = tmp；如果curr->val小于l2->val，则form更新为curr，同时curr指向下一个结点，
*6.进入步骤4
*7.如果l2!=NULL,则将所有l2添加到form后面
*8.返回头结点l1
*/

struct ListNode * mergeTwoLists( struct ListNode * l1, struct ListNode * l2 ){

    //if l1 is NULL, returning l2
    if( l1 == NULL ){

        return l2;

    }

    //if l2 is NULL, returning l1
    if( l2 == NULL ){

        return l1;

    }

    //the parameter of curr points to current node in l1
    //the parameter of form points to former node of curr in l1
    struct ListNode * curr = l1;
    struct ListNode * form = l1;

    //if the value of head in l1 bigger than the value of head in l2, updating the head
    if( l2 != NULL && l1 -> val >= l2 -> val ){

        struct ListNode * tmp = l2;
        //updating l2
        l2 = l2 -> next;
        //appending current node in l2 to l1
        tmp -> next = l1;
        //updating l1 and form
        l1 = tmp;
        form = tmp;

    }

    while( curr != NULL && l2 != NULL ){

        //if the value of current node in l1 bigger than that in l2, updating l1 and l2
        if( curr -> val >= l2 -> val ){

            struct ListNode * tmp = l2;
            l2 = l2 -> next;
            form -> next = tmp;
            tmp -> next = curr;
            form = tmp;

        } else {
            
            //if the value of current node in l1 smaller than the value of l2, continuing
            form = curr;
            curr = curr -> next;

        }


    }

    //if l2 is not NULL, appending the rest of node in l2 to l1
    if( l2 != NULL ){

        form -> next = l2;

    }

    return l1;

}
```
