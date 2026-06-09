### 代码

```java
class Solution {
    public int[] dailyTemperatures(int[] T) {
        int[] ans = new int[T.length];
        
        Stack<Integer> stac = new Stack<>();
        
        stac.push(0);
        
        for(int i = 1; i < T.length; i++) {
            while(!stac.isEmpty() && T[i] > T[stac.peek()]) {
                int top = stac.pop();
                ans[top] = i - top;
            }
            stac.push(i);
        }
        
        return ans;
    }
}
```