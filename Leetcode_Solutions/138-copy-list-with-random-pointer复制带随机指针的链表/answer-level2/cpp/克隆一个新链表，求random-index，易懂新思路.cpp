### 解题思路
这是个不同于用哈希表，或者1-1-2-2的方法，既然是深拷贝，题目也给了一个random-index的提示，那为什么不用呢？所以我想可以从头构造一个一模一样的链表`tete`：
首先从头遍历，按照next的顺序构造单向链表。
再遍历一次原链表，求每个节点的random-index（它指向链表第几个元素），然后同步在`tete`中前进这么多次，把这个元素连接到当前`tete`中random来，因为长度一样，`head`遍历到尾巴那`tete`也到头了。
### 实现方法
我先定义了一个函数，输入head和tete（也就是要复制和粘贴的两个链表），以及要复制random的head中的结点，返回`tete`中对应的结点。
遍历第一次，克隆了一个按照next看顺序一样，random全部NULL的链表`tete`（知道为什么要叫tete的朋友欢迎留言哈哈哈）。
第二次遍历是两个链表同步进行的，每次就把`head`中结点指向的random对应的“拷贝”到`tete`上。

### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
Node* count(Node *head,Node* test,Node* tete){
    Node *move=head;
    int c=0;
    int i=0;
    while(move!=test){
        c++;
        move=move->next;
    }//求到random-index等于c
    while(i!=c)
    {
        tete=tete->next;
        i++;
    }//在新构造的链表中迭代c次，对应节点就是新表中random应该指向的结点
    return tete;
}
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        Node *tete=new Node(head->val);
        Node *m=head;
        Node *n=tete;
        while(m->next!=NULL)
        {
            Node *tmp=new Node(m->next->val);
            n->next=tmp;
            n=n->next;
            m=m->next;
        }//构造好了新链表
        m=head;
        n=tete;
        while(m!=NULL)
        {
            n->random=count(head,m->random,tete);//关键的一步，同步random
            m=m->next;
            n=n->next;
        }
        return tete;
        
    }
};
```