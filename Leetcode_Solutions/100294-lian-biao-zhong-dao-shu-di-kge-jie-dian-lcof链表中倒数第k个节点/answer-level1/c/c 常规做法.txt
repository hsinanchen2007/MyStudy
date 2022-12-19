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
*1.首先计算链表长度len
*2.清空计算器count，遍历链表，如果计数器count+k==len，返回当前结点，否则移向下一个节点
*3.返回NULL
*/ 


struct ListNode * getKthFromEnd( struct ListNode * head , int k ){

    //the parameter of len is the length of len
    //the parameter of count used to calculate the node that have been visited
    int len = 0 , count = 0;
    struct ListNode * curr = head;

    //calculating the length of link
    while( curr != NULL ){

        len++;
        curr = curr -> next;

    }

    while( head != NULL ){

        //if count + k == len , returning current node
        if( count + k == len ){

            return head;

        }

        count++;
        head = head -> next;

    }

    return NULL;

}
```
