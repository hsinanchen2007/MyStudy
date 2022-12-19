### 解题思路
使用递归需要避免思考问题的实现的细节，不需要考虑每一层堆栈的实际情况。只需要去想如何分解一个大问题即可
实际的编写是在一个巨大的假设之下的，代码展现的仅是最后一步。前面的n-1步假设已经执行完毕。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
  if(head==NULL||head->next==NULL) return head;
  struct ListNode*p=reverseList(head->next);
  head->next->next=head;
  head->next=NULL;
  return p;
}
```