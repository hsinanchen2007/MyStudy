```
public int largestRectangleArea(int[] heights) {
        if (heights.length ==0 ) {
            return 0;
        }

        int maxArea = 0;
        for (int i=0; i<heights.length; i++) {
            int left=i-1;
            int right=i+1;
            while (left>=0 && heights[left] >= heights[i]) {
                left--;
            }
            while (right<heights.length && heights[right]>=heights[i]) {
                right++;
            }
            maxArea = Math.max(maxArea, (right-left-1)*heights[i]);
        }
        return maxArea;
    }
```
