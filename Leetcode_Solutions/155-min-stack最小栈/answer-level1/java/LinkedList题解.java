### 解题思路
思路：借助`Java`标准库的`LinkedList`类，在`push`的时候记录最小的值，在`pop`的时候判断值是否为最小值，如果为最小值的话，遍历整个`List`更新最小值，最坏情况数值为倒序压入栈，每次`pop`都需要更新最小值，所以时间复杂度为`O(n)`。

### 代码

```java
class MinStack {

    private int min = Integer.MAX_VALUE;
    LinkedList<Integer> list = null;

    /** initialize your data structure here. */
    public MinStack() {
        list = new LinkedList<>();
    }
    
    public void push(int x) {
        if(x < min) {
            min = x;
        }
        list.push(x);
    }
    
    public void pop() {
        Integer num = list.removeFirst();
        if(num == min) {
            min = Integer.MAX_VALUE;
            for(Integer element : list) {
                if(element < min) {
                    min = element;
                }
            }
        }
    }
    
    public int top() {
        return list.getFirst();
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