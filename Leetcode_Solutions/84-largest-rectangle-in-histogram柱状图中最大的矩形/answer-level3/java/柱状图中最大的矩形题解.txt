### 解题思路
穷举法，从中心向两边扩展

### 代码

```java
class Solution {
    public int largestRectangleArea(int[] heights) {
        //穷举法
        int max=0;
        for(int i=0;i<heights.length;i++){
            int height=heights[i];
            int width=0;
            for(int j=i;j>=0;j--){
                if(heights[j]>=heights[i]){
                    width++;
                }else{
                    break;
                }
            }
            for(int j=i+1;j<heights.length;j++){
                if(heights[j]>=heights[i]){
                    width++;
                }else{
                    break;
                }
            }
            max=Math.max(max,height*width);
        }
        return max;
    }
}
```