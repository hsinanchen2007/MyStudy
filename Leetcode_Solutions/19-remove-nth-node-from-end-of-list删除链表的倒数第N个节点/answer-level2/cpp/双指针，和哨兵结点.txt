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
//第二种
//使用双指针，这样只需要遍历一次,两个指针之间有n个结点
//这个方法里面，我们设置了哑结点dummy
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);//头哨兵
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
        for(int i = 0 ; i <= n ; i++)
        first = first->next;
        while(first != nullptr)
        {
            first = first->next;
            second = second->next;
        }
        auto temp = second->next;
        second->next = second->next->next;
        delete temp;
        temp = nullptr;
        return dummy->next;
    }
};
```