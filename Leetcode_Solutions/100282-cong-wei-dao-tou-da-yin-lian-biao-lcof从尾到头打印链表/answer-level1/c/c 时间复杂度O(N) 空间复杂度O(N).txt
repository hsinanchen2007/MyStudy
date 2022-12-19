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
*1.第一次遍历链表，计算出链表长度*returnSize
*2.申请长度为*returnSize的动态缓冲区buffer
*3.第二次遍历链表，依次从缓冲区buffer后面开始存放对应的链表结点数据
*4.返回buffer
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * reversePrint( struct ListNode * head , int * returnSize ) {

    //the parameter of curr used to visit link
    struct ListNode * curr = head;

    //intializing the value of *returnSize
    *returnSize = 0;

    //calculating the length of link
    while( curr != NULL ){

        *returnSize += 1;
        curr = curr -> next;

    }

    //alloclating memory to save the final result
    int * buffer = ( int * )malloc( sizeof( int ) * ( *returnSize ) );
    int i = 0;

    //saving the value of node to buffer
    while( head != NULL ){

        *( buffer + *returnSize - i++ - 1 ) = head -> val;
        head = head -> next;

    }

    //returning buffer
    return buffer;

}
```
