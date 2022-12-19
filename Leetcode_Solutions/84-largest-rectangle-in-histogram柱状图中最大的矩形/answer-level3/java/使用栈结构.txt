### 解题思路
//解题思路：设置一个栈结构，自底向上的升序排列，本题所说最大面积，来源于，每根柱子向两边所能延长的最大面积
//之所以采用栈结构，是能够确定每一根柱子左边界（下一个位置），出现不满足升序的时候（右边界），计算面积，且当遍历完所有的柱子，有可能会出现有的柱子无右边边界的情况，将栈结构清空计算。最后得出最大面积值。时间复杂度为O(n)，空间复杂度为O(n)

### 代码

```java
class Solution {
    public int largestRectangleArea(int[] heights) {
        
        int max = 0;
        Stack<Integer> stack = new Stack<Integer>();
        stack.push(-1);//代表第一根柱子的左边界
        for(int i= 0;i<heights.length;i++){
            if(stack.peek() != -1){
                while(stack.peek() != -1 && heights[i] <heights[stack.peek()]){
                    max = Math.max(max,heights[stack.pop()]*(i-stack.peek()-1));
                }
                stack.push(i);
            }else{
                stack.push(i);
            }
        }
        if(stack.peek() != -1){
            while(stack.peek() != -1){
                max = Math.max(max,heights[stack.pop()]*(heights.length-stack.peek()-1));
            }
        }
        return max;
    }
}
```