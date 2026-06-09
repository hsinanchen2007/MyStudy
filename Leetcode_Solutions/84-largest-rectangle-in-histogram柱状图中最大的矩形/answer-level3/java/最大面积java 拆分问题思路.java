### 解题思路
    假设每次新增一个边的时候出现可能出现最大面积的情况
    1.新增边的面积最大
    2.新增面以后底部横向民机最大
    3.从左至右有可能出现最大面积
### 代码

```java
class Solution {
    //拆分问题横向处理
    public int largestRectangleArea(int[] heights) {
        if(heights.length == 0) return 0;
        int max = 0,index = 0,min =heights[0];
        while(index < heights.length){
            if(heights[index] < min){
                min = heights[index];
            }

            // 计算横向面积与本身的面积
            int count =  min * (index+1) >  heights[index] ? min * (index+1) : heights[index];
            if(count > max){
                max = count;
            }
            int newmin = heights[index];
            //往回开始算
            for(int i = index-1; i >= 0; i--){
                if(newmin > heights[i]){
                    newmin = heights[i];
                }
                max = max > newmin * (index-i+1) ? max : newmin * (index-i+1);
            }
            index++;
        }
        return max;
    }
}
```