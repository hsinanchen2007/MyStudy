# 方法1：
依次遍历节点，若某节点p有子链表，则找到该子链表的最后一个节点c，将节点c与节点p的后继结点相连。
这种方法容易理解，但是时间复杂度较高。。。
```
Node* flatten(Node* head) {
        Node *p = head;
        while (p!=NULL)
        {
            if(p->child!=NULL)//该节点有子链表
            {
                Node *next = p->next;//next指向p的初始后继结点
                Node *c = p->child;
                p->child = NULL;//将该节点的child指针清空
                p->next = c;
                c->prev = p;
                while (c->next != NULL)//找到子链表的最后一个节点
                {
                    c = c->next;
                }
                c->next = next;
                if(next!=NULL)
                    next->prev = c;
            }
            p = p->next;
        }
        return head;
    }
```

# 方法2：
类似于深度优先遍历，借助栈完成。
```
Node* flatten(Node* head) {
        stack<Node*> s;
        Node *pre=NULL;
        if(head)//先判断头结点是否为空
            s.push(head);
        while (!s.empty())
        {
            Node *t = s.top();
            s.pop();
            if(t->next)//注意：后继节点优先入栈
            {
                s.push(t->next);
            }
            if(t->child)
            {
                s.push(t->child);
                t->child = NULL;//将该节点的child指针清空
            }
            if(pre)
            {
                pre->next = t;
                t->prev = pre;
            }
            pre = t;//pre指向刚出栈的节点
        }
        return head;
    }
```
