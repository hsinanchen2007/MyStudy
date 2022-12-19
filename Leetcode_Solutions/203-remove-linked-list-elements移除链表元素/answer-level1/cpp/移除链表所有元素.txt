### 解题思路
* 先处理移除的数字在链表开头的情况,此外，还要考虑其重复的可能,这一步操作直接移动head;
* 处理中间及之后元素的方法为，如果发现一个元素的下个元素的val等于要删除元素，就定义一个指向下个元素的指针，在该指针非空的前提下，若它的next的val等于要删除元素，则使它前进，即等于它的next，直到它为空或者其val不为要删除的val

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode*temp = head,*pre = head;
        while(temp){
            if(temp->val == val){
                temp = temp->next;
                head = temp;
            }
            else{
                if(temp->next&&temp->next->val == val){
                    ListNode * last = temp->next;
                    while(last&&last->val == val){
                        last = last->next;
                    }
                    temp->next = last;
                }
                temp = temp->next;
            }
        }
        return head;
    }
};
```