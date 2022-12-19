### 执行结果
执行用时 :50 ms, 在所有 Java 提交中击败了12.80%的用户
内存消耗 :45.7 MB, 在所有 Java 提交中击败了12.44%的用户
### 解题思路
使用数组实现最小栈。
1. 在类中定义成员变量数组arr，长度越大越小，为了通过本题的编译，我将长度设计成了10000的大小；
2. 定义成员变量i,它表示栈的指针，当push进一个元素时i++，当pop出一个元素时i--;
3. 利用`min=Math.min(min, arr[j]);`来求取最小值；

### 代码

```java
class MinStack {
    int [] arr= new int[10000];
	int i=0;
	public MinStack() {
        
    }
    
    public void push(int x) {
        arr[i]=x;
        i++;
    }
    
    public void pop() {
        arr[i-1]=0;
        i--;
    }
    
    public int top() {
        return arr[i-1];
    }
    
    public int getMin() {
    	int min=arr[0];
        for(int j=0;j<i;j++) {
        	min=Math.min(min, arr[j]);
        }
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