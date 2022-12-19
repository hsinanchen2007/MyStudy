### 解题思路
虽然执行时间和内存消耗结果不堪入目，但至少是我第一次不看题解自己写出来的哈哈哈！
表示纪念。

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
        if(headA == NULL || headB == NULL) //若有结点为空，则必然无交点
          return NULL;
        
        ListNode *p1 = headA;
        ListNode *p2 = headB;

        map<ListNode*,int> Harsh; // 哈希表，标记每一次遍历的结点
        
        while(p1 != NULL || p2 != NULL) // 先标记以head1为头结点的链表
                                        // 再遍历以head2为头结点的链表
                                        // 若无交点，则跳出循环
        {
            if(Harsh[p2] == 1) // 表示有交点，因为如果存在交点，再一次遍历就已经标记过了
              return p2;

            if(p1 == NULL) // 一次遍历结束，则开始第二次遍历
            {
                Harsh[p2]++;
                p2 = p2 -> next;
            }
            else // 第一次遍历
            {
                Harsh[p1]++;
                p1 = p1 -> next;
            }

        }
        
        return NULL;
    }
};
```