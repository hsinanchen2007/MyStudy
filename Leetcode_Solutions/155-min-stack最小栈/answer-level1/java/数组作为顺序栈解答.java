### 解题思路
此处撰写解题思路
使用顺序栈作为解答。
考虑数组动态扩容
考虑当前栈顶的指针
min每次指向最小的元素，在入栈后进行对比，确定最小元素
### 代码

```java
class MinStack {

    /**
     * initialize your data structure here.
     */
    int[] arr;
    int index;
    int min;
    int size = 10;

    public MinStack() {
        arr = new int[size];
        index = -1;
    }

    public void push(int x) {
        if (index == size - 1) {
            // 扩容
            this.size *= 2;
            int[] kr = new int[this.size];
            for (int i = 0; i < this.arr.length; i++) {
                kr[i] = this.arr[i];
            }
            this.arr = kr;
        }
        arr[++index] = x;
        // 添加第一个元素
        if (index == 0) {
            min = x;
        } else {
            min = min > arr[index] ? arr[index] : min;
        }
    }

    public void pop() {
        // 栈顶元素弹出不计算
        arr[index--] = 0;
        // 认为末尾元素为最小值
        if (index == -1) {
            this.min = 0;
            return;
        }
        this.min = arr[index];
        for (int i = 0; i < index; i++) {
            this.min = arr[i] < this.min ? arr[i] : this.min;
        }
    }

    public int top() {
        if (index == -1) {
            return 0;
        }
        return arr[index];
    }

    public int getMin() {
        return min;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
```