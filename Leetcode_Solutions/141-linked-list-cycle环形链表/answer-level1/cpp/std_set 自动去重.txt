### 解题思路
此处撰写解题思路
1. 循环遍历链表，分两种情况：
    a. 链表无环， 则head为遍历到NULL， 循环会终止， 返回false；
    b. 链表有环， 则head不会遍历到NULL， while的退出条件始终不成立，通过set来记录结点的数量，当成环的元素加入到set后， set的大小跟加入前的一样， 即set自动去重了。 返回true；

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
    bool hasCycle(ListNode *head) {
        std:set<ListNode*> nset;
        int presize = nset.size(), nextsize = 0;
        while(head) {
            nset.insert(head);
            nextsize = nset.size();
            if (presize == nextsize)
                return true;
            presize = nextsize;
            head = head->next;
        }
        return false;
        

    }
};
```