### 单调栈

以一个柱子为最矮的柱子, 向左右延伸, 能得到的最大矩形取决于它左右第一个比它矮的柱子的位置.

维护一个单调递增的栈, 栈中储存位置, 比较的关键字是该位置的柱子高度. 从左到右遍历每一个位置, 都要入栈, 但是在入栈前, 如果栈顶的位置的柱子比自己高, 就要将栈顶弹出.

在每一个位置出栈时即可计算出左右第一个比它矮的柱子的位置 (得益于单调栈的性质).

- 如果栈中还有元素, 那么栈顶就是它左边第一个比它矮的柱子位置
- 如果栈中没有元素, 那么左边没有比它矮的位置
- 把当前位置挤出栈的元素就是右边第一个比它矮的位置

### 代码

```java
/**
 * 单调栈
 * 维护一个单增的栈 (栈中储存下标, 比较关键字是下标对应位置的高度)
 * 当一个点出栈时, 计算出的就是以该点的柱子为高, 往左右延伸能得到的最大矩形面积
 * (高 = 该点高度, 宽 = 当前点出栈后的栈顶与把当前点挤出栈的位置差)
 */
class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> stk = new Stack<>();
        int res = 0;
        for (int i = 0; i < heights.length; i++) {
            while (!stk.isEmpty() && heights[i] < heights[stk.peek()]) {
                int idx = stk.pop();    // 计算 idx 的柱子往左右延伸能得到的最大矩形面积
                int h = heights[idx];
                int w = i - (stk.isEmpty() ? 0 : stk.peek() + 1);
                res = Math.max(res, h * w);
            }
            stk.push(i);
        }
        // 把栈中剩余的元素一一弹出, 并计算
        while (!stk.isEmpty()) {
            int idx = stk.pop();    // 计算 idx 的柱子往左右延伸能得到的最大矩形面积
            int h = heights[idx];
            int w = heights.length - (stk.isEmpty() ? 0 : stk.peek() + 1);
            res = Math.max(res, h * w);
        }
        return res;
    }
}

```