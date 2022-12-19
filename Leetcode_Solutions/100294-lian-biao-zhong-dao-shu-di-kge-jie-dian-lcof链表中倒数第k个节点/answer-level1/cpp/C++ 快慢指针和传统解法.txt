### 解题思路
此处撰写解题思路

### 代码
传统解法：
```cpp
/*传统解法*/
class Solution {
public:
       ListNode* getKthFromEnd(ListNode* head, int k) {
              ListNode* p;
              int count = 0;
              p = head;
              while (p)
              {
                     count++;
                     p = p->next;
              }
              p = head;
              count -= k;
              while (count--)
              {
                     p = p->next;
              }
              return p;
       }
};
```

快慢指针解法：
```cpp
//快慢指针，参考剑指offer，算法更好，且增强了代码鲁棒性
class Solution {
public:
       ListNode* getKthFromEnd(ListNode* head, int k) {
              if (head == nullptr || k == 0) return nullptr;//链表为空或者k==0
              ListNode* slow=head, * fast=head;
              for (int i=0;i<k-1;i++)//快指针先走k-1步
              {
                     if (fast->next!=nullptr)//链表中的节点个数少于k个
                     {
                           fast = fast->next;
                     }
                     else
                     {
                           return nullptr;//返回空指针
                     }
                     
              }
              while (fast)//同时走
              {
                     fast = fast->next;
                     slow = slow->next;
              }
              return slow;
       }
};
```