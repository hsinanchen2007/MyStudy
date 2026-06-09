
做链表题,个人经验就是,不管简单还是复杂,比较通用步骤

1. 定义三个变量,curr_node,pre_node,next_node分别指代当前处理的节点,上一个节点,下一个节点.

   因为链表题的运算逻辑,本质上就是在调整和更新这三者之间的关系.

2. 如果不确定返回链表的头结点会不会为输入链表头结点,则new一个ghost节点,把运算结果往这个ghost节点的后面接.

3. 最终返回值就是ghost->next.不过要注意释放堆空间.****

```cpp
    ListNode* deleteDuplicates(ListNode* head) {
        if(nullptr==head||nullptr==head->next) return head;
        ListNode* curr_node=head; //当前节点
        ListNode* nex_node=head->next;//下一个节点
        ListNode* pre_node=new ListNode(0);//不知道头指针的情况下,先定义一个头,满足要求的节点在后面接着
        ListNode* pre=pre_node;//上一个有效节点
        int currVal=head->val;//当前节点比较值
        while(nullptr!=nex_node){
            if(nex_node->val==currVal){//下一个节点和当前值比较
                curr_node=nullptr;//如果相同,则当前值所对应节点就得删除,做标志位
                nex_node=nex_node->next;//然后循环看后面还有米有等于当前值的节点
            }else if(nullptr==curr_node){  //说明后面这个节点的值已经和当前值不相等,通过是否为空,
                                            //可以知道这里的下一个节点是不是最后一个相等值节点后的节点
                curr_node=nex_node;//如果是,那么当前节点就直接跳到这个新节点
                currVal=nex_node->val;//更新当前值
                nex_node=nex_node->next;//继续取后续节点判断

            }else{//当前节点值,只有一个
                pre->next=curr_node;//所以可以连接在上一个有效节点后面
                pre=pre->next;//更新上一个有效节点
                curr_node=nex_node;//更新当前节点
                currVal=curr_node->val;//更新需要比较的当前节点值
                nex_node=nex_node->next;//更新下一个节点
            }
        }
        pre->next=curr_node;//把当前节点添加在上一个有效节点后面,最后的节点连续相等,自然就是连接在上一有效节点的为空,否则就是当前节点
        head=pre_node->next;//为了释放new的空间
        delete pre_node;
        return head;
    }
```
