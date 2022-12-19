### 基于数组模拟Stack的解法（JAVA）
基于数组模拟栈，主要有一下几点：
1. 通过index下标指针记录插入的位置
2. 数组的这里设计的初始容量为10，每次扩容一半,使用右移，效率快点 
    `Arrays.copyOf(this.arrs, this.arrs.length + (this.arrs.length >> 1))`
3. push方法：先判断扩容，然后比较存储的最小值和当前值的大小,符合要求赋值给min属性
4. pop方法：先移动index下标指针，然后找出数组中此时的最小值，赋值给min属性

执行用时 :61 ms, 在所有 java 提交中击败了95.47%的用户
内存消耗 :40.3 MB, 在所有 java 提交中击败了95.44%的用户
还有优化空间的话，欢迎大家指出。

具体代码如下：
```
import java.util.EmptyStackException;
class MinStack {
        // 存储整个stack中的最小值
        private int min = Integer.MAX_VALUE;
        private int[] arrs = new int[10];
        private int index = 0;

        /**
         * initialize your data structure here.
         */
        public MinStack() {

        }

        public void checkGrowth() {
            if (index >= arrs.length - 1) {
                // 使用右移位运算符，每次扩容一半
                this.arrs = Arrays.copyOf(this.arrs, this.arrs.length + (this.arrs.length >> 1));
            }
        }

        public boolean isEmpty() {
            return this.index <= 0;
        }

        public void push(int x) {
            // 判断是否扩容
            checkGrowth();
            int min = this.min;
            if ( min > x) {
                this.min = x;
            }
            // 加入
            arrs[index] = x;
            index++;
        }

        public int pop() {
            // pop的时候先将下标指针-1, 然后找出此时栈中的最小值,赋值给this.min
            int top = top();
            this.index--;
            int min = Integer.MAX_VALUE;
            for (int i = 0; i < this.index; i++) {
                if (min > this.arrs[i]) {
                    min = this.arrs[i];
                }
            }
            this.min = min;
            return top;
        }

        public int top() {
            if (this.isEmpty()) {
                throw new EmptyStackException();
            }
            // 指针前移一位
            return this.arrs[this.index - 1];
        }

        public int getMin() {
            return this.min;
        }
}

```
