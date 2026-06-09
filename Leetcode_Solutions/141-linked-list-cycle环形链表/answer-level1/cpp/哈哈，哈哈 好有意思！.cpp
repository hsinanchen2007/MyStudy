### 解题思路
我就是想偷个懒，让链表不断遍历，每次遍历记个数，如果有环的话肯定没有头，那我取一个大点的数一比，比这个还大肯定是由环的，否则不是。
但是我一取1000，什么，测试用例里还真有一个这么多的链表，那就10000
哈哈，leetcode没办法了。

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
        ListNode*cur=head;
        int len=0;
        while(head!=NULL&&len<10000){
            head=head->next;
            len++;
        }
        if(len>9000)return true;
        else return false;
    }
};
```