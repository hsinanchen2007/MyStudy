### 解题思路
先遍历一遍，统计链表长度，再遍历第二遍删除指定位置节点。
![7e42873f2c76797a151eb8bc87469d0.png](https://pic.leetcode-cn.com/4eead0913a9c16ce505f766d55ca646c0db77dc0ae8d4d64ed4b09a31030b6fb-7e42873f2c76797a151eb8bc87469d0.png)

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }
        if(len == n)
            return head->next;
        temp = head; 
        while (len-n-1){
            temp = temp->next;
            len--;
        }
        temp->next = temp->next->next;
        return head;
    }
};
```