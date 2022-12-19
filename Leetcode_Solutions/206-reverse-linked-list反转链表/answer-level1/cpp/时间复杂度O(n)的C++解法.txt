### 解题思路
通过三个指针来，反转；
三个指针分别保存当前遍历节点、当前遍历节点的左侧节点、当前便利节点的右侧节点；
# 代码执行效果
时间复杂度：O(n)
空间复杂度：O(1)
执行用时 :
12 ms, 在所有 C++ 提交中击败了27.52%的用户
内存消耗 :8.3 MB, 在所有 C++ 提交中击败了100.00%的用户
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
    ListNode* reverseList(ListNode* head) {
        //0,1个节点时候无需反转
        if(head==nullptr)       return nullptr;
        if(head->next==nullptr) return head;
        ListNode *pNext=head;            //用来遍历每个节点
        ListNode *leftNode=nullptr;           //用来保存当前遍历节点的左侧节点
        ListNode *rightNode=pNext->next;     //用来保存当前遍历节点的右侧节点
        while(rightNode!=nullptr)
        {
            pNext->next=leftNode;
            leftNode=pNext;
            pNext=rightNode;
            rightNode=rightNode->next;
        }
        pNext->next=leftNode;
        head=pNext;
        return pNext;
    }
};
```