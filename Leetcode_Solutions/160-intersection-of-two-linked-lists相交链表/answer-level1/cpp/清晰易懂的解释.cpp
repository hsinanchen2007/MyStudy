### 解题思路
![image.png](https://pic.leetcode-cn.com/2c31ecb5962c093480dcf6fd161e01e0184566360dd32d56b916471bfbdf6f61-image.png)

借高赞大神的思路：
设长链表的“非共有部分”为a,短链表“非共有部分”为b，设“共有部分”为c。
我们看一个式子：
 **a+c + b+c = b+c + a+c** 
并且**a+c+b = b+c+a**
1.当长链表走完全部(即a+c)时，去短链表从头开始走。
2.当短链表走完全部(即b+c)时，去长链表从头开始走。
**当1中，走到短链表的末尾时，此时两个指针距离公共节点的距离都是c**

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
        if(headA == nullptr || headB == nullptr)return nullptr;
        ListNode* pa = headA;
        ListNode* pb = headB;
        while(pa!=pb){
            pa=pa==nullptr?headB:pa->next;
            pb=pb==nullptr?headA:pb->next;
        }
        return pa;
    }
};
```