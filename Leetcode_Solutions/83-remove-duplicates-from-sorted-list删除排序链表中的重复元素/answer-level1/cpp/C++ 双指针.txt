### 解题思路
使用快慢双指针进行遍历；
+ 如果快指针数据域的值等于慢指针数据域的值，则再次移动快指针
+ 直到快指针数据域的值不等于慢指针数据域的值，那么就对慢指针进行移动，并对慢指针的数据域赋值


```cpp
例如这样一个例子：

原始链表：
1->1->2->3->3->NULL

按照上述快慢双指针的方法进行遍历之后的链表：
1->2->3->3->3->NULL

此时slow慢指针指向第一个3所在的节点，接下来要做的就是删除slow以后的节点
```


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
        if(!head || !head->next) {
            return head;
        }
        // 利用快慢指针完成复制工作
        ListNode* slow = head;
        for(ListNode* fast = head; fast != NULL; fast = fast->next) {
            if(fast->val != slow->val) {
                slow = slow->next;
                slow->val = fast->val;
            }
        }
        // 删除重复多余的节点
        ListNode* p = slow;
        while(p->next) {
            ListNode* tmp = p->next;
            p->next = p->next->next;
            delete tmp;
        }
        return head;
    }
};
```