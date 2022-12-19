![题解.png](https://pic.leetcode-cn.com/82418165c65b9f8cd48b50e686162ff1a22c38514aa312a56c688791c691833e-%E9%A2%98%E8%A7%A3.png)


```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pre = new ListNode(-1);       //因为头节点可能会被删除所以先申请一个头前结点
        pre->next = head;                       //头前结点自然指向头结点
        head = pre;                             //pre一会还得用所以头节点更新一下
        ListNode* moving = head->next;          //当然我们遍历从原始头解点开始
        bool needDelete = false;                //然后得有一个标志确定当前结点是不是历史遗留问题
        while(moving)
        {
            if(moving->next && moving->next->val == moving->val)  //如果下一结点的值等于当前结点
            {                                                     //删了就完事了
                ListNode* tmp = moving->next;
                moving->next = tmp->next;
                delete tmp;
                tmp = nullptr;
                needDelete = true;              //把当前结点标志为历史遗留问题
                continue;                       //当前结点先不往后更新了
            }
            if(needDelete)                      //有历史遗留问题就把历史遗留问题解决了
            {
                pre->next = moving->next;
                delete moving;
                moving = pre;
                needDelete = false;
            }
            pre = moving;                       //遍历下一个结点前存下当前结点
            moving = moving->next;              //遍历下一个结点
        }
        pre = head;                             //头前结点拿回来释放掉
        head = head->next;
        delete pre;
        pre = nullptr;
        return head;
    }
};
```
还有不是很明白好多人不释放空间，那不是相当于没删，不会导致内存泄露吗