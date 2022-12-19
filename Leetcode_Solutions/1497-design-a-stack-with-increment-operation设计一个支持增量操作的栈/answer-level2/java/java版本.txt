### 解题思路
用整型数组nums存储数据，top记录当前的栈顶在哪

### 代码

```java
class CustomStack {
    private int[] nums;
    private int top;

    public CustomStack(int maxSize) {
        nums = new int[maxSize];
        top = 0; 
    }
    
    public void push(int x) {
        if (top >= nums.length)
            return;
        nums[top] = x;
        top++;
    }
    
    public int pop() {
        if (top == 0) 
            return -1;
        return nums[--top];
    }
    
    public void increment(int k, int val) {
        int min = k < top ? k : top;
        for (int i = 0; i < min; i++) {
            nums[i] += val;
        }

    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */
```