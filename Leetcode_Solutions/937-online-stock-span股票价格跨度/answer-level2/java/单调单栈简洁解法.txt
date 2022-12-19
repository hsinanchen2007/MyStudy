```
class StockSpanner {

    private Deque<int[]> stack = new ArrayDeque<>(); 
    private int nextIndex = 0;

    public StockSpanner() {
        stack.push(new int[]{nextIndex++, 100000});
    }
    
    public int next(int price) {
        while(stack.peek()[1] <= price){
            stack.pop();
        }
        int span = nextIndex - stack.peek()[0];
        stack.push(new int[]{nextIndex++, price});
        return span;
    }
}
```