### 解题思路
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :5.4 MB, 在所有 C 提交中击败了100.00%的用户

1.定义一个while循环，遍历，获取链表长度
2.定义一个for循环，执行p = p->next
3.注意：for循环执行n-k次
4.return p->val

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int kthToLast(struct ListNode* head, int k){
    struct ListNode*p;
    p = head;
    int n = 0;
    int i;
    while(p){
        ++n;
        p = p->next;
    }

    p = head;
    for(i=0;i<n-k;i++){
        p = p->next;
    }
    //p->next = NULL;
    return p->val;
}
```