### 解题思路
与84题的解决思路相同
如果选择第i行作为搜索矩形的底边，使用`lenght[j]`记录第j个位置上从下往上数1的个数，利用84题中搜索直方图中最大举行的算法可以得到以该行为底边的最大矩形面积
遍历矩阵中的所有行即可得到整个矩阵中的最大矩形面积

### 代码

```java
class Solution {
	
    public int maximalRectangle(char[][] matrix) {
        if(matrix.length < 1 || matrix[0].length < 1) {
            return 0;
        }
        int rowCnt = matrix.length;
        int colCnt = matrix[0].length;
        int[] heights = new int[colCnt];
        int maxArea = 0;
        for(int row = 0; row < rowCnt; row++) {
        	for(int col = 0; col < colCnt; col++) {
        		if(matrix[row][col] == '1') {
        			heights[col]++;
        		}
        		else {
        			heights[col] = 0;
        		}
        	}
        	int thisLineMax = maxRectangleForOne(heights);
        	maxArea = Math.max(maxArea, thisLineMax);
        }
        return maxArea;
    }
    
    public int maxRectangleForOne(int[] heights) {
    	// 维护一个单调递增的栈
    	Stack<Integer> stack = new Stack<Integer>();
    	int maxArea = 0;
    	stack.push(-1);
    	for(int i = 0; i < heights.length; i++) {
    		while(stack.peek() != -1 && heights[stack.peek()] > heights[i]) {
    			int height = heights[stack.pop()];
    			int bottom = i - stack.peek() - 1;
    			int area = height * bottom;
    			maxArea = Math.max(maxArea, area);
    		}
    		stack.push(i);
    	}
    	while(stack.peek() != -1) {
    		int height = heights[stack.pop()];
    		int bottom = heights.length - stack.peek()  - 1;
    		int area = height * bottom;
    		maxArea = Math.max(maxArea, area);
    	}
    	return maxArea;
    }
}
```