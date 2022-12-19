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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) //若没有链表，返回空
        {
            return NULL;
        }
        if(lists.size()==1)//若只有一个链表，直接返回这个链表
        {
            return lists[0];
        }
        if(lists.size()==2)//若有两个链表，进行合并，并返回合并后的链表
        {
            ListNode *head=new ListNode(0);
            ListNode *s=head;
            ListNode *p=lists[0];
            ListNode *q=lists[1];
            while(q&&p)
            {
                if(p->val<=q->val)
                {
                    s->next=p;
                    s=s->next;
                    p=p->next;
                }
                else
                {
                    s->next=q;
                    s=s->next;
                    q=q->next;
                }
            }
            if(p)
            {
                s->next=p;
            }
            else
            {
                s->next=q;
            }
            return head->next;
        }
        else//如果有两个以上的链表，分成一半进行处理
        {
            int mid=lists.size()/2;
            vector<ListNode*>left(lists.begin(),lists.begin()+mid);//左半部分
            vector<ListNode*>right(lists.begin()+mid,lists.end());//右半部分
            ListNode *leftl=mergeKLists(left);//左半部分进行合并操作
            ListNode *rigehtr=mergeKLists(right);//右半部分进行合并操作
            vector<ListNode*>result;
            result.push_back(leftl);
            result.push_back(rigehtr);
            return mergeKLists(result); //合并合并后的左右两部分
        }
    }
};
```