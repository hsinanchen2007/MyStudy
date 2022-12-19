### 解题思路
此处撰写解题思路

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return nullptr;
        ListNode *darkNode = new ListNode(-1);  //哑节点
        darkNode->next = head;
        ListNode *preNode = darkNode;
        ListNode *Node = head;
        while(Node)
        {
            if(Node->next && Node->val==Node->next->val)
            {
                //有重复值
                int dupValue = Node->val;  //记下当前重复值，全部删除
                while(Node && Node->val==dupValue)
                {
                    ListNode *deleteNode = Node;
                    Node = Node->next;
                    delete deleteNode;
                }
                preNode->next = Node;
            }
            else
            {
                preNode = Node;
                Node = Node->next;
            }
        }
        return darkNode->next;
    }
};
```