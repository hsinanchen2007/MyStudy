目前执行4ms~8ms，有一个点不知道怎么优化，望指点。
下面是思路：
`交换过程如下图，不过有一个问题，如果我不在尾结点添加一个与尾结点val值相等的节点，会少输出最后一个值，所以想到这个方法(中间隔断部分代码)来解决。`

`应该还有更好的解决思路，不过还没有想到，希望大佬指点。`

![两两交换链表中的节点.jpg](https://pic.leetcode-cn.com/92a23a05053a56e8a47ad659f641f916cb79e2df33cc629d6a53ae93b3e0d38e-%E4%B8%A4%E4%B8%A4%E4%BA%A4%E6%8D%A2%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B9.jpg)


```

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head -> next == NULL)
            return head;
        ListNode *p = head;         //初始指向头节点
        ListNode *q = head -> next; //初始指向头节点下一节点
        ListNode *newHead = q;      //返回值
        ListNode *t;                //指向q的下一节点

        
```

```
        ListNode *r = head;         //遍历到最后一个节点，用于在尾节点添加一个节点

        while (r -> next){
            r = r -> next;
        }
        ListNode *s = new ListNode(r -> val);//在尾结点添加一个与尾结点val值一样的节点
        r -> next = s;
        s -> next = NULL;
```
        

```
        while (q && q -> next){
            t = q -> next;  //如图①
            q -> next = p;  //如图②
            q = t -> next;  //如图③
            p -> next = q;  //如图④
            p = t;          //如图⑤
        }
        return newHead;
    }
};
```
