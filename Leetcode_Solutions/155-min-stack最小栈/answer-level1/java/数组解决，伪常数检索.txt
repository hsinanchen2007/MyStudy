思路：
1.通过头指针对数组下标的指向实现栈后进先出的特点；
2.在getmin方法中直接返回当前“栈”中的最小数；
3.在每次push操作时判断是否比预定的最小数要小，是则取其为最小数；
4.在每次pop操作时判断要出栈的值是否与最小数相等，是则去余下值中最小的数为最小数。

```
class MinStack {

    private static int[] stack = null;
	private static int head;
	private static int min;
	private static int j;

	/** initialize your data structure here. */
    public MinStack() {
        stack = new int[10000];
        min = 2147483647;
        head = 0;
        j = 0;
    }
    
    public void push(int x) {
		stack[head++] = x;
		if(x < min)
			min = x;
    }
    
    public void pop() {
    	if(top()==min) {
    		j = head - 2;
    		min = 2147483647;
    		while(j >= 0) {
    			if(stack[j--] < min)
    				min = stack[j+1];
    		}
    	}
    	if(--head < 0)
    		head = 0;
    }
    
    public int top() {
        return stack[head-1];
    }
    
    public int getMin() {
        return min;
    }
}
```
