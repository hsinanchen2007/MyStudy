使用一个单调递减栈存在比当前节点大的后续节点，这比当前节点的“下一个更大节点”就是栈顶元素。
```
    public static int[] nextLargerNodes(ListNode head) {
        if (head.next == null) {
            return new int[] {0};
        }
        Stack<Integer> input = new Stack<>();
        int size = 0;
        while (head != null) {
            size ++;
            input.push(head.val);
            head = head.next;
        }
        Stack<Integer> stack = new Stack<>();
        int[] result = new int[size];
        while (!input.isEmpty()) {
            size--;
            while (!stack.isEmpty() && input.peek() >= stack.peek()) {
                stack.pop();
            }
            if (stack.isEmpty()) {
                result[size] = 0;
            } else {
                result[size] = stack.peek();
            }
            stack.push(input.pop());
        }
        return result;
    }
```
