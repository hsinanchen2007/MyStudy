## 三种解法
解决本题就是要解决一个问题：如何储存最小元素。
如果只是用普通的变量储存当前的最小元素，即每次入栈一个新元素，同时更新当前最小元素，那么当最小元素出栈后，剩下元素里的最小元素是谁？即怎么把之前的最小元素也储存？这是关键问题。
下面给出三种解法，三种解法的本质都是为了解决上面这个关键问题。

### 解法一：辅助栈
显然，只储存当前最小元素是远远不够的，既然要把之前的最小元素也储存，也就是还要储存之前再之前的最小元素，这数量不是普通的一两个变量就能储存下来的，我们需要一个“容器”装这些最小元素。
一个栈不够，那就再借助一个栈，用双栈来存储，这个思路很自然。其中一个栈就是普通的元素栈，存储所有元素，能够完成除getMin()以外的所有功能；而另一个栈就是专门负责getMin()方法的，用于存储最小元素。

push()时，如果minE为空，两个栈同时做push()操作，因为目前没有最小元素，即将入栈的元素将成为最小元素；如果minE不空，且入栈的元素比minE栈顶的元素**相等或更小**，两个栈同时做push()操作，因为说明有新的最小元素了；除上面两种情况以外，仅ele做push()操作。
pop()时，如果ele出栈的元素恰好为最小元素即minE栈顶元素，则两个栈同时做pop()操作，这样minE中下一个栈顶元素就是之前的最小元素，解决了开篇的关键问题，将之前的最小元素存储下来；其他情况，仅ele做pop()操作。

代码：
```java
class MinStack {
    private Stack<Integer> ele;
    private Stack<Integer> minE;

    /** 
     * 构造函数 
     */
    public MinStack() {
        ele = new Stack<Integer>();
        minE = new Stack<Integer>();
    }
    
    /** 
     * 注意minE压入栈的条件
     */
    public void push(int x) {
        ele.push(x);
        if(minE.isEmpty() || x <= minE.peek())
            minE.push(x);
    }
    
    /** 
     * 注意minE弹出的条件
     */
    public void pop() {
        if(ele.peek().equals(minE.peek()))
            minE.pop();
        ele.pop();
    }
    
    public int top() {
        return ele.peek();
    }
    
    public int getMin() {
        return minE.peek();
    }
}
```

### 解法二：辅助变量
只用一个栈就解决不了吗？回到最初的想法，只用一个栈加一个int变量是否可行呢？
可行，但依然要解决上面提到的关键问题，如何存储之前的最小元素？
显然用int变量存储是不可能的，因为之前的最小元素有许多个，int变量只有一个，所以还是要靠这个栈。因此，相对解法一而言，本解法的这个栈要完成解法一中两个栈的功能。

存储之前最小元素的做法：当新元素更小时，把旧min入栈，然后更新min，再入栈新元素；出栈时，如果弹出的是最小元素，那么下一个栈顶元素应该是之前存储的旧min，将其赋值到min，再弹出，即进行了两次pop()。

代码：
```java
class MinStack {
    private Stack<Integer> stack;
    private int min = 0x7fffffff;

    /** 
     * initialize your data structure here. 
     */
    public MinStack() {
        stack = new Stack<Integer>();
    }
    
    /**
     * 新元素小于等于min，说明要更新min，则把旧min也压入，更新min，再压入新元素
     */
    public void push(int x) {
        if(x <= min)
        {
            stack.push(min);
            min = x;
        }
        stack.push(x);
    }
    
    /**
     * 弹出元素为最小元素时，要再弹出一个元素，这是之前一同入栈的旧min
     */
    public void pop() {
        int e = stack.pop();
        if(e == min)
            min = stack.pop();
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int getMin() {
        return min;
    }
}
```

### 解法三：借助链表
为了存储之前的最小元素，我们还可以使用链表，用链表实现栈，将当前元素和最小元素都存在链表的结点内。

push()即添加结点，若x更小，则在结点内更新最小值，否则使用之前的最小值。
pop()即删除结点，由于每个结点都存储了当前元素和最小元素，删除了一个结点后，后面的结点依然存储了之前的最小值。

```java
class MinStack {
    class Node {
        Node next;
        int val;
        int min;

        Node(int v, int m) {
            val = v;
            min = m;
            next = null;
        }
    }

    Node head;

    public void push(int x) {
        if(head == null)
            head = new Node(x, x);
        else
        {
            Node h = new Node(x, Math.min(x, head.min));
            h.next = head;
            head = h;
        }
    }
    
    public void pop() {
        if(head != null)
            head = head.next;
    }
    
    public int top() {
        if(head != null)
            return head.val;
        return -1;
    }
    
    public int getMin() {
        if(head != null)
            return head.min;
        return -1;
    }
}
```