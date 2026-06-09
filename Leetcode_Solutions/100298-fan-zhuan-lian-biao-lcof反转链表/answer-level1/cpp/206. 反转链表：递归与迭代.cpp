### 解题思路
* 迭代：使用了新建链表。空间复杂度O(n);
* 递归：只是修改了next指针。空间复杂度O(1);

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
    // 迭代
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;    // 空链表直接返回NULL

        ListNode *h = new ListNode(head->val);
        ListNode *tmp = head->next;
        while(tmp) {        // 迭代反转
            ListNode *t = new ListNode(tmp->val);
            t->next = h;
            h = t;
            tmp = tmp->next;
        }
        return h;
    }
};
```
![1.png](https://pic.leetcode-cn.com/e7243870d0cedf960267067a90a26da52b603366d70f084b1dd895108c4ed510-1.png)

```cpp
// 递归
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        ListNode *h = NULL;
        reverseNode(head, h);
        return h;
    }
    void reverseNode(ListNode *node, ListNode *&h) {
        if(node == NULL)
            return ;
        ListNode *tmp = node->next;
        node->next = h;
        h = node;
        reverseNode(tmp, h);
    }
```
![2.png](https://pic.leetcode-cn.com/fa874e3e1130d1456c03567fe502240921805062def13d6c28730a42559a5e75-2.png)
