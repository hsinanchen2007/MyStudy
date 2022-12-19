![Screen Shot 2020-01-14 at 13.54.56.png](https://pic.leetcode-cn.com/48a2e615a623a8eec5f19e8b641a4d9a9174c9badace45762aa32e8f3faca738-Screen%20Shot%202020-01-14%20at%2013.54.56.png)

### 解题思路
使用链表（等于stack）作为数据结构，保存一个min记录. 
push:遇到更小的元素 备份次小值 更新最小值 入栈当前值
pop:若栈顶为最小值 先把栈顶元素拿掉，再恢复次小值
top = peek 末尾getlast即可   getMin 返回min
### 代码

```java
class MinStack {
    private LinkedList<Integer> list = new LinkedList<>();
    private int min = Integer.MAX_VALUE; 
    public void push(int x) {
        if(x <= min) {
            list.add(min);
            min = x;
        }
        list.add(x);
    }
    public void pop() {
        if(list.removeLast() == min) min = list.removeLast();
    }
    
    public int top() {
        return list.getLast();
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