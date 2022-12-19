/**
    思路:
    给定一个存取最小值的变量 min,每次在入栈时进行判断,当 min 大于存入栈中 x 时 将存取的角标赋值给min
    在pop时进行判断 当 min 被取出时再次获取最小值
*/
```java
class MinStack {
    private int[] stack;
    private int size;
    private int min = 0;//记录最小值
    /** initialize your data structure here. */
    public MinStack() {
        stack = new int[1000];
        size = -1;
    }
    
    public void push(int x) {
        if (size + 1 >= stack.length){
            stack = addLength(size * 2);
        }
        
        stack[++size] = x;
        
        if(stack[min] > stack[size]){
            min = size;
        }
    }
    
    public int[] addLength(int length){
        int[] temp = new int[length];
        for (int x = 0; x <= size; x++){
            temp[x] = stack[x];
        }
        return temp;
    }
    
    public void pop() {
        --size;
        if (size + 1 == min && size <= 0){
            min = 0;
        } else if (size + 1 == min){
            min = size;
            for (int x = 0 ; x < size; x++){
                if (stack[min] > stack[x])
                    min = x;
            }
        }
    }
    
    public int top() {
       return size < 0 ? stack[0] : stack[size];
    }
    
    public int getMin() {
        return stack[min];
    }
}
