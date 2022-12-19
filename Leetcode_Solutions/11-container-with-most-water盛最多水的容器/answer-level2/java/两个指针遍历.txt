### 解题思路
使用两个指针来遍历，类似于最长子字符串。

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        if(height.length<2)return 0;
        int maxArea =0;
        for(int i =0; i<height.length ; i++){
            for(int j = i+1;j<height.length;j++){
                maxArea =Math.max(area(i,j,height),maxArea);
            }
            
        }
        return maxArea;
    }
    public int area(int i ,int j,int[] height){
           int are=(j-i)*Math.min(height[i],height[j]);
           return are;
    }
}
```