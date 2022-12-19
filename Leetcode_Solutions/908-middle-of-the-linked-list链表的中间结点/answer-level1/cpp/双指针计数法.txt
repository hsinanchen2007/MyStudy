### 解题思路
tail指针指向当前遍历链表的最后一个元素，另外用mid指针指向当前遍历时的中间节点，count用来计数，tail指向第偶数个节点的时候，mid后移，指向奇数个节点的时候不改变位置。

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
    ListNode* middleNode(ListNode* head) {
        //遍历链表，返回中间节点的指针
        ListNode *mid = head;
        ListNode *tail = head;
        int count = 1;
        while(tail->next!=NULL){
            tail = tail->next;
            count++;
            if(count%2==0){
                mid = mid->next;
            }
        }
        return mid;
    }
};
```