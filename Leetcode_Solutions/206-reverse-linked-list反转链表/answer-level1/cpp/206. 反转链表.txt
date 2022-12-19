### 解题思路
方法一：
循环
执行用时：8 ms
内存消耗：9.5 MB
1. 设置两个指针，一个指向前一个指针pre，一个指向当前指针cur
![微信图片_20200322103255.jpg](https://pic.leetcode-cn.com/744d1bc8290268dcf536235fca908633a1cc23f279912e543221676d1803de3f-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200322103255.jpg)
方法二：
递归

### 代码

方法一：
```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* cur=head;
        while(cur){
            ListNode* tmp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=tmp;
        }
        return pre;
    }
};
```

方法二：
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
    ListNode* reverseList(ListNode* head) {
        //递归
        return revers(NULL,head);
    }
    ListNode* revers(ListNode* pre,ListNode*cur){
        if(cur==NULL)return pre;
        ListNode* tmp=cur->next;
        cur->next=pre;
        return revers(cur,tmp);
    }
};
```