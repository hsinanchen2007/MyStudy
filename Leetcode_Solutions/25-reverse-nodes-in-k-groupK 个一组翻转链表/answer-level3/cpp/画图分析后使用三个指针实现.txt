链表相关的问题大多可以在纸上画一画，仔细分析一下，使用双指针等小技巧基本上就解决了。

和之前两两交换链表节点的解法一脉相承，代码如下：
```
void reverse(ListNode *pre, ListNode *left, ListNode *right)
{
    if (pre != nullptr)
        pre->next = right;
    pre = right->next;
    while (left != right)
    {
        ListNode *tmp = left->next;
        left->next = pre;
        pre = left;
        left = tmp;
    }
    left->next = pre;
}


ListNode* forward(ListNode *node, int k)
{
    int count = 0;
    while (count < k && node != nullptr)
    {
        node = node->next;
        count++;
    }
    
    return node;
}


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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr)
            return nullptr;
        if (k == 1)
            return head;
        
        ListNode *left = head;
        ListNode *right = forward(head, k - 1);
        if (right == nullptr)
            return head;
        head = right;

        ListNode *pre = nullptr;
        while (right != nullptr)
        {
            reverse(pre, left, right);
            
            pre = left;
            left = left->next;
            right = forward(left, k - 1);
        }
        
        return head;
    }
};
```

执行用时 : 28 ms, 在所有 cpp 提交中击败了79.94%的用户。  
内存消耗 : 9.6 MB, 在所有 cpp 提交中击败了94.42%的用户。  
