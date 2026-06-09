### 解题思路
依次相加即可

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 习惯上不想修改题目给的变量值，所以创建了两个新的指针 l1Node 和 l2Node 。实际上可直接使用 l1 和 l2。

struct ListNode * addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode * returnList = NULL, *l1Node = l1, *l2Node = l2, *rearNode = returnList;
    int carry = 0;
    while (l1Node || l2Node) {
        struct ListNode *tempNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (l1Node && l2Node) {
            tempNode->val = l1Node->val + l2Node->val + carry;
            l1Node = l1Node->next;
            l2Node = l2Node->next;
        } else if (l1Node) {
            tempNode->val = l1Node->val + carry;
            l1Node = l1Node->next;
        } else {
            tempNode->val = l2Node->val + carry;
            l2Node = l2Node->next;
        }
        carry = tempNode->val / 10;
        tempNode->val = tempNode->val % 10;
        if (returnList == NULL) {
            returnList = rearNode = tempNode;
            tempNode->next = NULL;
        } else {
            rearNode->next = tempNode;
            rearNode = tempNode;
            tempNode->next = NULL;
        }
    }
    if (carry != 0) {
        rearNode->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        rearNode = rearNode->next;
        rearNode->val =carry;
        rearNode->next = NULL;
    } // 如果两个链表长度相同时，会发生循环已结束但 carry 不为 0 的情况，这时要另外插入一个结点。
    return returnList;
}
```