### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        //遍历，需要两个参数，minHeight,maxIndex
        int maxArea=0;
        int maxIndex;
        for(int i=0;i<height.length;i++){
            maxIndex=0;
            for(int j=0;j<height.length;j++){
                if(height[i]== Math.min(height[i],height[j])&& Math.abs(j-i)>maxIndex){
                    maxIndex=Math.max(Math.abs(j-i),maxIndex);
                    maxArea=Math.max(maxIndex*height[i],maxArea);
                }
            }
        }
        return maxArea;
    }
}
```