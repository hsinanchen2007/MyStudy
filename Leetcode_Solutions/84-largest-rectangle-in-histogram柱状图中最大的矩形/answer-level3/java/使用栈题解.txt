class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> stackList=new Stack();
        stackList.push(-1);

        int maxarea=0;
        for(int i=0;i<heights.length;i++){
            while(stackList.peek()!=-1&&heights[stackList.peek()]>heights[i]){
               maxarea=Math.max(maxarea,heights[stackList.pop()]*(i-1-stackList.peek())); 
            }
            stackList.push(i);
        }

        while(stackList.peek()!=-1){
        maxarea=Math.max(maxarea,heights[stackList.pop()]*(heights.length-stackList.peek()-1)); 
        }
        return maxarea;

    }
}

先把栈底放入-1
挨个把下标放入栈中，如果当前一个比栈顶端的小，则停止入栈。
依次出栈，因为栈里从大到小排列，所以最顶端面积就是高度*(i-1-栈的下标)。
直到栈底为-1。
循环放入栈结束后
依次出栈算出栈里面最大面积，length-栈的下标。
