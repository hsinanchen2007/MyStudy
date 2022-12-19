### 解题思路
LeetCode菜鸟第一次写题解，有点激动。
这道题还是很简单的，由于我们不能修改两个分区指针的相对位置，那么最直观的方式就是再创建两个链表，然后再遍历原链表，并按顺序把节点进行分类；
但这样做就有点浪费空间了，那么就可以直接在原链表上进行操作：维护两个头节点，分别指向两个分区的第一个节点，然后还要维护当前遍历后每个分区的尾部指针，然后如果在下一次遍历时，将遇到的节点正确加到对应分区的尾部，然后修改这个尾部指针即可。因为我们永远修改的是前面已经遍历过了的节点之间的指针，所以不用担心会破坏尚未遍历的指针。
不知道讲清楚没有，代码应该还算比较好理解。

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
    ListNode* partition(ListNode* head, int x) {
        ListNode *temp = head, *p1 = NULL, *p2 = NULL;
        ListNode *firstLess = NULL, *firstNotLess = NULL;

        while(temp != NULL){
            if(temp->val < x){
                if(firstLess == NULL){
                    firstLess = temp;
                    p1 = firstLess;
                }else{
                    p1->next = temp;
                    p1 = p1->next;
                }
            }else{
                if(firstNotLess == NULL){
                    firstNotLess = temp;
                    p2 = firstNotLess;
                }else{
                    p2->next = temp;
                    p2 = p2->next;
                }
            }
            temp = temp->next;
        }
        if(p2 != NULL)
            p2->next = NULL;
        if(p1 != NULL)
            p1->next = firstNotLess;
        
        if(firstLess)
            return firstLess;
        else
            return firstNotLess;
        
    }
};
```