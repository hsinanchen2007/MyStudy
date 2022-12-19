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
    ListNode* 
    removeNthFromEnd(ListNode* head, int n) 
    {
     ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* front = dummy;
        ListNode* behind = dummy;
        for( int i = 0 ; i < n + 1 ; i ++ ){
            front = front->next;
        }
        while(front){
            behind = behind->next;
            front = front->next;
        }
        ListNode* deleteNode = behind->next;
        behind->next = deleteNode->next;
        delete deleteNode;

        ListNode* tempNode=dummy->next;
        delete dummy;                        //new之后最好delete释放动态内存
        
        return tempNode;
    }
};

```在所有 C++ 提交中击败了
100.00%
的用户
内存消耗 :
6 MB
, 在所有 C++ 提交中击败了
100.00%
的用户