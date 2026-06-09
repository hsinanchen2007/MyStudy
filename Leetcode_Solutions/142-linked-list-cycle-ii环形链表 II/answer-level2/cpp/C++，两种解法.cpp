### 解题思路
1.使用set保存，出现重复则返回；
这里一开始纠结的是，如果值相同，对set来说算不算相同的节点，应该是不算的，因为数据结构的定义包含了next；
2.快慢指针，知道可以找到环，但是如何用相遇的节点找到第一个入环节点，我本来想着是从头结点开始，把环走一遍，但是复杂度很大；
看了解答发现有数学兴致；
### 代码1,set

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
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> pool;
        while(head!=NULL){
            if(pool.count(head)) return head;
            else pool.insert(head);
            head=head->next;
        }
        return NULL;
    }
};
```
### 代码2,快慢指针
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
    ListNode* detectCycle(ListNode* head) {
        ListNode* fastPtr=head, *slowPtr=head;
        // 让fast与slow指针第一次相遇
        while (fastPtr!=NULL && fastPtr->next!=NULL)
        {
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
            if (fastPtr==slowPtr)
            {
                // 从相遇点再走“非环部分长度”一定可以再次走到环起点
                fastPtr = head;
                while (fastPtr != slowPtr)
                {
                    fastPtr = fastPtr->next;
                    slowPtr = slowPtr->next;
                }
                return fastPtr;
                break;
            }
        }

        return nullptr;
    }
};
```
