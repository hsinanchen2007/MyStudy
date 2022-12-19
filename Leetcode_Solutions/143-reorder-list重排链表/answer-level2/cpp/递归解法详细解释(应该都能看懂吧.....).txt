1. 参考大佬,自己改了一下.
2. 注释感觉已经清楚了.
3. 更多题解,详见我的博客 https://blog.csdn.net/qieyuan4083/article/details/104338538
4. 欢迎一起交流学习.
```
    class Solution {
    public:
        ListNode* helper(ListNode* head, int len) {
            //len更容易递归到终止条件.
            if(len==1) return head;
            if(len==2) return head->next;
            //返回head->next,len-2,即除去头尾节点的上一个
            //重排的尾部节点.
            ListNode* tail = helper(head->next, len-2);
            //画图容易理解.tmp为重排之前的最后一个节点.
            ListNode* tmp = tail->next;
            //头尾头尾顺序连接链表.
            //注意tail->next应该连接他之后的节点,
            //这样才能不停递归.
            tail->next = tail->next->next;
            tmp->next = head->next;
            head->next = tmp;
            //返回重排后链表的尾部节点.
            return tail;
        }
        void reorderList(ListNode* head) {
            if(head==NULL || head->next==NULL) return;
            int len = 0;
            ListNode* cur = head;
            while(cur!=NULL) {
                len++;
                cur = cur->next;
            }
            //helper函数的作用是给定头结点和对应的链表长度,
            //返回重排链表的最后一个节点.
            ListNode* tail = helper(head, len);
        }
};
```
