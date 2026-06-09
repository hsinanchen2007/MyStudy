### 解题思路
双指针

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        if(height == null || height.length < 2){
            return 0;
        }

        int i = 0;
        int j = height.length - 1;
        int maxArea = 0;
        while(i < j){
            maxArea = Math.max(Math.min(height[i],height[j]) * (j - i),maxArea);
            if(height[i] == height[j]){
                i++;
                j--;
            }else if(height[i] > height[j]){
                j--;
            }else{
                i++;
            }
        }

        return maxArea;
    }
}
```