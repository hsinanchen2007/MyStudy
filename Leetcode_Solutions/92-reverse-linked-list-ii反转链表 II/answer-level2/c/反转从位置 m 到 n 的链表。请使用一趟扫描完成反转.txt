### 解题思路
**这道题可以使用顺序表的解题方法，通过空间换取时间的方法在O(N)的时间复杂度内完成**
1. 查找到m位置，并记录m位置
2. 通过栈记录到n的数据
3. 将栈中的数据取出赋给从m位置开始的节点
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if(head == NULL || m > n)
        return false;
    int stack[10240];
    int top = -1;
    struct ListNode* p = head;
    struct ListNode* q;

    for(int i = 0; i < m-1; i++){
        p = p->next;
    }
 
    q = p;
    for(int i = 0; i < n-m+1;i++){
        stack[++top] = p->val;
        p = p->next;
    }
    while(top != -1){
        q->val = stack[top--];
        q = q->next;
    }
    return head;
}
```