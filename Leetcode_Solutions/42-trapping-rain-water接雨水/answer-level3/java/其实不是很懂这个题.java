### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int trap(int[] height) {
        if (height == null){
            return 0;
        }

        Stack<Integer> stack = new Stack<>();

        int ans = 0;
        for(int i = 0; i < height.length; i++){
            while(!stack.isEmpty() && height[stack.peek()] < height[i]){
                int curIdx = stack.pop();
                while(!stack.isEmpty() && height[stack.peek()] == height[curIdx]){
                    stack.pop();
                }

                if(!stack.isEmpty()){
                    int stackTop = stack.peek();
                   ans += (Math.min(height[stackTop], height[i]) - height[curIdx]) * (i - stackTop - 1);
                }
            }
            stack.add(i);
        }
        return ans;

    }
}
```