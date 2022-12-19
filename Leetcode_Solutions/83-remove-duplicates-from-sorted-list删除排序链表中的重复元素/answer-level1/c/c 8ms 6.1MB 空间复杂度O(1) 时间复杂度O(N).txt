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
*1.如果链表长度<2,直接返回head
*2.暂存前一个节点的信息，用于删除重复节点时重新连接
*3.如果当前节点不为NULL，
*  当前节点curr和前一个节点form进行比较，判断是否重复，如果重复，直接删除节点curr，进入下一个节点
*  如果不重复，更新form为curr，同时移动curr到下一个节点
*4.重复3步骤
*5.返回head
*/


struct ListNode * deleteDuplicates( struct ListNode * head ){

    //if the length of link is less than 2, returning head
    if( head == NULL || head -> next == NULL ){

        return head;

    }

    //the parameter of form used to save former node
    //the parameter of curr used to save current node
    struct ListNode * form = head;
    struct ListNode * curr = head;
    curr = curr -> next;

    while( curr != NULL ){

        //if the value of current node equals to the value former node, deleting current node
        //do not updating former node
        if( form -> val == curr -> val ){

            form -> next = curr -> next;
            curr = curr -> next;
            continue;

        } 
        
        //updating former node
        form = curr;
        curr = curr -> next;

    }
    
    return head;

}
```
