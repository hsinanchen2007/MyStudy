从左到右遍历数组，假设遍历的数组下标序号为i，每遍历到一个数就比较以栈顶元素为下标的数和当前数的大小，如果比当前元素小则弹出栈顶元素index，更新结果数组res[index] = i -index，继续这样的比较直到以栈顶元素为下标的数大于当前数为止，这时将当前的下标序号i入栈。
遍历完数组后需要判断栈是不是为空，如果不为空（留在栈中的元素表明后面之的温度都不会升高），则不停弹出栈中元素index，并更新结果数组res[index] = 0;
         
```
public int[] dailyTemperatures(int[] T) {
       int[] res = new int[T.length];
        Stack<Integer> stack = new Stack<>();

        for(int i=0;i<T.length;i++) {
            while (!stack.isEmpty() && T[stack.peek()]< T[i]) {
                int index = stack.pop();
                res[index] = i - index;
            }
            stack.push(i);
        }
        while (!stack.isEmpty()) {
            res[stack.pop()] = 0;
        }
        return res;
    }
```
