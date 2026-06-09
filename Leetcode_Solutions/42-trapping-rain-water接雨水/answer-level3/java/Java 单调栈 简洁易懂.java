维护一个单调递减栈，栈中存放墙的索引。
1）当栈顶元素大于等于height[i]时，将i入栈，栈依然保持单调递减，此时由于是递减的，并没有形成凹陷，所以不能接雨水。
2）当栈顶元素小于height[i]时，说明形成了凹陷，此时可以接雨水。若将其入栈，则栈不再单调。我们不断弹出栈顶元素，直到栈为空或者栈顶元素大于等于height[i]，使栈保持有序。在每次弹出时进行如下操作，计算下列数值。
    2-1）雨水底部(bottom): 保存刚才弹出的栈顶元素，此即为盛放雨水的墙所对应的索引
    2-2)  左边界(left): 栈不为空时，说明有左边界，可以形成凹陷。栈顶元素即为盛放雨水的墙左边相邻的墙所对应的索引。
    2-3）右边界(right:) 明确右边界, 右边界对应的索引即为i
    2-4）宽度(width): 计算雨水的宽度。w = 右边界-左边界-1
    2-5）高度(height): 计算雨水的宽度。h = min(右边界的高度，左边界的高度) - bottom
    2-6)  结果(ans): 累加结果

代码如下：
``` java
public class Trap {

    public int trap(int[] height) {
        //单调栈记录单调递减的元素的索引
        Stack<Integer> stack = new Stack<>();
        int ans = 0;
        for (int i = 0; i < height.length; i++) {
            //栈顶元素 < 新的墙，可以接雨水
            while (!stack.isEmpty() && height[stack.peek()] < height[i]) {
                int bottom = stack.pop();   //雨水底部
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
