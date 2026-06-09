### 解题思路
链表说难不难，说简单也不简单，主要是理清楚各个节点之间的关系！
本题的一次操作中一共涉及到了4个节点：
```
res:当前节点；
node1: res的下一个节点；
node2: node1的下一个节点；
node3: node2的下一个节点。
```
可以看到，一次交换的操作为：
```
res的下一个节点为node2；
node2的下一个节点为node1；
node1的下一个节点为node3;
```
**下一次操作的起始节点为node1.**
按照上面的逻辑，不断执行就可以了！



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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* res = dummy;
        while(res->next && res->next->next){
            ListNode* node1 = res->next;
            ListNode* node2 = node1->next;
            ListNode* node3 = node2->next;
            res->next = node2;
            node2->next = node1;
            node1->next = node3;

            res = node1;
        }
        return dummy->next;
    }
};
```