### 解题思路

1.两个栈，一个栈用于保存元素(这个栈可以自己设计)。另一个保存最小值。

2.入栈时，当元素栈为空时，将这个值压入最小值栈。当元素栈不为空时，则比较当前值与最小值栈顶元素的大小；如果栈顶元素大于等于当前值时，当前值入最小值栈。此时说明最小值栈为从大到小的数字栈，靠近栈顶的值最小。

3.出栈时，需要判断元素栈顶值与最小值栈顶值是否相等。相等说明最小值出栈，则最小值栈出栈。

4.时间复杂度O(n)，空间复杂度O(n)

### 代码

```java
class MinStack {

//    /**
//     * 栈顶指针，用于保存元素
//     */
//    private Node top;
//    /**
//     * 栈的元素个数
//     */
//    private int size;
    /**
     * 保存最小值的栈
     */
    private Stack<Integer> minElementStack;
    /**
     * 保存元素的栈
     */
    private Stack<Integer> elementStack;

    public MinStack() {
        minElementStack = new Stack<>();
        elementStack = new Stack<>();
    }

    /**
     * 入栈
     */
    public void push(int x) {
        // 元素栈是否为空
        if (elementStack.empty()) {
            // 元素栈为空，说明最小值就是当前值
            minElementStack.push(x);
        } else if (minElementStack.peek() >= x) {// 比较最小值栈顶值与当前值的大小
            // 最小值栈顶值 >= 当前值，把当前值入栈。这个栈是一个从大到小的栈，靠近栈顶的元素最小
            minElementStack.push(x);
        }
        // 元素栈入栈
        elementStack.push(x);
//        // 元素入栈，栈顶指针上移
//        top = new Node(x, top);
//        if (size == 0) {
//            minElementStack.push(x);
//        } else if (minElementStack.peek() >= x) {
//            minElementStack.push(x);
//        }
//        size++;
    }

    /**
     * 出栈
     */
    public void pop() {
//        if (top == null) {// 边界判断
//            throw new RuntimeException("Stack is null, can not pop");
//        } else if (size == 0) {// 边界判断
//            throw new RuntimeException("Stack is empty, can not pop");
//        } else {
//            // 元素栈顶与最小值栈顶是否相等
//            if (top() == minElementStack.peek()) {
//                // 相等，说明最小值出栈
//                minElementStack.pop();
//            }
//            //  元素栈出栈，栈顶指针下移
//            Node node = top;
//            top = top.next;
//            size--;
//            // help gc
//            node.next = null;
//        }
        if (elementStack.empty()) {// 边界判断
            throw new RuntimeException("Stack is empty, can not pop");
        } else {
            // 元素栈顶与最小值栈顶是否相等
            if (elementStack.peek().equals(minElementStack.peek())) {
                // 相等，说明最小值出栈
                minElementStack.pop();
            }
            // 元素栈出栈
            elementStack.pop();
        }
    }

    /**
     * 获取元素栈栈顶元素
     */
    public int top() {
//        return top.value;
        return elementStack.peek();
    }

    /**
     * 获取最小值
     */
    public int getMin() {
//        if (top == null) {
//            throw new RuntimeException("Stack is null, no minElement");
//        } else if (size == 0) {
//            throw new RuntimeException("Stack is empty, no minElement");
//        } else {
//            return minElementStack.peek();
//        }
        if (elementStack.empty()) {
            throw new RuntimeException("Stack is empty, no minElement");
        } else {
            return minElementStack.peek();
        }
    }

//    static class Node {
//        int value;
//        Node next;
//
//        public Node(int value, Node next) {
//            this.value = value;
//            this.next = next;
//        }
//    }
}
```