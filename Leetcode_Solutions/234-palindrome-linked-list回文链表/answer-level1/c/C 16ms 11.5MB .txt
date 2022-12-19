/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
* 主要思路：
* 1.利用快指针移动两个结点，利用慢指针移动一个结点，是慢指针停留在链表中间位置
* 同时把链表前半部分值存在临时缓冲区中
* 2.继续移动慢指针，比较慢指针当前结点的值与临时缓冲区的值
*/

/**
* check the link whether is a Palindrome
* @param: struct ListNode* head, the pointer of the link's header
* retutn: boolean, the result of the function
*/
bool isPalindrome(struct ListNode* head){

    //if the link is NULL, return true
    if( head == NULL ){

        return 1;

    }

    struct ListNode * curr = head;
    struct ListNode * tmp = head;
    int * buf = ( int * )malloc( sizeof( int ) * 1024 * 1024 );
    int len = 0 ;
    
    //use a slower pointer to stop in the mid of the link,
    //use a faster pointer to stop in the end of the link
    //store the element in the buffer
    while( tmp != NULL ){

        *( buf + len ) = curr -> val;
        curr = curr -> next;
        tmp = tmp -> next;

        if( tmp == NULL ){
            break;
        }

        len++;
        tmp = tmp -> next;

    }

    tmp = head;
    len--;
    
    //comparing the element of buffer with the element's value of link
    while( curr != NULL ){

        if( curr -> val != *( buf + len-- ) ){

            return 0;

        }

        curr = curr -> next;
        tmp = tmp -> next;

    }

    return 1;

}