![image.png](https://pic.leetcode-cn.com/630188718dab8dae1457d1972a3dddf18c45d40ee8e927aa2488a09d45c6fe04-image.png)

解题思路：

1 增加头节点，方便对第一个节点操作

2 找到第m个节点和其前节点 ，第n个节点

3 截取下来m到n这段链表

4 把截取下的链表中的节点逐个插入原链表
```
struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if(m == n)return head;
    struct ListNode *p = head, *q = p, *s, *pre;
    struct ListNode *prehead = (struct ListNode*)malloc(sizeof(struct ListNode));
    prehead -> val = NULL;
    prehead -> next = head;
    pre = prehead;
    int i = 1;
    while(i < m)
    {
        pre = p;
        p = p -> next;
        q = q -> next;
        i++;
    }
    while(i < n){
        q = q -> next;
        i++;
    }
   
    int k = n - m;
    pre -> next = q; //截取 让第m - 1个节点指向第n个节点 
    while(k--){      // 从m节点开始到n - 1节点 逐步插入到n节点之后
        s = p -> next;
        p -> next = q -> next;
        q -> next = p;
        p = s;
    }

    return prehead -> next;
}
```
