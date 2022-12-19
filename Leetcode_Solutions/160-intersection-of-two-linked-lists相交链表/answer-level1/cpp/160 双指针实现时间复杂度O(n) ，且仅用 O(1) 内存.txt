### 解题思路
注意：刚开始要判断两个链表是否有空链表
为了满足 O(n) 时间复杂度，且仅用 O(1) 内存，需要用到两个指针，也就是官方提到的解法三。
![image.png](https://pic.leetcode-cn.com/e0cc5de26ef3ca84187b67363876d9993ae1d6db090c47d5865aa11687f126dd-image.png)

### 代码

```cpp
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA==nullptr || headB==nullptr)
            return nullptr;
        ListNode *pA = headA, *pB = headB;
        while (pA != pB) {
            pA = pA->next;            
            pB = pB->next;
            if (pA==nullptr && pB==nullptr)
                return nullptr;
            if (pA == nullptr)
                pA = headB;
            if (pB == nullptr)
                pB = headA;
        }
        return pA;
    }
};
```