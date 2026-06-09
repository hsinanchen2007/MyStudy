### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int trap(int[] height) {
        if(height == null || height.length == 0) {
            return 0;
        }

        Stack<Integer> stack = new Stack<>();
        int res = 0;
        for (int i = 0; i < height.length; i++) {
            while (!stack.isEmpty() && height[stack.peek()] < height[i]) {
                int cur = stack.pop();//当前坐标
                //一直找到最左边的那个坐标，最右边的坐标就是i
                while(!stack.isEmpty() && stack.peek() == cur) {
                    stack.pop();
                }

                //i - stack.peek() - 1是宽
                //左右坐标取高度较小的
                if(!stack.isEmpty()) {
                    res += (Math.min(height[stack.peek()], height[i]) - height[cur]) * (i - stack.peek() - 1);
                }
            }

            stack.push(i);
        }

        return res;
    }
}
```