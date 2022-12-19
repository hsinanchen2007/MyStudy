### 解题思路
构建双循环，判断两个链表是否相等。

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
    //第一个公共节点，说明后面的数据也是相等的才对；
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //搞个循环就行了
        while(headA!=NULL){
            ListNode* temp = headB;
            while(temp != NULL){
                if(headA == temp) return temp;
                temp = temp->next;
            }
            headA = headA->next;
        }
        return headA;
    }
};
```