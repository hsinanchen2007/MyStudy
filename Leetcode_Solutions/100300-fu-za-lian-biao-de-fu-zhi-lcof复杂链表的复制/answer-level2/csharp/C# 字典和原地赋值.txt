```csharp
// 思路1 借助哈希保存节点信息。
public Node CopyRandomList(Node head)
{
    if (head == null)
        return null;

    Node curr = head;

    Dictionary<Node, Node> dic = new Dictionary<Node, Node>();

    // 遍历节点, 将原节点作为KEY拷贝节点作为value保存在字典中
    while (curr != null)
    {
        Node copy = new Node(curr.val);
        dic[curr] = copy;
        curr      = curr.next;
    }

    // 复制next和random指针
    curr = head;
    while (curr != null)
    {
        dic[curr].next   = curr.next == null ? null : dic[curr.next];
        dic[curr].random = curr.random == null ? null : dic[curr.random];
        curr             = curr.next;
    }

    return dic[head];
}

// 思路二：原地复制
//    复制节点，同时将复制节点链接到原节点后面，如A->B->C 变为 A->A'->B->B'->C->C'。
// 设置节点random值。
// 将复制链表从原链表分离。
public Node CopyRandomList2(Node head)
{
    if (head == null)
        return null;

    Node curr = head;
    // 复制节点添加到原节点后面
    while (curr != null)
    {
        Node copy = new Node(curr.val);
        copy.next = curr.next;
        curr.next = copy;
        curr      = copy.next;
    }

    // 复制random节点
    curr = head;
    while (curr != null)
    {
        if (curr.random != null)
        {
            // curr.next 是copy节点, 
            curr.next.random = curr.random.next;
        }

        // 跳过copy节点
        curr = curr.next.next;
    }

    // 分离链表
    curr = head;
    Node newHead = head.next;
    Node newNode = newHead;
    while (curr != null)
    {
        curr.next = curr.next.next;
        // 不可能是空指针, 因为只要head不为null,肯定有下一个复制copy节点
        if (newNode.next != null)
        {
            newNode.next = newNode.next.next;
        }

        curr    = curr.next;
        newNode = newNode.next;
    }

    return newHead;
}
```
