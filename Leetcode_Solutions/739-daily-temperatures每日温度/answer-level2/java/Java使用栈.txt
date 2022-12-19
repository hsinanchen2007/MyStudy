## 基本思路
以某个元素为出发点，第一想法是将后续所有元素入栈，再遍历栈顶与当前元素比较。  
遍历过程中我们要找的是首个更大值的下标，某个大值后的较小值对我们毫无意义，剔除降序片段，所以我们的目标是 __维护一个从栈顶至栈底递增的栈__ 。

根据栈后进先出的特性，要从后往前遍历数组。目的是获取下标差值，所以栈保存下标而不是值。

如果当前元素大于等于栈顶元素，则重复pop，直到栈顶元素大于当前元素，二者下标差值即为所求。  
如果栈为空，说明栈中没有大于当前元素的值，保存0。  
将当前元素（新的最小值）入栈。

## 代码
```
class Solution {
    public int[] dailyTemperatures(int[] T) {
        int[] result = new int[T.length];
        Stack<Integer> stack = new Stack<>();
        for (int i = T.length - 1; i >= 0; i--) {
            // 循环pop，直到栈顶大于当前元素
            while (!stack.isEmpty() && T[i] >= T[stack.peek()]) stack.pop();
            result[i] = stack.isEmpty() ? 0 : stack.peek() - i;
            stack.push(i);
        }
        return result;
    }
}
```
