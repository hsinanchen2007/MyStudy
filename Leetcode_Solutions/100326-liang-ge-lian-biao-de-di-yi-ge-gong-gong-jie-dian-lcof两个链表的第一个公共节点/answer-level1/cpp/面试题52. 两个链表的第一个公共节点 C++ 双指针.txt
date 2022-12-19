### 解题思路
如果有交点，那么交点及交点之后的所有节点都应该相同。

可以使用双指针，快指针先对较长的链表遍历，当遍历到和较短的链表相同长度时再一起便利

当两个指针遇到的第一个相同的节点时，即为公共节点

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

        if(!headA || !headB) return nullptr;
        int lenA = 0;
        int lenB = 0;

        ListNode* pA = headA;
        while(pA){
            // 遍历headA，计算链表A的长度
            pA = pA->next;
            ++lenA;
        }
        ListNode* pB = headB;
        while(pB){
            // 遍历headB，计算链表B的长度
            pB = pB->next;
            ++lenB;
        }

        int lenLong, lenShort;
        ListNode* longHead;
        ListNode* shortHead;
        // lenLong记录较长链表的长度，lenShort记录了较短链表的长度
        if(lenA > lenB){
            lenLong = lenA;
            longHead = headA;
            lenShort = lenB;
            shortHead = headB;
        }
        else{
            lenLong = lenB;
            longHead = headB;
            lenShort = lenA;
            shortHead = headA;
        }

        // 较长的节点先遍历
        int lenMore = lenLong - lenShort;
        while(lenMore){
            longHead =longHead->next;
            --lenMore;
        }

        // 此时后面的节点数目相同，就开始遍历，直到找到一个相同的节点
        ListNode* res = nullptr;
        while(longHead){
            if(longHead == shortHead){
                res = longHead;
                break;
            }
            else{
                longHead = longHead->next;
                shortHead = shortHead->next;
            }
        }
        
        return res;

    }
};
```