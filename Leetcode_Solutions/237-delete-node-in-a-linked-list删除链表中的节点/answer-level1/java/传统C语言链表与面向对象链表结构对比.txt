本题的题意是,存在一个我们不能直接去访问链表head,以及给定的节点node
我们要在无法访问head的情况下,把node节点删除

在面向对象的语言中,我们已知node但无法访问node的上一个节点,因此不能修改上一个节点的next属性
官方题解把node节点的值用下一个节点的值去覆盖掉,然后把重复值的node.next给删除掉,达成了一种"狸猫换太子"的效果

```java
public void deleteNode(ListNode node) {
    node.val = node.next.val;
    node.next = node.next.next;
}
```

但在c语言中,因为是指针和结构体来表示链表,因此node和之前节点的next指向了内存中的同一地址,所以只要对这个地址做修改,上一个节点的next也同时被修改了
```cpp
class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *(node->next);
    }
};
```