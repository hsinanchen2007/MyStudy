### 解题思路

### 代码

```java
class StockSpanner {
    
    public StockSpanner() {
        
    }
   Stack<Integer> stack =  new Stack<>();
    Map<Integer, Integer> map = new HashMap<Integer, Integer>();
    public int next(int price) {
        int num = 1;
        int temp = 0;
        
        while (!stack.isEmpty() && stack.peek() <= price) {
            temp = map.get(stack.peek());
            stack.pop();
            num += temp;
        }
        stack.push(price);

        map.put(price, num);
        return num;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
```