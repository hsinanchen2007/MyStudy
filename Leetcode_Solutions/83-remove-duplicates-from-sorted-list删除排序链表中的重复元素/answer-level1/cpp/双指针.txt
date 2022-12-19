### 解题思路
1.快指针遍历整个链表
2.慢指针确定是否连接慢指针的节点
注意：最后一部分可能出现重复元素自动连接的情况，需要做个判断删除

![image.png](https://pic.leetcode-cn.com/7954507bedf1651aa1e0ac25371769ed0bad6ec3c29dee6feb6d0b2043e65301-image.png)
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
class Solution{
public:
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode* ptr = new ListNode(0);
            ListNode* first = ptr;
            first->next = head;
            first = first->next;
            ListNode* second = head;
            if(second==NULL) return head;
            int temp1 = second->val;
            while (second->next!=NULL) {
                if(second->next->val!=temp1){
                    first->next = second->next;
                    first = first->next;
                    temp1 = first->val;
                }
                else {

                }
                second = second->next;
                
            }
            if(second->val==temp1){
                first->next = NULL;
            }
            return ptr->next;
        }
};
```