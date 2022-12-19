### 解题思路
本题和之前的环形链表不一样的地方在于相遇后，还要找到起始节点。
按之前的想法，进行双指针，一快一慢，就可以最终相遇（如果有环）。
问题的难点在于相遇后，怎么找头节点：
我自己最初的想法是搞一个**map**来存每个节点的次数；
当走第二遍的时候，快慢通速，如果map记录的节点值为2的话，就是头节点。
这个方法的问题在于，数据可能是重复的，这个时候map就不起作用了。

按照大佬们的想法，最终整明白了为什么当相遇后，在走a步就走到了头节点。
因此，直接再相遇后，再让快指针从头开始走，和慢指针同速，走a步后，肯定就走到了初始结点。

双指针的快乐真是奇妙无穷啊！


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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        if(!head) return head;
        //让慢的转一圈
        map<int,int> index;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;  
            if(fast == slow){
                fast = head;
                while(fast != slow){
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }             
        }
        return NULL;
    }
};
```