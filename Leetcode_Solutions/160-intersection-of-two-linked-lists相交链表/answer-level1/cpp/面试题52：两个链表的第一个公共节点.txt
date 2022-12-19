### 解题思路
方法一：用set集合的方法
1.遍历链表A，将A中的元素插入集合中。
set.insert(object);
2.遍历链表B，在集合A中查找B中的元素。
set.find(object)!=set.end();
3.直到两个指针相等

时间复杂度：O[N]
空间复杂度：O[N]

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
        std::set<ListNode*> node_set;
        while(headA)
        {
            node_set.insert(headA);
            headA=headA->next;
        }
        while(headB)
        {
            if(node_set.find(headB)!=node_set.end())
            {
                return headB;
            }
            headB=headB->next;
        }
        return NULL; 
    }
};

```

方法二：错位遍历
1.计算两个链表长度，如get_list_len函数
2.把长链表向前移动两个链表的差值
3.同时向前移动，直到两个指针相等

时间复杂度：O[M+N]
空间复杂度：O[1]

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
        int len_A=get_list_len(headA);
        int len_B=get_list_len(headB);
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
    int len=0;
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