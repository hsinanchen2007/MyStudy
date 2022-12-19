### 解题思路
大概就是反转链表，不过每次k个节点，注意节点的断开和重连就好了

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
    ListNode* reverse(ListNode* head){
      if(!head || !head->next)  return head;

      ListNode* pre = NULL;
      ListNode* cur = head;

      while(cur){
        ListNode* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
      }

      return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
      if(k == 0 || k == 1 || !head || !head->next)  return head;

      ListNode *fakeHead = new ListNode(-1);
      fakeHead->next = head;
      //pre and cur
      ListNode* pre = fakeHead;
      ListNode* cur = head;
      //tmp head to reverse k node
      ListNode* first = pre;
      int cnt = k;

      while(cur){
        pre = cur;
        cur = cur->next;
        cnt--;
        //reverse linklist
        if(cnt == 0){
          //cut linknode temporary
          pre->next = NULL;
          first->next = reverse(first->next);
          cnt = k;
          //update first point
          while(cnt){
            first = first->next;
            cnt--;
          }
          //reconnect linklist
          first->next = cur;
          pre = first;
          cnt = k;
        }
      }

      return fakeHead->next;
    }
};
```