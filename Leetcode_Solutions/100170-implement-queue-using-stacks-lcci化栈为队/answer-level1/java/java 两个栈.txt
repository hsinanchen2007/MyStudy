
**思路**
1. 新建两个栈，一个numStack用于存放插入的数，helpStack用于执行弹出操作。
2. 当push的时候，直接执行numStack.push操作即可
3. 当pop的时候，由于我们需要弹出先插入到栈中的元素，因此，我们可以再借助一个栈，将原有栈逆序即可。这里若helpStack为空，则需要将numStack中的元素全部取出压入到helpStack中，然后从helpStack中pop元素即可。否则直接从helpStack中pop元素即可。也就是说，只有helpStack为空的时候。才将numStack元素全部压入到helpStack中。
4. 由于pop操作与peek操作就多了一步弹出元素的操作，因此pop可以复用peek的代码。
5. isEmpty操作显然依赖于numStack.isEmpty和helpStack.isEmpty。


```java
 class MyQueue {

        private Stack<Integer> numStack;
        private Stack<Integer> helpStack;

        /** Initialize your data structure here. */
        public MyQueue() {
            numStack = new Stack<>();
            helpStack = new Stack<>();
        }

        /** Push element x to the back of queue. */
        public void push(int x) {
            numStack.push(x);
        }

        /** Removes the element from in front of queue and returns that element. */
        public int pop() {
            peek();
            return helpStack.pop();
        }

        /** Get the front element. */
        public int peek() {
            if (helpStack.isEmpty()) {
                while (!numStack.isEmpty()) {
                    helpStack.push(numStack.pop());
                }
            }

            return helpStack.peek();
        }

        /** Returns whether the queue is empty. */
        public boolean empty() {
            return helpStack.isEmpty() && numStack.isEmpty();
        }
    }

```