#### 方法一：双栈

一个普通的栈可以支持前三种操作 `push(x)`，`pop()` 和 `top()`，所以我们需要考虑的仅为后两种操作 `peekMax()` 和 `popMax()`。

对于 `peekMax()`，我们可以另一个栈来存储每个位置到栈底的所有元素的最大值。例如，如果当前第一个栈中的元素为 `[2, 1, 5, 3, 9]`，那么第二个栈中的元素为 `[2, 2, 5, 5, 9]`。在 `push(x)` 操作时，只需要将第二个栈的栈顶和 $x$ 的最大值入栈，而在 `pop()` 操作时，只需要将第二个栈进行出栈。

对于 `popMax()`，由于我们知道当前栈中最大的元素值，因此可以直接将两个栈同时出栈，并存储第一个栈出栈的所有值。当某个时刻，第一个栈的出栈元素等于当前栈中最大的元素值时，就找到了最大的元素。此时我们将之前出第一个栈的所有元素重新入栈，并同步更新第二个栈，就完成了 `popMax()` 操作。

```Python [sol1]
class MaxStack(list):
    def push(self, x):
        m = max(x, self[-1][1] if self else None)
        self.append((x, m))

    def pop(self):
        return list.pop(self)[0]

    def top(self):
        return self[-1][0]

    def peekMax(self):
        return self[-1][1]

    def popMax(self):
        m = self[-1][1]
        b = []
        while self[-1][0] != m:
            b.append(self.pop())

        self.pop()
        map(self.push, reversed(b))
        return m
```

```Java [sol1]
class MaxStack {
    Stack<Integer> stack;
    Stack<Integer> maxStack;

    public MaxStack() {
        stack = new Stack();
        maxStack = new Stack();
    }

    public void push(int x) {
        int max = maxStack.isEmpty() ? x : maxStack.peek();
        maxStack.push(max > x ? max : x);
        stack.push(x);
    }

    public int pop() {
        maxStack.pop();
        return stack.pop();
    }

    public int top() {
        return stack.peek();
    }

    public int peekMax() {
        return maxStack.peek();
    }

    public int popMax() {
        int max = peekMax();
        Stack<Integer> buffer = new Stack();
        while (top() != max) buffer.push(pop());
        pop();
        while (!buffer.isEmpty()) push(buffer.pop());
        return max;
    }
}
```

**时间复杂度**

* 时间复杂度：$O(n)$。由于前四个操作的时间复杂度都是 $O(1)$，而 `popMax()` 操作在最坏情况下需要将栈中的所有元素全部出栈再入栈，时间复杂度为 $O(n)$。因此总的时间复杂度为 $O(n)$。
* 空间复杂度：$O(n)$。

#### 方法二：双向链表 + 平衡树

**分析**

使用线性的数据结构（例如数组和栈）无法在较短的时间复杂度内完成 `popMax()` 操作，因此我们可以考虑使用双向链表 + 平衡树，其中双向链表用来表示栈，平衡树中的每一个节点存储一个键值对，其中“键”表示某个在栈中出现的值，“值”为一个列表，表示这个值在双向链表中出现的位置，存储方式为指针。平衡树的插入，删除和查找操作都是 $O(\log n)$ 的，而通过平衡树定位到双向链表中的某个节点后，对该节点进行删除也是 $O(1)$ 的，因此所有操作的时间复杂度都不会超过 $O(\log n)$。

**算法**

我们使用双向链表存储栈，使用带键值对的平衡树（Java 中的 `TreeMap`）存储栈中出现的值以及这个值在双向链表中出现的位置。

* `push(x)` 操作：在双向链表的末尾添加一个节点，并且在平衡树上找到 $x$，给它的列表中添加一个位置，指向新的节点。

* `pop()`操作：在双向链表的末尾删除一个节点，它的值为 $\mathrm{val}$，随后在平衡树上找到 $\mathrm{val}$，删除它的列表中的最后一个位置。

* `top()` 操作：返回双向链表中最后一个节点的值。

* `peekMax()` 操作：返回平衡树上的最大值。

* `popMax()` 操作：在平衡树上找到最大值和它对应的列表，得到列表中的最后一个位置，并将它在双向链表中和平衡树上分别删除。

```Java [sol2]
class MaxStack {
    TreeMap<Integer, List<Node>> map;
    DoubleLinkedList dll;

    public MaxStack() {
        map = new TreeMap();
        dll = new DoubleLinkedList();
    }

    public void push(int x) {
        Node node = dll.add(x);
        if(!map.containsKey(x))
            map.put(x, new ArrayList<Node>());
        map.get(x).add(node);
    }

    public int pop() {
        int val = dll.pop();
        List<Node> L = map.get(val);
        L.remove(L.size() - 1);
        if (L.isEmpty()) map.remove(val);
        return val;
    }

    public int top() {
        return dll.peek();
    }

    public int peekMax() {
        return map.lastKey();
    }

    public int popMax() {
        int max = peekMax();
        List<Node> L = map.get(max);
        Node node = L.remove(L.size() - 1);
        dll.unlink(node);
        if (L.isEmpty()) map.remove(max);
        return max;
    }
}

class DoubleLinkedList {
    Node head, tail;

    public DoubleLinkedList() {
        head = new Node(0);
        tail = new Node(0);
        head.next = tail;
        tail.prev = head;
    }

    public Node add(int val) {
        Node x = new Node(val);
        x.next = tail;
        x.prev = tail.prev;
        tail.prev = tail.prev.next = x;
        return x;
    }

    public int pop() {
        return unlink(tail.prev).val;
    }

    public int peek() {
        return tail.prev.val;
    }

    public Node unlink(Node node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
        return node;
    }
}

class Node {
    int val;
    Node prev, next;
    public Node(int v) {val = v;}
}
```

**复杂度分析**

* 时间复杂度：$O(\log n)$。`top()` 操作的时间复杂度为 $O(1)$，其余操作的时间复杂度为 $O(\log n)$，因此总的时间复杂度为 $O(\log n)$。
* 空间复杂度：$O(n)$。