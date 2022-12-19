### 解题思路
注释留下，记录尝试的过程

### 代码

```java
class Solution {
    public int[] dailyTemperatures(int[] T) {
        if (T == null || T.length == 0) {
            return T;
        }
        
//        int[] res = new int[T.length +2];
//        res[0] = Integer.MAX_VALUE;
//        res[res.length -1] = 0;
//        for(int i = 0; i < T.length; i++) {
//            res[i+1] = T[i];
//        }
        int[]  result = new int[T.length];
        Stack<Integer> stack  = new Stack<>();
//        stack.add(0);
        for(int i = 0; i <T.length; i++){
            while(!stack.isEmpty() && T[stack.peek()] < T[i]){
                int cur = stack.pop();
                // int temp = 0;
                // if(!stack.isEmpty()) {
                //     temp = stack.peek();
                // } 
                result[cur] = i - cur; 
            }
            stack.push(i);
        }
        
        return result;
    }
}
```