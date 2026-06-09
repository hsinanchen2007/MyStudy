### 解题思路
看来很多优秀的题解，都改变了输入指针l1,l2。

所以我这索性直接改变了l1,l2的val，减少了很多new ListNode的时间、空间

缺陷是不仅改变了输入指针，还改变了输入指针所指向的值

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = l1;
        char tem_r = 0;

        while (1) {
            tem_r = l1->val + l2->val + tem_r;
            l1->val = tem_r%10;
            tem_r /= 10;

            if(l1->next && l2->next)
            {
                l1 = l1->next;
                l2 = l2->next;
            }
            else
            {
                if(l2->next)//此时l1->next必然为NULL
                    l1->next = l2->next;
                while(l1->next)
                {
                    l1 = l1->next;
                    tem_r = l1->val + tem_r;
                    l1->val = tem_r%10;
                    tem_r /= 10;
                    if(tem_r == 0)
                    {
                        //不会再进位了,则后面的计算都是浪费，提前终止
                        break;
                    }
                }
                if(tem_r)
                    l1->next = new ListNode(tem_r);
                break;
            }
        }

        return res;
    }
};
```