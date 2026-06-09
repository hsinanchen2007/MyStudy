### 解题思路
方法很多，花里胡哨都有

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      if(!head || !head->next)  return head;
      ListNode* fakeHead = new ListNode(-1);
      fakeHead->next = head;
      ListNode* cur = head->next;
      ListNode* pre = head;
      //确定第一个节点是不是可以当头结点，first用来连接每个不一样的节点
      ListNode* first = cur->val == pre->val ? fakeHead : head;

      while(cur){
        //找到不一样的节点，比如1112223，这样就可以直接找到3
        while((cur && cur->val == pre->val) || (cur && cur->next && cur->val == cur->next->val)){
          pre = cur;
          cur = cur->next;
        }

        first->next = cur;
        first = cur;
        pre = cur;
        //比如111222，最后一个cur是NULL，这边就不可以在next，反正他下一次循环也会跳出，所以继续是NULL
        cur = cur != NULL ? cur->next : cur;
      }

      return fakeHead->next;
    }
};
```