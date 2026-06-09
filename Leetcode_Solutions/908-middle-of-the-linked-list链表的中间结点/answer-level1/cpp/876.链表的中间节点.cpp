### 解题思路
快慢指针的方法

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
 //可以用快慢指针法,一个走一步，一个走两步
 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        while(!head)//链表为空
        {
            return NULL;
        }
        ListNode* slow_node=head;//设置快慢指针
        ListNode* fast_node=head;
       
        while(fast_node->next)//快慢指针同时遍历链表,这里是fast_node是因为它走的快
        {   
            slow_node=slow_node->next;
            fast_node=fast_node->next;
            while(!fast_node->next)
            {
                return slow_node;
            }
            fast_node=fast_node->next;
        }
        return slow_node;
    }
};
```