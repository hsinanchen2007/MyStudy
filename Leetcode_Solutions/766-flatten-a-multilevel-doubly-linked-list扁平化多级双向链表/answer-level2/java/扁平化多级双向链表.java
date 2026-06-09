####  方法一：递归的深度优先搜素
我们可能会疑问什么情况下会使用这样的数据结构。其中一个场景就是 `git` 分支的简化版本。通过扁平化多级列表，可以认为将所有 `git` 的分支合并在一起。

首先，为了清楚扁平化操作的效果，我们用下面的一个例子来说明。
![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMwLzQzMF9saXN0X3N0ZXBfMS5wbmc?x-oss-process=image/format,png)
在上面的例子中，我们用不同的颜色区分不同级别的节点。扁平化的操作可以分为以下两个步骤：
![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMwLzQzMF9saXN0X3N0ZXBfMi5wbmc?x-oss-process=image/format,png)
我们可以看到通过扁平化的操作，我们将 `child` 指针指向的列表合并到父列表。

这是解释扁平化操作的一种方式，看起来很直观，但可能会在实现过程中遇到挫折，是因为没有抓住问题的本质。

我们将列表顺时针转 90 °，那么就会看到一颗二叉树，则扁平化的操作也就是对二叉树进行先序遍历（深度优先搜索）
![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMwLzQzMF9kZnNfdHJlZS5wbmc?x-oss-process=image/format,png)

如上图所示，我们可以将 `child` 指针当作二叉树中指向左子树的 `left ` 指针。同样，`next` 指针可以当作是二叉树中的 `right` 指针。然后我们深度优先搜索树将得到答案。

**算法：**
现在我们要做的就是模拟在二叉树进行深度优先搜索。

我们知道实现深度优先搜索通常有两种方式：递归和迭代。我们先从递归开始。

递归的深度优先搜索算法如下：
- 首先，我们定义递归函数 `flatten_dfs(prev, curr)`，它接收两个指针作为函数参数并返回扁平化列表中的尾部指针。`curr` 指针指向我们要扁平化的子列表，`prev` 指针指向 `curr` 指向元素的前一个元素。
- 在函数 `flatten_dfs(prev, curr)`，我们首先在 `prev` 和 `curr` 节点之间建立双向连接。
- 然后在函数中调用 `flatten_dfs(curr, curr.child)` 对左子树（`curr.child` 即子列表）进行操作，它将返回扁平化子列表的尾部元素 `tail`，再调用 `flatten_dfs(tail, curr.next)` 对右子树进行操作。
- 为了得到正确的结果，我们还需要注意两个重要的细节：
	- 在调用 `flatten_dfs(curr, curr.child)` 之前我们应该复制 `curr.next` 指针，因为 `curr.next` 可能在函数中改变。
	- 在扁平化 `curr.child` 指针所指向的列表以后，我们应该删除 `child` 指针，因为我们最终不再需要该指针。


```python [solution1-Python]
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""
class Solution(object):

    def flatten(self, head):
        if not head:
            return head

        # pseudo head to ensure the `prev` pointer is never none
        pseudoHead = Node(None, None, head, None)
        self.flatten_dfs(pseudoHead, head)

        # detach the pseudo head from the real head
        pseudoHead.next.prev = None
        return pseudoHead.next


    def flatten_dfs(self, prev, curr):
        """ return the tail of the flatten list """
        if not curr:
            return prev

        curr.prev = prev
        prev.next = curr

        # the curr.next would be tempered in the recursive function
        tempNext = curr.next
        tail = self.flatten_dfs(curr, curr.child)
        curr.child = None
        return self.flatten_dfs(tail, tempNext)
```

```java [solution1-Java]
/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;

    public Node() {}

    public Node(int _val,Node _prev,Node _next,Node _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
  public Node flatten(Node head) {
    if (head == null) return head;
    // pseudo head to ensure the `prev` pointer is never none
    Node pseudoHead = new Node(0, null, head, null);

    flattenDFS(pseudoHead, head);

    // detach the pseudo head from the real head
    pseudoHead.next.prev = null;
    return pseudoHead.next;
  }
  /* return the tail of the flatten list */
  public Node flattenDFS(Node prev, Node curr) {
    if (curr == null) return prev;
    curr.prev = prev;
    prev.next = curr;

    // the curr.next would be tempered in the recursive function
    Node tempNext = curr.next;

    Node tail = flattenDFS(curr, curr.child);
    curr.child = null;

    return flattenDFS(tail, tempNext);
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N)$。$N$ 指的是列表的节点数，深度优先搜索遍历每个节点一次。
* 空间复杂度：$\mathcal{O}(N)$，$N$ 指的是列表的节点数，二叉树很可能不是个平衡的二叉树，若节点仅通过 `child` 指针相互链接，则在递归调用的过程中堆栈的深度会达到 $N$。


####  方法二：迭代的深度优先搜索
我们还可以使用迭代的方式完成深度优先搜索。

关键是使用 `stack` 数据结构，元素遵循后进先出的原则。

`stack` 帮我们维持一个迭代序列，它模拟函数掉哦那个堆栈的行为，这样我们就可以不使用递归来获得相同的结果。

**算法：**
- 首先我们创建 `stack`，然后将头节点压栈。利用 `prev` 变量帮助我们记录在每个迭代过程的前继节点。
- 然后我们进入循环迭代 `stack` 中的元素，直到栈为空。
- 在每一次迭代过程中，首先在 `stack` 弹出一个节点（叫做 `curr`）。再建立 `prev` 和 `curr` 之间的双向链接，再顺序处理 `curr.next` 和 `curr.child` 指针所指向的节点，严格按照此顺序执行。
- 如果 `curr.next` 存在（即存在右子树），那么我们将 `curr.next` 压栈后进行下一次迭代。
- 如果 `curr.child` 存在（即存在左子树），那么将 `curr.child` 压栈，与 `curr.next` 不同的是，我们需要删除 `curr.child` 指针，因为在最终的结果不再需要使用它。
- 为了更好的理解该算法，可以看以下动画进行理解：
![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMwLzQzMF9zbGlkZV8yLnBuZw?x-oss-process=image/format,png)
![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMwLzQzMF9zbGlkZV8zLnBuZw?x-oss-process=image/format,png)
![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMwLzQzMF9zbGlkZV80LnBuZw?x-oss-process=image/format,png)
![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMwLzQzMF9zbGlkZV81LnBuZw?x-oss-process=image/format,png)
![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMwLzQzMF9zbGlkZV82LnBuZw?x-oss-process=image/format,png)
![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMwLzQzMF9zbGlkZV83LnBuZw?x-oss-process=image/format,png)
![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMwLzQzMF9zbGlkZV84LnBuZw?x-oss-process=image/format,png)
![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMwLzQzMF9zbGlkZV85LnBuZw?x-oss-process=image/format,png)
![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMwLzQzMF9zbGlkZV8xMC5wbmc?x-oss-process=image/format,png)
![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMwLzQzMF9zbGlkZV8xMS5wbmc?x-oss-process=image/format,png)
![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMwLzQzMF9zbGlkZV8xMi5wbmc?x-oss-process=image/format,png)

```python [solution2-Python]
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""
class Solution(object):
    def flatten(self, head):
        if not head:
            return

        pseudoHead = Node(0,None,head,None)
        prev = pseudoHead

        stack = []
        stack.append(head)

        while stack:
            curr = stack.pop()

            prev.next = curr
            curr.prev = prev

            if curr.next:
                stack.append(curr.next)
 
            if curr.child:
                stack.append(curr.child)
                # don't forget to remove all child pointers.
                curr.child = None

            prev = curr
        # detach the pseudo head node from the result.
        pseudoHead.next.prev = None
        return pseudoHead.next
```

```java [solution2-Java]
/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;

    public Node() {}

    public Node(int _val,Node _prev,Node _next,Node _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
  public Node flatten(Node head) {
    if (head == null) return head;

    Node pseudoHead = new Node(0, null, head, null);
    Node curr, prev = pseudoHead;

    Deque<Node> stack = new ArrayDeque<>();
    stack.push(head);

    while (!stack.isEmpty()) {
      curr = stack.pop();
      prev.next = curr;
      curr.prev = prev;

      if (curr.next != null) stack.push(curr.next);
      if (curr.child != null) {
        stack.push(curr.child);
        // don't forget to remove all child pointers.
        curr.child = null;
      }
      prev = curr;
    }
    // detach the pseudo node from the result
    pseudoHead.next.prev = null;
    return pseudoHead.next;
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N)$。
* 空间复杂度：$\mathcal{O}(N)$。