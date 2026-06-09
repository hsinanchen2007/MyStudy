### 解题思路
此处撰写解题思路

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
    ListNode* swapPairs(ListNode* head) {
      // 没有节点或者一个节点
      if(NULL == head || NULL == head->next)
      {
          return head;
      }
      // 两个节点
      if(NULL == head->next->next)
      {
          head->next->next = head;
          ListNode* tp = head->next;
          head->next = NULL;
          return tp;
      }
        
      // 多个节点
      ListNode* tail = head->next; // 取到第二个  
      ListNode* tp = head->next->next;
      head->next->next = head;
      head->next = tp;
     
      // 递归其他地方
      tp = tail->next->next;
      ListNode* ttp = swapPairs(tp);
      tail->next->next = ttp;
      return tail;  
    }
};
```
按照多种情况处理,如代码.
递归结束:分为无节点，1节点，两节点以及多节点的处理方案。
递归过程:得到下面的处理结果之后，和原来的链进行拼接.