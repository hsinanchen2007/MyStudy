### 解题思路
此题可以看成[https://leetcode-cn.com/problems/largest-rectangle-in-histogram/](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)
![image.png](https://pic.leetcode-cn.com/a51844e53b540e2ff5c2a54b2ff7acb9cb1fcdd0e768b39834df6765e9249f61-image.png)
所以将此题转换成84题,进行计算即可

### 代码

```java
class Solution {
    public int maximalRectangle(char[][] matrix) {
        if(matrix.length==0){
            return 0;
        }
        int[]nums=new int[matrix[0].length];
        int result=0;
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[i].length;j++){
                if(matrix[i][j]=='1'){
                    nums[j]=nums[j]+1;
                }else{
                    nums[j] = 0;
                }
            }
            result=Math.max(result,largestRectangleArea(nums));
        }
        return result;
    }
    //单调递增栈
    private int largestRectangleArea(int[] heights) {
       Stack<Integer> stack=new Stack<>();
       int result=0;
       for(int i=0;i<heights.length;i++){
           while(!stack.isEmpty()&&heights[stack.peek()]>=heights[i]){
               int pop=stack.pop();
               if(stack.isEmpty()){
                   result=Math.max(result,heights[pop]*i);
               }else{
                   result=Math.max(result,heights[pop]*(i-stack.peek()-1));
               }
           }
           stack.push(i);
       }
       while(!stack.isEmpty()){
           int pop=stack.pop();
           if(stack.isEmpty()){
              result=Math.max(result,heights[pop]*heights.length); 
           }else{
               result=Math.max(result,heights[pop]*(heights.length-stack.peek()-1));
           }
       }
       return result;
    }
}
```