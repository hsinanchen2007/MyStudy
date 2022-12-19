**1.注重代码的规范性、完整性、鲁棒性。
2.采用双栈实现队列，先将数字放入stackPush，然后pop到stackPop栈中，然后pop就是出队列的实现形式;
3.注意两个思想:(1):stackPush中的数据必须一次性全部压入stackPop中;(2):如果stackPop栈不为空，绝不能将stackPush栈中的元素压入stackPop栈，例：stackPop有元素1,2,3，此时stackPush压入了4,5元素，只能Pop完1,2,3，才能Push 5,4元素;
4.完结。**


    // 两个栈实现队列
    class MyQueue {
        Stack<Integer> stackPush;
        Stack<Integer> stackPop;

        /** Initialize your data structure here. */
        public MyQueue() {
            stackPush = new Stack<Integer>();
            stackPop = new Stack<Integer>();
        }

        /** Push element x to the back of queue. */
        public void push(int x) {
            stackPush.push(x);
        }

        /** Removes the element from in front of queue and returns that element. */
        public int pop() {
            if (stackPop.isEmpty() && stackPush.isEmpty()) {
                throw new RuntimeException("Queue is empty.");
            } else {
                if (stackPop.isEmpty()) {
                    while (!stackPush.isEmpty()) {
                        stackPop.push(stackPush.pop());
                    }
                }
            }
            return stackPop.pop();
        }

        /** Get the front element. */
        public int peek() {
            if (stackPush.isEmpty() && stackPop.isEmpty()) {
                throw new RuntimeException("Queue is empyt.");
            } else {
                if (stackPop.isEmpty()) {
                    while (!stackPush.isEmpty()) {
                        stackPop.push(stackPush.pop());
                    }
                }
            }
            return stackPop.peek();
        }

        /** Returns whether the queue is empty. */
        public boolean empty() {
            return stackPop.isEmpty() && stackPush.isEmpty();
        }
    }