### 解题思路
12 ms打败84.86%，7.3MB,打败100%。参照题解思路来的

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
 //快慢指针
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *meet=NULL;  
        while(fast){
            fast = fast->next;
            slow = slow->next;
            if(!fast)//特判，链表只有一个元素返回null
                return NULL;
            //第一次相遇
            fast = fast->next;//现在fast走两步了，slow一步
            
            if(fast == slow)
            {
                meet = fast;//把相遇的节点记下来
                break;
            }
        }      
        if(meet == NULL)
            return NULL;       
        while(head && meet)
        {
            if(meet == head)
                return head;
            meet = meet->next;
            head= head->next;
        }
        return NULL;
        


        
    }
};
```