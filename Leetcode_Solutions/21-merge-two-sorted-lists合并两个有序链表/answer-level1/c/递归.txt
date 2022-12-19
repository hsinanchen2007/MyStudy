### 解题思路
参考官方题解，我太菜了，一看就会，一写就错

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 递归
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    // 递归出口条件
    if ( !l1 ) {    // l1遍历完了
        return l2;
    }
    else if ( !l2 ) {   // l2遍历完了
        return l1;
    }
    else if ( l1 -> val <= l2 -> val ) {
        l1 -> next = mergeTwoLists( l1->next, l2 );
        return l1;
    } 
    else {
        l2 -> next = mergeTwoLists( l1, l2->next );
        return l2;
    }
}
```