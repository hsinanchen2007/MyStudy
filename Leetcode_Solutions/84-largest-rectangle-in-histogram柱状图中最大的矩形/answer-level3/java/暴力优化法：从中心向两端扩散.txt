### 解题思路
此处撰写解题思路
从每个高度为中心，分别向两端扩散，扩散的终止条件是遇到的数字小于中心数字，然后计算面积，然后更新最大面积

### 代码

```java
class Solution {
    public int largestRectangleArea(int[] heights) {

        int max=0;
        for(int i=0;i<heights.length;i++){
            int level = heights[i];
            int len = 1;
            for(int j=i+1;j<heights.length;j++){
                if(heights[j]>=level){
                    len++;
                }else{
                    break;
                }
            }
            for(int j=i-1;j>=0;j--){
                if(heights[j]>=level){
                    len++;
                }else{
                    break;
                }
            }
            int rectangle = len*level;
            if (rectangle>max)
                max=rectangle;

        }
        return max;
    }
}
```