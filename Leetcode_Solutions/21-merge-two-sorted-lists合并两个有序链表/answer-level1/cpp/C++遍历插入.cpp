### 解题思路
//刚看完数据结构的链表部分，做这个题做的心态崩了。
//谁在跟我说C++指针特别有趣我就跟谁急
![图片2.jpg](https://pic.leetcode-cn.com/31ae6a864adcfefdf8e31925ca066a4dbe7913b8bf5a392126dee80f3192a0b1-%E5%9B%BE%E7%89%872.jpg)

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL||l2==NULL)
        {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        }
        ListNode *temp = NULL;
        if(l1->val>l2->val)    //判断头指针对应的val，使l1指向大的链表
        {
            temp = l1;
            l1 = l2;
            l2 = temp;
        }
        ListNode *rec = l1;     //操作l1链表，记录l1的头指针
        while(l1!=NULL&&l2!=NULL)
        {
            if(l1->next==NULL)     //l1遍历到最后一个节点，直接指向l2链表剩下的部分。
            {
                l1->next=l2;
                l1=NULL;
            }
            else if(l2->val>=l1->val&&l2->val<=l1->next->val)
            {
                temp = l2->next;
                l2->next = l1->next; //l2置于l1之后
                l1->next = l2;
                l1 = l2;
                l2 = temp;                                    //遍历l1,l2，将l2的值依序插入l1 
            }
            else
            {
                l1 = l1->next;
            }
        }
        return rec;   //返回l1链表
    }
};
```