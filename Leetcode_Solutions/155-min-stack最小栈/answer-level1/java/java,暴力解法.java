### 解题思路
 最小栈
  因为 data > min 的时候还是min入入栈，造成大量重复的min
  所以只记录比min小的值入栈，为了minlist和list保持一致，当list
  pop的时候，需要进行一次比较如果top 小于等于min的时候，minlist出栈
  否则不出栈
  push  时间复杂度 O(1) ,空间复杂度 O(n)
  pop  时间复杂度 O(1) ,空间复杂度 O(n)
  top  时间复杂度 O(1) ,空间复杂度 O(n)
  getMin 时间复杂度 O(1) ,空间复杂度 O(n)

### 代码

```java
class MinStack {

    /** initialize your data structure here. */
    private final LinkedList<Integer> stack;
    private final LinkedList<Integer> minStack;
    private int min = Integer.MAX_VALUE;
    public MinStack() {
        this.stack = new LinkedList<>();
        this.minStack = new LinkedList<>();
    }

    public void push(int x) {
        this.stack.push(x);
        //为什么用等号，因为存在重复值,重复值需要重复入栈
        if (min >= x) {
            minStack.push(x);
            min = x;
        }
    }

    public void pop() {
        //等于是因为存在 1，1， 2， 3这种情况，如果只入站 1个1，导致最后一个1没有最小值
        // 或者 3，2，1，1，所以在入栈的时候进行等于的判断入栈，如果不用等于需要进行去重的处理比较麻烦
       if (this.stack.getFirst() <= min){
          this.minStack.removeFirst();
          if (this.minStack.isEmpty())
              min = Integer.MAX_VALUE;
          else
              min = this.minStack.getFirst();
       }
       this.stack.pop();
    }

    public int top() {
        return this.stack.getFirst();
    }

    public int getMin() {
        return this.minStack.getFirst();
    }
    @Test
    public void test(){
        MinStack minStack = new MinStack();
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);
        Assertions.assertEquals(-3,minStack.getMin());
        minStack.pop();
        Assertions.assertEquals(0, minStack.top());
        Assertions.assertEquals(-2, minStack.getMin());
        minStack.pop();
        minStack.pop();
        minStack.push(1);
        minStack.push(1);
        Assertions.assertEquals(1, minStack.getMin());
        Assertions.assertEquals(1, minStack.getMin());
    }
```