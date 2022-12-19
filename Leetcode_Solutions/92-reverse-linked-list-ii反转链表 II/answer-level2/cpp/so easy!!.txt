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
    ListNode* reverseBetween(ListNode* head, int m, int n) {

        if(!head || !head->next){
            return head;
        }

        ListNode *tNode = new ListNode(0);
        tNode->next = head;

        ListNode *startNode = tNode;
        ListNode *lastNode = NULL;
        for(int i = 0; i < m - 1; i++){
            startNode = startNode->next;
        }
        lastNode = startNode->next;

        ListNode *preNode = NULL;
        ListNode *curNode = startNode->next;
        ListNode *nextNode = NULL;
        int index = m;
        while(curNode){
            nextNode = curNode->next;
            curNode->next = preNode;
            preNode = curNode;
            curNode = nextNode;
            ++index;
            if (index == n + 1){
                break;
            }
        }
        startNode->next = preNode;
        lastNode->next = nextNode;

        return tNode->next;


    }
};
```