### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int trap(int[] height) {
        int max1=0,max2=0,count=0;
      for(int i=0;i<height.length;i++){
          max1=0;max2=0;
          for(int j=0;j<i;j++){
              max1=Math.max(max1,height[j]);
          }
         for(int j=i+1;j<height.length;j++){
              max2=Math.max(max2,height[j]);
          }
          if(max1<height[i])max1=height[i];
          if(max2<height[i])max2=height[i];
          count+=Math.min(max1,max2)-height[i];
      }
      return count;
    }
}
```