### 解题思路
![无标题.png](https://pic.leetcode-cn.com/7fe7d87f5c4cfec447b87f2e234904990a952848750b0b083636278beda0f223-%E6%97%A0%E6%A0%87%E9%A2%98.png)

大一下学的C++，当时学的咧咧呛呛，连滚带爬。现在回首捡一下，哈哈。
学数据结构时讲插入排序的前提是顺序存储。整个顺序表呈现出左侧有序、右侧无序的状态。并且需要移动元素腾位置。在这里就是将这个思想转换一下--**不需移动元素位置，判断合理位置即可**。
头节点的引入简化了部分操作，当时许老师一直强调这一点，但是当时数据结构学的更多的是理论，自己也是强行记忆。今天有所体现。
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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* p = new ListNode(0);
        p->next = head;
        while(head != NULL&&head->next != NULL)
        {
            if(head->val <= head->next->val)
                head = head->next;
            else
            {
                ListNode* pre = head->next;
                head->next = pre->next;
                ListNode* q = p;
                while(q->next->val <= pre->val)
                    q = q->next;
                pre->next = q->next;
                q->next = pre;
            }
        }
        return p->next;
    }
};
```