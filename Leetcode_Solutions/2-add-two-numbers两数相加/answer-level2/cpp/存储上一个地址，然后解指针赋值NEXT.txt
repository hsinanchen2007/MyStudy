### 解题思路
特殊情况特殊处理，当都不为空时进行加法，如果超过10，则记录标志位，下一次相加进行补位；另外            
            if (retNodeOld->next != NULL)
            {
                ListNode* temp = (ListNode*)retNodeOld->next; //解指针 将next赋值
                temp->next = tempNode;
            }
最为关键，相当于利用old记录指针，解指针后，再对它的next赋值，这样子链表就连起来了。

不喜勿喷！

执行用时 :
24 ms
, 在所有 cpp 提交中击败了
94.27%
的用户
内存消耗 :
10.3 MB
, 在所有 cpp 提交中击败了
82.54%
的用户

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
       if (l1 == NULL || l2 == NULL)
        {
            return NULL;
        }
        ListNode* line1 = l1;
        ListNode* line2 = l2;

        ListNode *retNode = new ListNode(NULL);
        retNode->val = NULL;
        retNode->next = NULL;

        ListNode *retNodeOld = new ListNode(NULL);
        retNodeOld->val  = NULL;
        retNodeOld->next = NULL;

        while (line1 != NULL || line2 != NULL || retNodeOld->val == 1)
        {
            ListNode *tempNode = new ListNode(NULL);
            tempNode->val = NULL;
            tempNode->next = NULL;

            if (line1 == NULL && line2 != NULL)
            {                    
                if (retNodeOld->val == 1) 
                {
                        tempNode->val = line2->val +retNodeOld->val;
                }else
                {
                    tempNode->val = line2->val;
                }
                line2 = line2->next;
            }else if(line2 == NULL && line1 != NULL)
            {
                if (retNodeOld->val == 1) 
                {
                   tempNode->val = line1->val +retNodeOld->val;
                }else
                {
                   tempNode->val = line1->val;
                }
                
                line1 = line1->next;
            }else if (line1 != NULL && line2 != NULL)       
            {
                //如果上一个 相加大于10 则本次应多+1
                if (retNodeOld->val == 1)
                {
                     tempNode->val = line1->val + line2->val + retNodeOld->val;
                }else
                {
                     tempNode->val = line1->val + line2->val;
                }
               
                line1 = line1->next;
                line2 = line2->next;
            }else
            {
                tempNode->val = retNodeOld->val;
            }

            if (retNodeOld->next != NULL)
            {
                ListNode* temp = (ListNode*)retNodeOld->next; //解指针 将next赋值
                temp->next = tempNode;
            }
            
            retNodeOld->next = tempNode;

            if (tempNode->val >9)
            {
                tempNode->val = tempNode->val%10;
                retNodeOld->val = 1; //赋值
            }else
            {
                retNodeOld->val = 0; //赋值
            }

            if(retNode->next == NULL)retNode->next = tempNode;

            //
        }
        return retNode->next;
    }
};
```