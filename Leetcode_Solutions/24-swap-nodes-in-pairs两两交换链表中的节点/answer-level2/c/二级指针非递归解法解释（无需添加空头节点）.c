

通常在进行链表的删除或交互操作时为了操作方便，会在链表的head之前再添加一个节点，这样在处理真实的head节点时就可以按普通的节点处理逻辑进行处理。
比如一个链表：a->b->c
添加空头节点以后：prehead->a->b->c
如果要交换a与b,可以这样操作：
```
Node *a = prehead->next; // 先把a节点地址保存起来
prehead->next = a->next; // 把prehead->next指向b
a->next = a->next->next; // 把a->next指向c
prehead->next->next = a; // prehead->next指向b
```
添加了prehead节点，实际的head节点就可以当成普通节点来处理，不管是操作的head节点还是其它位置的节点，都可以按上面类似的逻辑处理。那么如果不加空头指针操作时，按常规思考，就需要针对head节点做额外的处理逻辑，增加了代码复杂度。

如果采用二级指针就可以消除空头节点，并且不需要对head节点做额外的处理逻辑。方法就是直接修改节点指针指向的地值，这样就不需要通过父节点来修改，从而避免了使用空头指针。举例说明：
链表： a->b->c
如果想修改a节点的next指向c有两种方法：
一种是直接修改a->next = a->next->next;
另一种方法是修改通过修改a->next指针指向的地址,让a->next的指针地址变成c节点的指针地址
```
ListNode **node = &a->next;
*node = a->next->next; 
```
第二种方法有什么好处呢？我们在遍历节点时只需要保留到要修改的这一级节点就可以了，而不需要保留到父节点的层级，这样就消除了空头指针，让代码变得简洁。

下面按这个思路编写题解代码：


```c++ []
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode **node = &head;
        while (*node != NULL && (*node)->next != NULL) {
            ListNode *tmp = *node;
            *node = (*node)->next;
            tmp->next = (*node)->next;
            (*node)->next = tmp;
            node = &((*node)->next->next);
       } 
       return head;
    }
}
```
