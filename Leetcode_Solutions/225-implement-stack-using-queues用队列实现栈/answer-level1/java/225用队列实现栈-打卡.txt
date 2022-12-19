### 解题思路
队列是先进先出，栈是先进后出。
使用队列模拟栈，重点在获得栈顶元素上。
思路：将队列中的元素先取出再重新加入直到最后一个元素。
```Java []
int size = queue.size();
for (int i = 0; i < size - 1; i++) {
    queue.add(queue.poll());
}

```
class MyStack {

        private Queue<Integer> queue;

        /**
         * Initialize your data structure here.
         */
        public MyStack() {
            queue = new LinkedList<>();
        }

        /**
         * Push element x onto stack.
         */
        public void push(int x) {
            queue.add(x);
        }

        /**
         * Removes the element on top of the stack and returns that element.
         */
        public int pop() {
            int size = queue.size();
            // 关键：将头size个值放到尾部
            for (int i = 0; i < size - 1; i++) {
                queue.add(queue.poll());
            }
            return queue.poll();
        }

        /**
         * Get the top element.
         */
        public int top() {
            int size = queue.size();
            for (int i = 0; i < size - 1; i++) {
                queue.add(queue.poll());
            }
            int result = queue.poll();
            queue.add(result);
            return result;
        }


        /**
         * Returns whether the stack is empty.
         */
        public boolean empty() {
            return queue.isEmpty();
        }
    }
```

