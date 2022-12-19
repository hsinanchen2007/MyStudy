首先说一下我的思路 : 
1. 我们可以不用虚拟头结点进行解题
2. 我们设置两个指针 p 和 q, 让p去指向头结点,我们想一个问题,删除一个结点就要处在这个结点的前一个位置,这样的话我们的循环条件就是p 和 p->next都不为空的时候,如果p 的值和 p->next都值相等时,我们用q去保存 p->next ,之后就行改链 p->next = q->next; 我们释放q,否则 p继续向下走.
3. 记住这里我们为什么是q进行保存的呢, 是为了防止内存泄露,比较严谨一点;
4. 最后返回头结点.
5. 上代码 

```
   struct ListNode *p = head , *q;
    while (p && p->next) {
        if (p->val - p->next->val) {
            p = p->next;
        }else {
            q = p->next ;
            p->next = q->next;
            free(q);
        }
    }
    return head;
```

小伙伴们好好想一想,欢迎有其他的方法教教我!