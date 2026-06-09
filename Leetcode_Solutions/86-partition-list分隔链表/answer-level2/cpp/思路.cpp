### 解题思路
一种插入排序
需要找到插入的前一个节点位置，每次需要更新，条件是pre小于，cur大于或者等于
如果还没有找到这个节点，就需要一直继续遍历

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
    ListNode* partition(ListNode* head, int x) {
      if(!head || !head->next)  return head;
      //初始化fake节点小于x，这样可以确定第一个节点是否是起始被插入节点
      ListNode* fake = new ListNode(x - 1);
      fake->next = head;
      ListNode* cur = head;
      ListNode* pre = fake;
      ListNode* first = fake;
      bool find = false;

      while(cur){
        if(pre->val < x && cur->val >= x){
          first = pre;
          find = true;
        }

        if(cur->val < x && find){
          ListNode* tmp = first->next;
          first->next = cur;
          pre->next = cur->next;
          cur->next = tmp;
          first = cur;
          cur = pre->next;
          continue;
        }
      
        pre = cur;
        cur = cur->next;
      }

      return fake->next;
    }
};
```