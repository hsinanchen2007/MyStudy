使用单调栈解决，看了题解后发现不是最优的，但也是个思路
```
/**
 * Solution, LeetCode
 *
 * @author jianghe
 * @since 2020-03-29
 */
class Solution {
    public int maxProfit(int[] prices) {
        // 从下至上的递增栈
        Stack<Integer> largerStack = new Stack<>();
        int max = 0;
        for (int price : prices) {
            if (!largerStack.empty() && largerStack.peek() >= price) {
                while (!largerStack.empty() && largerStack.peek() >=  price) {
                    int bottom = largerStack.get(0);
                    max = Math.max(max, largerStack.pop() - bottom);
                }
            }
            largerStack.push(price);
        }
        if (!largerStack.empty()) {
            max = Math.max(max, largerStack.peek() - largerStack.get(0));
        }

        return max;
    }
}
```
