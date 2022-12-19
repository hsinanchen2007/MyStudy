```
    Node* flatten_recurse(Node* head, Node*& tail)
    {
        if (head == nullptr)
            return head;
        Node* cur = head;
        Node* pre = nullptr;
        while (cur != nullptr)
        {
            Node* next = cur->next;
            if (cur->child == nullptr) //不存在child节点
            {
                tail = cur;
                pre = cur;
                cur = next;
            }
            else
            {
                Node* beg = flatten_recurse(cur->child, tail); //此时beg是新生成的链表的头节点，tail是尾节点

                cur->next = beg;//连接头节点与cur节点，即beg节点是cur节点的next节点
                beg->prev = cur;

                cur->child = nullptr; //将cur节点的child节点置为nullptr

                tail->next = next; //连接尾节点与next节点，即尾节点tail是next节点的pre节点
                if(next!= nullptr)
                    next->prev = tail;

                pre = tail;
                cur = next;
            }
        }
        return head;
    }
    Node* flatten(Node* head)
    {
        Node* tail = nullptr;
        return flatten_recurse(head, tail);
    }
```
