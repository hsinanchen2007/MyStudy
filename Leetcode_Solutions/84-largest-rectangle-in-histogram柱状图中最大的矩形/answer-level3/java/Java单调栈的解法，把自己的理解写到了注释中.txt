    public int largestRectangleArea(int[] heights) {
        int max = 0, i = 0;
        // 保存柱形的位置，栈底->栈顶对应的height是单调递增的
        Stack<Integer> posStack = new Stack<>();
        // 为方便统一处理，设置一个终极左边界
        posStack.push(-1);

        for (; i < heights.length; ++i) {
            // 当遇到不满足递增条件的位置 i 时，需要出栈直到满足
            while (posStack.peek() >= 0 && heights[i] <= heights[posStack.peek()]) {
                // 之所以出栈丢弃这些位置不会产生问题
                // 是因为后续柱形若能扩展到位置 i ，就一定能穿过这些丢弃的位置拓展到更前面去
                int j = posStack.pop();
                // 出栈的同时计算出栈位置 j 对应图形向两边扩展能得到的最大矩形
                // 显而易见图形 j 能扩展到的右边界就是i
                // 又因为有递增保证，所以左边界就是pop之后栈顶保存的位置
                max = Math.max(max, (i - posStack.peek() - 1) * heights[j]);
            }
            // 满足递增条件了，可以把当前位置入栈了
            posStack.push(i);
        }

        // 把栈中剩余的位置计算完
        while (posStack.peek() >= 0) {
            int j = posStack.pop();
            max = Math.max(max, (i - posStack.peek() - 1) * heights[j]);
        }

        return max;
    }