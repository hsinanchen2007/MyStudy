### 解题思路
此处撰写解题思路
直接暴力破解
### 代码

```java
import java.lang.Math;
class Solution {
    public int maxArea(int[] height) {
        int result = 0;
        for(int i=0;i<height.length-1;i++){
            for(int j=i+1;j<height.length;j++){
                result = Math.max(result,(j-i)*Math.min(height[j],height[i]));
            }
        }
        return result;
    }
}
```