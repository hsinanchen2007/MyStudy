```
    /**
     * 栈
     * @param T
     * @return
     */
    public int[] dailyTemperatures(int[] T) {
        int[] retArr = new int[T.length];
        Stack<Integer> stack = new Stack();
        for (int i = 0 ; i < T.length ; i++){
            boolean flag = true;
            while (stack.size() != 0 && flag) {
                int index = stack.pop();
                if(T[i]>T[index]){
                    retArr[index] = i-index;
                }else {
                    stack.push(index);
                    flag = false;
                }
            }
            stack.push(i);
        }
        return retArr;
    }
```
