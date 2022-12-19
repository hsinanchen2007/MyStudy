## 思路

* 暴力法，每个高度都计算一遍最长的连续的底，然后取最大值。

* 其实这道题的本质就是转化为求每个高度对应的最长的连续的底，即对两边分别找第一个小于遍历的数的高度的索引值（即求矩形的最长的底），这点和``接雨水`` 有点相似，同时，采用单调递增栈的方法  跟 ``求最大有效括号`` 这道题有异曲同工之处，都是采用了栈存取数组索引值的方法！
* 为何说单调递增栈（严格递增）能非常轻松的找到 height[i] 的 两边刚好比它的高度小的第一个数 呢？
  * <font color='red'>这里我们先假设所有的高度都是不会相同的。</font> 首先由于栈是递增的，当 height[i] 比栈顶的索引值对应的高度 大时，直接压入栈即可，否则说明 height[i] 比栈顶的索引值对应的高度小，则栈顶对应的右边第一个小于它的高度的数找到了，就是 height[i]，然后把栈顶元素弹出，新栈顶的元素即是刚才弹栈元素左边第一个小于它的高度的数，这样就很轻松的找到了两边分别小于 栈顶元素的数，这样取更新最大值就行了。
  * 所以，我们现在来考虑一下取消开始那个前提条件，现在有的高度是会相同的，这个条件我们怎么处理呢？当面临栈顶元素和遍历的元素对应的高度相同时，我们只需要更新栈顶元素的值（即将其存入的索引变为新的我们正在遍历的元素的索引值），我举个例子，比如说 2 5 6 7 5 6 3，当遍历到最后一个数 5 时，此时栈顶值为 1（索引 1 对应的高度是 5 ），我们只要把栈顶值变为 4 即可。
  * 当然这样还有一个问题，就是假如是 2 5 6 7，高度一直递增，四个值全部入栈了，此时最后一个元素 7 的 右边第一个小于它的高度其实没有，我们可以令其为 height.length。

## 代码

* 暴力法

```java
class Solution {
    public int largestRectangleArea(int[] heights) {
        HashSet<Integer> heightsSet = new HashSet<Integer>();
        //得到所有的高度，也就是去重。
        for (int i = 0; i < heights.length; i++) {
            heightsSet.add(heights[i]);
        }
        int maxArea = 0;
        //遍历每一个高度
        for (int h : heightsSet) {
            int width = 0;
            int maxWidth = 1;
            //找出连续的大于等于当前高度的柱形个数的最大值
            for (int i = 0; i < heights.length; i++) {
                if (heights[i] >= h) {
                    width++;
                //出现小于当前高度的就归零，并且更新最大宽度
                } else {
                    maxWidth = Math.max(width, maxWidth);
                    width = 0;
                }
            }
            maxWidth = Math.max(width, maxWidth);
            //更新最大区域的面积
            maxArea = Math.max(maxArea, h * maxWidth);
        }
        return maxArea;
    }
}
```

> 作者：windliang
> 链接：https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-1-7/
> 来源：力扣（LeetCode）
> 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

* 单调递增栈法

```java
class Solution {
    public int largestRectangleArea(int[] heights){
        Stack<Integer> stack = new Stack<>();
        int max = 0;
        stack.push(-1);
        for(int i = 0; i < heights.length; i++){
            // 1. 栈中值不等于 -1 且 栈顶元素对应的高度 大于 正在遍历的元素的高度
            while(stack.peek() != -1 && heights[stack.peek()] > heights[i]){
                max = Math.max(max,heights[stack.pop()] * (i - stack.peek() - 1));
            }
            // 2. 栈中值不等于 -1 且 栈顶元素对应的高度  == 正在遍历的元素的高度
            // 直接把当前栈顶弹栈即可
            if(stack.peek() != -1 && heights[stack.peek()] == heights[i]){
                stack.pop();
            }
            stack.push(i);
        }
        // 遍历完了，但是没计算完
        while(stack.peek() != -1){
            max = Math.max(max,heights[stack.pop()] * (heights.length - stack.peek() - 1));
        }
        return max;
    }
}
```