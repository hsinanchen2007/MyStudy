### 解题思路
此处撰写解题思路
执行用时 :
8 ms
, 在所有 C++ 提交中击败了
90.03%
的用户
内存消耗 :
10.3 MB
, 在所有 C++ 提交中击败了
100.00%
的用户
因为只有指向下一个的指针，所以设置了一个a来记录找到数字的那个位置的上一个位置然后把a的下一个指向下下个，这样中间那个就被删除了。同时也要保证第一个位置，把第一个数据的位置记录下来为b，这才能输出
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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode*a;
        ListNode*b;

        if(head->val==val)
        return head->next;
        else
        {
            b=head;
        

        while(head->val!=val)
        {
            a=head;

            head=head->next;


        }
        a->next=head->next;
            return b;
            
            }




    }
};
```