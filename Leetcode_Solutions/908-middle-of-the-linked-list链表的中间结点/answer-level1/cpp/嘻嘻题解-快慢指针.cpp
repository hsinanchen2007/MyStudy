
### 解题思路

快慢指针！很典型的一道使用快慢指针的题。

定义两个指针fast 和 slow ，fast一次走两步，slow一次走一步，当fast走到尾节点，slow指向中间节点。

**有几个点需要注意哦**

**由于fast指针指向head，head若为空则直接退出循环，输出空指针，所以不用进行head为空判断**

在判断循环条件时要注意 `fast != nullptr && (fast->next)!=nullptr` 要同时判断空值~


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
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr)return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && (fast->next)!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
```