### 解题思路
使用固定距离为n的两个指针，让l1先走n步，然后l1与l2一起走，直到l1->next为NULL
这时，l2->next即为倒数第n个节点
边界条件：
(1) 删除head节点
(2) n > 总节点数
(3) n <= 0

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
        if(n <= 0) return head;
        ListNode* l1 = new ListNode(-1);
        l1 = head;
        while(n){
            if(!l1) return NULL;
            l1 = l1->next;
            --n;
        }
        if(!l1) return head->next;
        ListNode* l2 = new ListNode(-1);
        l2 = head;
        while(l1->next){
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l2->next->next){
            l2->next = l2->next->next;
        }else{
            l2->next = NULL;
        }
        return head;

    }
};
```

### 结果
执行用时 : 4 ms , 在所有 C++ 提交中击败了 88.02% 的用户 
内存消耗 : 6.2 MB , 在所有 C++ 提交中击败了 100.00% 的用户