#### 链表的题**一定一定**要画图（此处省略我的图）
***
###### 首先看到这道题时先想一下反转整个链表的做法，双指针很容易理解，记录相邻的两个节点指针，迭代就行，我们着重解决只反转一部分怎么做。
###### 画图可知反转一部分后，需要将一开始的第m个节点的next指向第n+1个节点，将第m-1个节点（如果存在的话）的next指向第n个节点，函数返回head节点（如果`m!=1`的话）或者第n个节点。具体见代码：
```
/**
 * 执行用时 : 0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
 * 内存消耗 : 7.8 MB, 在所有 C++ 提交中击败了 100.00% 的用户
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==nullptr || m==n) return head; //空树或者只反转一个节点没必要操作
        //pre记录m-1个节点，mth记录第m个节点
        ListNode *pre=nullptr, *mth=nullptr, *cur=nullptr, *next=head, *tmp=nullptr;
        int count=0;
        while(next!=nullptr && count<n)
        {
            tmp = next->next;
            //这时next指向的第m个节点，如果`m==1`的话pre是空的
            if(count==m-1) pre = cur; 
            if(count==m) mth = cur;
            //从next指向m+1个节点、cur指向m个节点开始有反转
            if(count>=m) next->next = cur;
            //迭代
            cur = next;
            next = tmp;
            count++;
        }
        //将第m个节点的next指向第n+1个节点
        mth->next = next;
        //将第m-1个节点的next指向第n个节点
        if(pre) pre->next = cur;
        //如果`m==1`，pre就是空的，第n个节点就是头节点
        return pre ? head : cur;
    }
};
```

###### PS: 递归感觉比迭代更难理解，没搞