![_YW$H(0NBA\[_6CIO_YY}ZU1.png](https://pic.leetcode-cn.com/fc6827565faa0e5f10008e4f79d69fea2cae9807c482fbcbe9bf7862edce2748-_YW$H\(0NBA%5B_6CIO_YY%7DZU1.png)

/**
*思路：
*1.情况一：如果节点匹配
*2.情况二：如果在链表中匹配
*3.情况三：链表结尾匹配
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){

    if( head == NULL ){
        return NULL;
    }
    //point the former node in the list
    struct ListNode* form = head ;
    //point the current node in the list
    struct ListNode* curr= head ;

    //compare the first node with the param val 
    while( head != NULL && head -> val == val ){

        head = head ->next ;

    }

    //compare the nodes which among the list with the param val
    while( curr -> next != NULL ){
        
        if( curr -> val == val ){

            //do not move the former pointer to the current node,
            //just link former node to the next node
            form -> next = curr -> next;

        } else {

            //move the former pointer to the current node
            form = curr ;

        }

        //keep move next node
        curr = curr -> next;

    }

    //compare the last node's val with the param val
    if( curr -> val == val ){

        form -> next = NULL;

    }

    return head;
}