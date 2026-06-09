### 解题思路
此处撰写解题思路
1. 查询得到两个链表长度
2. 求出最小的比对长度
3. 将较长链表的指针移到到和较短的链表一样长
4. 比对两个链表节点，一致，找到，不一致，两个链表都向后移动

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
        int len1 = 0;
        int len2 = 0;

        ListNode * a = headA;
        ListNode * b = headB;
        ListNode * ret = NULL;

        while (a != NULL) {
            a = a->next;
            len1++;
        }

        while (b != NULL) {
            b = b->next;
            len2++;
        }

        if(len1 == 0 || len2 == 0) {
            return ret;
        }

        a = headA;
        b = headB;

        int x = 0;
        int min = 0;
        int i = 0;

        if(len1 >= len2) {
            x = len1 - len2;
            min = len2;
            for (i = 0; i < x; i++) {
                a = a->next;
            }
        } else {
            x = len2 - len1;
            min = len1;
            for (i = 0; i < x; i++) {
                b = b->next;
            }
        }

        for (i = 0; i < min; i++) {
            if(a == b && a!= NULL) {
                ret = a;
                break;
            } else {
                a = a->next;
                b = b->next;
            }
        }
        return ret;
    }
};
```