### 解题思路
执行用时 :52 ms, 在所有 C++ 提交中击败了85.11%的用户
内存消耗 :16.8 MB, 在所有 C++ 提交中击败了49.36%的用户
具体做法代码注释中已经写明，关键点在于让长链表步进step个节点，然后再遍历

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
            return nullptr;

        // 计算两链表节点个数，并计算节点个数之差
        ListNode* node1 = headA;
        ListNode* node2 = headB;
        int count1 = 0;
        int count2 = 0;
        while(node1)
        {
            node1 = node1->next;
            count1++;
        }     
        while(node2)
        {
            node2 = node2->next;
            count2++;
        }            
        int step = (count1 > count2) ? (count1-count2):(count2-count1);        

        // 首先让长链表步进step个节点，使长短链表长度相等
        // 然后让两链表按1步进，判断步进后的节点是否相等
        ListNode* short_list = (count1 > count2) ? headB : headA;
        ListNode* long_list = (count1 > count2) ? headA : headB;
        for(int i = 0; i < step; i++)
            long_list = long_list->next;
        while(short_list != nullptr )
        {
            if(short_list == long_list)
                return short_list;
            short_list = short_list->next;
            long_list = long_list->next;
        }
        return nullptr;
    }
};
```