### 解题思路
方法一：暴力法
方法二：哈希表法
方法三：双指针法
方法四：同时遍历法
方法五：栈弹出法
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unsigned int len_A=get_list_len(headA);
        unsigned int len_B=get_list_len(headB);
        if(len_A>len_B)
        {
            headA=forword_long_list(len_A,len_B,headA);
        }
        else
        {
            headB=forword_long_list(len_B,len_A,headB);
        }
        while(headA&&headB)
        {
            if(headA==headB)
            {
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
private:
    //计算list长度
int get_list_len(ListNode *head)
{
    unsigned int len=0;
    while(head)
    {
        len++;
        head=head->next;
    }
    return len;
}

//向前走的步数
ListNode *forword_long_list(int long_len,int short_len,ListNode *head)
{
    int delta=long_len-short_len;
    while(head && delta)
    {
        head=head->next;
        delta--;
    }
    return head;
}
};
```