第一次写题解

看了一下别人的题解，很多都是直接递归返回扁平化链表后的头结点的，类似这种逻辑：
```
Node* flatten(Node* head) {
//省略...
    if(cur->child){
    //省略...
        cur->next = flatten(cur->child);
        cur->child->prev = cur;
    //...    
    }

}
```

但这样写会导致同一级链表被遍历多次。

假如整个多级链表有m级，而现在正在遍历第n级链表，当遇到这一级链表带child的节点时（假设这个节点叫cur），递归调用cur->next = flatten(cur->child)会展开剩下(m-n)级链表，这个递归过程每级链表至少被遍历一次。由于返回的是展开后链表的头结点，因此还要再遍历一次刚刚已经遍历过的节点来找到尾节点，再将这个为节点与cur原来的下一个节点拼接起来。

所以其实这样最后对每一级链表来说，第n级链表会被遍历n次

不如稍微改动一下函数的返回值，返回每次扁平化后的链表的最后一个节点
Node* flatten_tail(Node* head)：入参为需要扁平化链表的头结点，返回值为扁平化后的尾节点。由于返回的是尾节点，所以就可以直接和cur的下一个节点拼接起来，不需要再遍历一次。

```
class Solution {
public:
    Node* flatten(Node* head) {
        flatten_tail(head);
        return head;
    }
private:
    Node* flatten_tail(Node* head){
        Node *cur = head, *prev;
        while(cur){
            if(cur->child){
                Node *child_tail = flatten_tail(cur->child);//取得展开后的尾节点
                child_tail->next = cur->next;
                if(cur->next) cur->next->prev = child_tail;
                cur->next = cur->child;
                cur->child->prev = cur;
                cur->child = NULL;
            }
            prev = cur;
            cur = cur->next;
        }
        return prev;//遍历完，返回尾节点
    }
};
```

![image.png](https://pic.leetcode-cn.com/16ff465b72386efdf8136ce43023691d78f2d54b624c5eeeefcba232478b5e1b-image.png)