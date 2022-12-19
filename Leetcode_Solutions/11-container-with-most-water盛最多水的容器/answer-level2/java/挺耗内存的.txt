### 解题思路
此处撰写解题思路

### 代码

```java
import java.lang.Math;
class Solution {
    public int maxArea(int[] height) {
        //双指针
        int i=0;
        int j=height.length-1;
        int max =0;
        while(i!=j){
            max = Math.max(max,Math.min(height[i],height[j])*(j-i));
            if(height[i]>=height[j]){
                j--;
            }else{
                i++;
            }
        }
    return max;
    }
}
```