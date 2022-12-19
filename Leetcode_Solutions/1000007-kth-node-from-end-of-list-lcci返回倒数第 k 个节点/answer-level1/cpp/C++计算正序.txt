### 解题思路
![image.png](https://pic.leetcode-cn.com/99665cb09603dbad89db7579d7a0c9ab643d4e2fd0fb8edb72fd91997e380fae-image.png)

1）用一个ListNode* node 先遍历一遍，计算链表长度
2）利用长度和倒序k计算正序
3）用head正序遍历到要取的位置

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
    int kthToLast(ListNode* head, int k) {
        ListNode* node = head;
        int num=0;
        while(node)
        {
            num++;
            node = node->next;
        }

        k = num - k ;
        while(k>0)
        {
            head = head->next;
            k--;
        }
        return head->val;
    }
};
```