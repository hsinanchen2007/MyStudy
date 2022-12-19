**1.关注代码的规范性、完整性、鲁棒性。
2.定义一个数据栈也就是正常存放数字的栈，再定义一个存放最小值的栈;
3.在pop数字的时候添加判断栈空的判定条件，面试会加分;
4.push：数据栈正常push数字，最小值栈的添加条件：栈空 或者 当 x <= 最小栈的栈顶元素添加;
5.pop：数据栈先判断栈空，栈非空pop数据;将pop数据保存下来，如果最小栈栈顶元素等于数据栈的pop元素，最小栈也要pop一次;**

    //同步压栈 
    class MinStack {
        private Stack<Integer> stackData;
        private Stack<Integer> stackMin;

        public MinStack() {
            this.stackData = new Stack<Integer>();
            this.stackMin = new Stack<Integer>();
        }

        public void push(int x) {
            this.stackData.push(x);
            if (this.stackMin.isEmpty() || x <= this.getMin()) {
                this.stackMin.push(x);
            }
        }

        public void pop() {
            if (this.stackData.isEmpty())
                throw new RuntimeException("Your stack is empty.");
            int val = this.stackData.pop();
            if (val == this.getMin())
                this.stackMin.pop();
        }

        public int top() {
            if (this.stackData.isEmpty())
                throw new RuntimeException("Your stack is empty.");
            return this.stackData.peek();
        }

        public int getMin() {
            if (this.stackMin.isEmpty())
                throw new RuntimeException("Your stack is empty.");
            return this.stackMin.peek();
        }
    }


**同步压栈：push当 x < 最小栈栈顶元素，入最小栈，否则重复压入最小栈栈顶元素，和数据栈保持同步。**

    // 同步压栈
    class MinStack {
        private Stack<Integer> stackData;
        private Stack<Integer> stackMin;

        /** initialize your data structure here. */
        public MinStack() {
            this.stackData = new Stack<Integer>();
            this.stackMin = new Stack<Integer>();
        }

        public void push(int x) {
            this.stackData.push(x);
            if (this.stackMin.isEmpty() || x < this.getMin()) {
                this.stackMin.push(x);
            } else {
                stackMin.push(this.getMin());
            }
        }

        public void pop() {
            if (this.stackData.isEmpty())
                throw new RuntimeException("Your stack is empty.");
            this.stackData.pop();
            this.stackMin.pop();
        }

        public int top() {
            if (this.stackData.isEmpty())
                throw new RuntimeException("Your stack is empty.");
            return this.stackData.peek();
        }

        public int getMin() {
            if (this.stackMin.isEmpty())
                throw new RuntimeException("Your stack is empty.");
            return this.stackMin.peek();
        }
    }