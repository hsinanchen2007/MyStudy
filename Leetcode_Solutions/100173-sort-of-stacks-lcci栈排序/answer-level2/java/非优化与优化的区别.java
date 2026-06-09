### 解题思路

![image.png](https://pic.leetcode-cn.com/9dffca1d539f865a8b8dd4cb4b9ecc83d5158c15cba9e352bae059700a82ab52-image.png)
![image.png](https://pic.leetcode-cn.com/00cd730bdd1b60ac95a41cfce3bb6e21239804f0be2b154025f9eecc142bab27-image.png)
非优化思路：
  采用直接插入的思想，假设主栈已经有序，那么push一个元素，需要插到对应的位置上，
  1.这个位置上面的所有元素都暂时放到一个辅助栈里面
  2.将该元素插入正确位置
  3.将之前的元素在移动回来即可。
优化思路：
  优化：既然有辅助栈，那么充分利用辅助栈，考虑到主栈栈顶元素>=辅助栈的栈顶元素，如果处在中间的元素，我们直接放入辅助栈中，而不用来回倒了
 逻辑：
   1.设新加入的元素为x
   2. x与主栈栈顶y、辅栈栈顶元素z比较只可能出现三种情况，x>=y>=z,y>=x>=z,y>=z>=x,根据这三种情况分别讨论即可
   3. 如果主栈空，x加入主栈
   4.如果主栈不空并且x大于栈顶的元素，那么需要将主栈中所有小于x的元素送到辅栈,将x加入主栈
   5.如果主栈不空并且x小于栈顶的元素，那么就需要将x与辅栈作比较
   6.如果辅栈为空或者辅栈的栈顶元素小于等于x，那么直接加入辅栈
   7.如果辅栈不空并且辅栈栈顶元素大于x，那么就需要将辅栈中所有大于x的元素移到主栈，将x加入辅栈
   8.pop和peek时候需要将辅栈中的所有元素移到主栈

### 代码

```java
//优化代码
class SortedStack {
    Stack<Integer> stack;
    Stack<Integer> helpStack;
    public SortedStack() {
        stack = new Stack<>();
        helpStack = new Stack<>();
    }

    public void push(int val) {
        if (stack.empty()) {
            stack.push(val);
        } else if (stack.peek() < val) {
            while (!stack.empty() && stack.peek() < val) {
                helpStack.push(stack.pop());
            }
            stack.push(val);
        } else if (helpStack.empty() || helpStack.peek() <= val) {
            helpStack.push(val);
        }else{
            while (!helpStack.empty() && helpStack.peek() > val) {
                stack.push(helpStack.pop());
            }
            helpStack.push(val);
        }
    }

    public void pop() {
        while (!helpStack.empty()) {
            stack.push(helpStack.pop());
        }
        if (!isEmpty()) {
            stack.pop();
        }

    }

    public int peek() {
        while (!helpStack.empty()) {
            stack.push(helpStack.pop());
        }
        if (isEmpty()) {
            return -1;
        }
        return stack.peek();
    }

    public boolean isEmpty() {
        return stack.empty();
    }
}

//非优化代码
class SortedStack {
    Stack<Integer> stack;
    Stack<Integer> helpStack;
    public SortedStack() {
        stack = new Stack<>();
        helpStack = new Stack<>();
    }

    public void push(int val) {
        if (stack.empty()) {
            stack.push(val);
        } else{
            while (!stack.empty()&&stack.peek() < val) {
                helpStack.push(stack.pop());
            }
            stack.push(val);
            while (!helpStack.empty()) {
                stack.push(helpStack.pop());
            }
        }
    }

    public void pop() {
        if (!isEmpty()) {
            stack.pop();
        }

    }

    public int peek() {
        if (isEmpty()) {
            return -1;
        }
        return stack.peek();
    }

    public boolean isEmpty() {
        return stack.empty();
    }
}

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack obj = new SortedStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.isEmpty();
 */
```