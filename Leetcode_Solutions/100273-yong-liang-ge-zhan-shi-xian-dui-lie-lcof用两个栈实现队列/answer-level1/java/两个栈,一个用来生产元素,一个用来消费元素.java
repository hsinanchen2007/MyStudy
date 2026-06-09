### 解题思路
 
**两个栈,一个用来生产元素,一个用来消费元素**
    1. appendTail的元素放入生产栈(此时顺序和队列相反)
    2. 每次消费栈没有元素时,将生产栈中所有元素一次性挪过去,这样就能保证deleteHead的先入先出顺序(和队列顺序一样)
### 代码

```java
class CQueue {
        //两个栈,一个用来生产元素,一个用来消费元素
        Stack<Integer> produceStack;
        Stack<Integer> consumerStack;

        public CQueue() {
            this.produceStack = new Stack<>();
            this.consumerStack = new Stack<>();
        }

        public void appendTail(int value) {
            produceStack.push(value);
        }

        public int deleteHead() {
            if (produceStack.isEmpty() && consumerStack.isEmpty()) return -1;
            if (consumerStack.isEmpty()) {
                while (!produceStack.isEmpty()) {
                    consumerStack.push(produceStack.pop());
                }
            }
            return consumerStack.pop();
        }
    }

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */
```