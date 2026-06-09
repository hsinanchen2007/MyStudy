### 解题思路

使用快慢指针，用于将链表的前半部分进行反转。

需要考虑到链表的数目的奇偶型

如果是偶数个, 条件是 `fast->next == NULL`

如果是奇数个，条件是 `fast == NULL`

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



bool isPalindrome(struct ListNode* head){
    //空节点, 一个节点, 两个节点
    if ( head == NULL || head->next == NULL){
        return true;
    }
    struct ListNode *cur = head, *res=NULL, *fast = head;

    while (  true  ){
        if ( fast == NULL){
            break;
        }
        if (fast->next == NULL){
            head = head->next;
            break;
        }
        fast = fast->next->next;
        head = head->next;
        cur->next = res;
        res = cur;
        cur = head;
    }
    while ( head != NULL && res != NULL){
        if (head->val != res->val){
            return false;
        }
        head = head->next;
        res = res->next;
    }

    return true;

}
```