### 解题思路
* 维护奇数链的“头”与偶数链的“头”
* 双指针交叉遍历后续结点
* 最后退出循环情况：偶数个结点时，tmpOdd==NULL；奇数个结点时，tmpEven==NULL

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)    return head;

        ListNode *oddFirst = head;
        ListNode *evenFirst = head->next;
        ListNode *tmpOdd = head;
        ListNode *tmpEven = head->next;

        while(tmpOdd && tmpEven) {
            tmpOdd->next = tmpEven->next;
            tmpOdd = tmpOdd->next;
            if(tmpOdd) {
                tmpEven->next = tmpOdd->next;
                tmpEven = tmpEven->next;
            }
        }
        // 修改奇数链拼接偶数链
        if(tmpOdd)  tmpOdd->next = evenFirst;   // 有奇数个结点
        else {  // 有偶数个结点
            for(oddFirst; oddFirst->next; oddFirst = oddFirst->next){}
            oddFirst->next = evenFirst;
        }
        return head;
    }
};
```