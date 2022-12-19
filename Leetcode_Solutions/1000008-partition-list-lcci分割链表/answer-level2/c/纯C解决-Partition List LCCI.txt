### 解题思路

题目给Medium，我觉得不太妥，没啥难点，就是要求我们把小于x的全部放在前面，我想了一下，这个不就是经典的头插法嘛?

只是说这里需要考虑一个小问题，我不清楚大家使用的头插法是什么样子的，但是我可以很肯定的是绝大部分的伙伴都是用我的这种头插法，直接把一个节点插在了头节点的后面，头插法其实存在一个漏洞
```
插入的位置和pre下一个位置是同一个位置
```
那么为什么会说有BUG呢？我们来看看
经典的头插法应该我是这个样子
```
//假设p是待插入的元素,new_head是头节点,pre是指向p的前驱
pre->next=p->next;
p->next=new_head->next;
new_head->next=p;
p=pre->next;
```
看起来似乎是很完美的操作,但是我们的理想中，我们应该是把p这个元素插入到了pre前面去了,可能不太好理解，我们举个反例，如果插入的元素的位置就是原来的位置，比如说：
```
new_head-->1-->2--> 3-->4,x=2
pre此时应该是new_head,p=1这个节点
我们把p插入其实还是p本身的位置，p此时后继的指向结果是它自己了,2-->3-->4这段链表就被丢弃了。因为p没办法找到2所在的节点了。
```
此时又有伙伴会想：
```
问题是2的节点找不到了,那么我用一个q节点来保存p的后继，那么就不会丢弃
```
是的，但是又会有其他的问题你的pre就会很有可能找不到p的前驱节点。可以用下面这个例子：
```
1-->2-->3-->2->2-->2,x=3;
```
解决方案：
```
1.对首元素单独分析
2.额外列一个链表
```
以上分析了这么多，我不知道大家会不会觉得我没必要分析这么多，我只是喜欢把一个问题尽可能的分析清楚，方便自己也方便别人~当然，大神勿喷







### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    if(!head||!head->next)
    return head;
    //自建头节点
    struct ListNode *new_head=(struct ListNode *)malloc(sizeof(struct ListNode));
    new_head->next=head;

    struct ListNode *pre=new_head;
    while(head&&head->val<x)//单独分析头节点
    {
        pre=head;
        head=head->next;
    }
    while(head)
    {
        if(head->val<x)//目标
        {
            pre->next=head->next;
            head->next=new_head->next;
            new_head->next=head;
            head=pre->next;
        }
        else
        {
            pre=head;
            head=head->next;
        }
    }
    return new_head->next;
}
```