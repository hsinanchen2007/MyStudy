![image.png](https://pic.leetcode-cn.com/220cb190ac2a462439010fcf1ed94555325622a5089293c01995d1b1aadc23c6-image.png)
```
# 头插法
struct ListNode* reverseKGroup(struct ListNode* head, int k){

    if (!(head)||!(head->next)) return head;//特殊情况

    struct ListNode *L = (struct ListNode *)malloc(sizeof(struct ListNode));//构造新链表
    struct ListNode *p=head;//p,q两指针作为原链表遍历用
    struct ListNode *q=head;
    L->next = NULL;
    struct ListNode *rear=L;//新链表尾指针
    struct ListNode *phead=L;//新链表头指针

    int cnt=0;
    while(p)//得出单链表的长度
    {
      cnt++;
      p=p->next;
    }

    p=head;//从表头开始遍历
    while(p)
    {
        if(cnt<k)//退出循环
          break;
        else
        {
            int i;
            for(i=0;i<k;i++)//进行k次头插结点
            {
                q=p;
                p=p->next;  
                q->next=phead->next;
                phead->next=q;
                if(i==0)//记录尾指针
                  rear=q;
            }
            phead=rear;//头插K个结点后这时链表的头指针位置应该移动到尾指针上，为下一轮头插做准备
            cnt-=k;
        }
    }
    if(p)//不为整数倍的特殊情况
     rear->next=p;

    return L->next;
}

```
# 就地排序，构造一个虚拟头结点
```
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if (head == NULL || head->next == NULL) {//特殊情况
        return head;
    }
    //创建一个虚拟头节点，避免链表头节点需要区分处理
    struct ListNode *L = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *tmphead = head;
    L->next = head;
    head = L;//此时head为虚拟头结点


    //获取链表长度
    int cnt = 0;
    while (tmphead != NULL) {
        cnt++;
        tmphead = tmphead->next;
    }

    int i;
    struct ListNode *prev, *now, *tmp;
    while (point != NULL) {
        //判断剩下的节点数量是否足够
        if (cnt < k) {
            break;
        }
       //指定K个节点逆转
        tmphead = NULL;
        prev = L->next;
        now  = L->next->next;
        for (i=0; i<k; i++) {
            prev->next = tmphead;//就地逆置k个结点
            tmphead = prev;
            prev = now;
            if (now != NULL) {
                now = now->next;
            }
        }
        //处理后的prev指针指向第K+1个节点或NULL
        //串联下部分节点：原第1个节点，现第K个节点，指向第K+1个节点或NULL
        L->next->next = prev;
        //暂存第K个节点（尾节点）
        tmp = L->next;
        //串联上部分节点，第一次操作时head指针对应临时节点的后继节点为链表的头节点
        L->next = tmphead;
        //point指针指向第K个节点，作为下一轮K个节点的临时前继节点
        point = tmp;
        //重新计算可用的剩余节点数量
        cnt -= k;
    }
    //释放虚拟头节点
    tmp = head;
    head = head->next;
    free(tmp);
    return head;
}

```
