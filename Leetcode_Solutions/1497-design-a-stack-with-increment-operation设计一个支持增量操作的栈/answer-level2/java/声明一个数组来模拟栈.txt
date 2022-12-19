![2020032201.PNG](https://pic.leetcode-cn.com/83bdcbc2321bbdfefe6c8414050dd7a4ccdb89fe00d9cd7178ff5b98fcfc6b21-2020032201.PNG)

### 解题思路
1. 声明一个数组来模拟栈的压入栈和弹出栈的操作;

2. 当给栈底元素实现增量操作时, 从左边遍历数组, 并给数组的元素增加一定量的值

### 代码

```java
class CustomStack {
    private int[] stack;
    private int maxSize;
    private int left = -1;
    private int temp = 0;
    public CustomStack(int maxSize) {
        this.maxSize = maxSize;
        stack = new int[maxSize];
    }
    
    public void push(int x) {
        if(left<maxSize-1){
            left++;
            stack[left] = x;
        }
    }
    
    public int pop() {
        if(left<0){
            return -1;
        }
        temp = stack[left];
        left--;
        return temp;
    }
    
    public void increment(int k, int val) {
        if(left<=k-1){
            for(int i=0;i<=left;i++){
                stack[i] += val;
            }
        }else if(k<left+1){
            for(int i=0;i<k;i++){
                stack[i] += val;
            }
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