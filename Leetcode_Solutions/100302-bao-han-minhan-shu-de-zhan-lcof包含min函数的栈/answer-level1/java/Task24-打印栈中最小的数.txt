### 解题思路
两个思路：
- 不用辅助栈，在min方法中用一个数组记录栈
- 用辅助栈B来保存最小值。

### 代码

```java
class MinStack {
    Stack<Integer> A;
    /** initialize your data structure here. */
    public MinStack() {
        A = new Stack<Integer>();
    }
    
    public void push(int x) {
        A.push(x);
    }
    
    public void pop() {
        A.pop();

    }
    
    public int top() {
        int res = A.peek();
        return res;
    }
    
    public int min() {
        int count = A.size();
        int[] arr = new int[count];
        int index = count-1;
        
        // 获取数组
        while (!A.isEmpty()) {
            arr[index--] = A.peek();
            A.pop();
        }
        
        // 将A还原
        for(int i = 0; i < count; i++) {
            A.push(arr[i]);
        }
        
        // 将数组重新排列
        Arrays.sort(arr);
        
        // 返回最小数
        return arr[0];

    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.min();
 */
```