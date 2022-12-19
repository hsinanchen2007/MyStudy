### 解题思路
使用linkedlist保存栈的信息，同时记录一个最小值

### 代码

```java
class MinStack {

      private LinkedList<Integer> linkedList;
    private int min = Integer.MAX_VALUE;

    /**
     * initialize your data structure here.
     */
    public MinStack() {
        linkedList = new LinkedList<>();
    }

    public void push(int x) {
        min = Math.min(x, min);
        linkedList.offerFirst(x);
    }

    public void pop() {
        int poped = linkedList.removeFirst();
        if (min == poped) {
            min=Integer.MAX_VALUE;
            refreshMin(this.linkedList);
        }


    }

    public int top() {
        return linkedList.peek();
    }

    public int getMin() {
        return this.min;
    }

    private void refreshMin(LinkedList<Integer> list) {
        if (list == null || list.isEmpty()) {
            return;
        }

        min = list.stream().sorted().collect(Collectors.toList()).get(0);


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