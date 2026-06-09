```java []
class Solution {
    public int mctFromLeafValues(int[] arr) {
        int res = 0;
        Stack<Integer> stack = new Stack<>();
        stack.push(Integer.MAX_VALUE);
        for (int leaf : arr) {
            while (leaf >= stack.peek()) {
                int mid = stack.pop();
                res += mid * Math.min(stack.peek(), leaf);
            }
            stack.push(leaf);
        }
        while (stack.size() > 2) {
            res += stack.pop() * stack.peek();
        }
        return res;
    }
}
```
