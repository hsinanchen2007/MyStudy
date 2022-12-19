# 写在前面
好久没有重新刷题了，最近突然觉得自己代码水平急速下降，别的东西做的多了，因而想来这里刷刷题目，希望回复一下手感。[CSDN](https://blog.csdn.net/XIVIVV/article/details/105154674)上是我的cpp代码，基本一模一样

-------------

# 解题思考
刚开始做这道题的时候苦思冥想，怎么样能够一次遍历就找到倒数第n个节点呢？我始终觉得是不可能的。后来我发现一个指针确实不能完成这样的事情，那两个指针呢？两个指针中间相距的间隔为n，不就可以了吗？

说干就干，我当即创建了两个指针，一个指针`ptr`指向遍历过的最后一个节点，另一个指针`delayN`指向`ptr`的前`n`个节点。这样，我们就能直接通过`delayN	`指针找到倒数第`n`个节点了！

然而，实际操作和理论的思索还是有一些区别的，因为我发现，由于要删除节点，我们需要锚定`delayN`在倒数`n+1`位置的节点，那么这时候会出现两种可能：
1. 倒数第`n`个节点实际上是头节点；
2. 倒数第`n`个节点不是头节点。

例如：`1->2->3`这样一个链表，`1`和`3`之间的距离是2，如果`n = 3`那么`delayN`和`ptr`的距离就必须是`distance = 3`，这显然是不可能的。想解决这个问题，那么两个指针之间的距离则会有两种可能：
1. 指针间的距离是`n-1`；
2. 指针间的距离是`n`。

接下来的思路就清晰了，将`ptr`锚定到最后一个节点，并在`ptr`后移的时候判断指针之间的距离，如果`distance = n`，则两个指针同时后移，如果`distance < n`则只有`ptr`后移。这样做之所以成立是因为题目里告诉我们`n`必然有效，所以我可以放心大胆的移。

因为`n`必然有效，因此当`ptr`移到最后一个节点的时候，如果`distance < n`那必然是删除头节点，我们只需要返回头节点的后一个节点了，它有两种可能：
1. `NULL`(链表长度为1)
2. `head->next`

如果`distance = n`，就正常删除`delay->next`，并返回`head`。接下来的事情就不用我说了吧。上代码就完事了

------
# 代码
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* ptr = head; 
    struct ListNode* delayN = head;
    int count = 0;
    
    while(ptr->next != NULL){ // length > 1
        count < n ? count = count + 1 : (delayN = delayN->next);
        ptr = ptr->next;
    }
    (count == n) ? (delayN->next = delayN->next->next) : (head = head->next);
    return head;    
}
```

# 总结
最终结果：
```
执行用时:
0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗:
5.3 MB, 在所有 C 提交中击败了100.00%的用户
```
代码比较简洁，因为我确实不太喜欢看到太多的`if else`分支条件语句，因此能用三目运算符的就用了。看起来舒服一点。


