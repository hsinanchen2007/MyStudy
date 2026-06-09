### 解题思路
单调栈,遇到heights[i]>heights[i-1] 入栈,heights[i-1]>=heights[i]出栈

### 代码

```java
class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> stack=new Stack<>();
        int result=0;
        for(int i=0;i<heights.length;i++){
            //如果栈顶元素大于heights[i],说明j<i heights[j]>=heights[i],出栈计算
            while(!stack.isEmpty()&&heights[stack.peek()]>=heights[i]){
                //弹出栈顶元素
                int pop=stack.pop();
                //如果此时栈变为空,那么宽度就是i,如果栈不为空那么宽度是i-stack.peek()-1
                if(stack.isEmpty()){
                    result=Math.max(result,heights[pop]*i);
                }else{
                    result=Math.max(result,heights[pop]*(i-stack.peek()-1));
                }
            }
            stack.push(i);
        }
        //如果到达数组尾部,栈内存在数据,那么继续判断栈内元素,进行计算
        while(!stack.isEmpty()){
            int pop=stack.pop();
            //此时栈为空宽度为heights.length,因为栈为空时候pop是整个数组最小的
            if(stack.isEmpty()){
                result=Math.max(result,heights[pop]*heights.length);
            }else{
                //宽度是heights.length-stack.peek()-1
                result=Math.max(result,heights[pop]*(heights.length-stack.peek()-1));
            }
        }
        return result;
    }
}
```