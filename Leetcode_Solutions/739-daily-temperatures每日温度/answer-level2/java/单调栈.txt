```
class Solution {
    //单调栈从顶到底严格减，有些严格增，保存其下标，有些保存值
    public int[] dailyTemperatures(int[] T) {
        int[] res = new int[T.length];
        Stack<Integer> stack = new Stack<>();
        for(int i=0;i<T.length;i++) {
            //栈里保存的是下标，若果满足栈不空且目前对应i值大于栈里的值，那就是满足第一个右边
            while(!stack.isEmpty() && T[stack.peek()]<T[i]) {
                res[stack.peek()] = i-stack.pop();
            }
            stack.push(i);
        }
        //当循环完了栈里还有下标证明还有没找到的
        while(!stack.isEmpty()) {
            res[stack.pop()] = 0;
        }
        return res;
    }
}
```
