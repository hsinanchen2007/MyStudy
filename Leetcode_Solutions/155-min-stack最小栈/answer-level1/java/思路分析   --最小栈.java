这一题思路的重点不在于你怎么实现的栈，而是最小值问题，这个最小值要求的是在常数时间内检索到的所以说就是需要把这个值保存起来了，保存起来一个还不行还要避免这个值被后来来的重写掉，所以说应该保存多个，那么实现起来就有了思路；贴一下刚学的时候老师讲过的代码，说的也就是这个题
```java
class MinStack {
 // 数据栈
        private Stack<Integer> data;
        // 辅助栈
        private Stack<Integer> min;

        /**
         * initialize your data structure here.
         */
        public MinStack() {
            data = new Stack<>();
            min = new Stack<>();
        }

        // 思路 1：数据栈和辅助栈在任何时候都同步

        public void push(int x) {
            // 数据栈和最小值栈一定会增加元素
            data.add(x);
            if (min.isEmpty() || min.peek() >= x) {
                min.add(x);
            } else {
                min.add(min.peek());
            }
        }

        public void pop() {
            // 两个栈都得 pop
            if (!data.isEmpty()) {
                min.pop();
                data.pop();
            }
        }

        public int top() {
            if(!data.isEmpty()){
                return data.peek();
            }
            throw new RuntimeException("空栈");
        }

        public int getMin() {
            if(!min.isEmpty()){
                return min.peek();
            }
            throw new RuntimeException("空栈");
        }
}
```
这个应该是最经典的解法了，如果学的是java数据结构的基本都会在讲解栈的时候拿出来当例题的吧；
