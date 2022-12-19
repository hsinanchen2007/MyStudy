### 解题思路

原本代码没有用哑节点（哨兵？），因此需要单独考虑第一个节点

```c
    //获取第一个节点
    if ( l1->val < l2->val ){
        new_node = l1;
        l1 = l1->next;
    } else{
        new_node = l2;
        l2 = l2->next;
    }
    new_head = new_node;
```

后来参考了官方的答案， 使用哑节点，解决了首节点的问题。

```c
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *cur = dummy;
```

同时，之前还傻傻地遍历了不为空的链表，后来看了官方题解，原来直接搭个指针就行了, 省了两端的while。

```c
cur->next = ( l1 == NULL) ? l2 : l1;
```

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    //考虑输入为NULL
    if ( l1 == NULL && l2 == NULL) return NULL;
    if ( l1 == NULL && l2 != NULL) return l2;
    if ( l2 == NULL && l1 != NULL) return l1;
    //哑节点
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *cur = dummy;
    while( l1 != NULL && l2 != NULL){
        if ( l1->val > l2->val){
            cur->next = l2;
            l2 = l2->next;
        }  else{
            cur->next = l1;
            l1 = l1->next;
        }
        cur = cur->next;
    }
    cur->next = ( l1 == NULL) ? l2 : l1;
    return dummy->next;

}


```

![image.png](https://pic.leetcode-cn.com/d19facc9edf43b12f3537e146cb0073a9c42d7e41692e816499a37f22268795d-image.png)
