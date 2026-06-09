**思路：**
先求出链表长度size，若k取余size为空，那么不用旋转了，直接返回head；否则将链表首尾相连形成环形链表，由于k表示尾节点向右移动`k%size`位，那么头节点向右移动`size-k%size`位，此时的tail移动`size-k%size`位到达新头节点的前驱节点，我们仅仅需要保存新头节点，同时断开链表就好了。

**推荐：**
[力扣刷题总结之链表](https://leetcode-cn.com/circle/article/YGr54o/)

**代码如下**
```cpp
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||k==0)return head;
        ListNode *tail=head;
        int size=1;
        while(tail->next){
            size++;
            tail=tail->next;
        }
        if(k%size==0)return head;
        //首尾相连，形成环形链表
        tail->next=head;
        int m=size-k%size;
        //tail移动m步，到达新头节点的前驱节点
        while(m--)tail=tail->next;
        //tail的next节点为新的头节点，顺便断开环形链表
        ListNode *res=tail->next;
        tail->next=nullptr;
        return res;
    }
};
```
