```java
public class Trap {

    public int trap(int[] height) {
        //单调栈记录单调递减的元素的索引
        Stack<Integer> stack = new Stack<>();
        int ans = 0;
        for (int i = 0; i < height.length; i++) {
            //栈顶元素 < 新的墙，可以接雨水
            while (!stack.isEmpty() && height[stack.peek()] < height[i]) {
                int bottom = stack.pop();
                if (!stack.isEmpty()) {
                    int left = stack.peek();//左边界
                    int w = i - left - 1;   //雨水宽度
                    int h = Math.min(height[left], height[i]) - height[bottom];//雨水高度
                    ans += w * h;
                }
            }
            stack.push(i);
        }

        return ans;
    }

}
```
