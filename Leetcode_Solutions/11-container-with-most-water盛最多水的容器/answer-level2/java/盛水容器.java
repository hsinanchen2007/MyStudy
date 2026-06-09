### 解题思路
暴力法，低内存，长时间；需要改进；

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        int max=-1;
        for(int i=0;i<height.length-1;i++){
            for(int j=i+1;j<height.length;j++){
                int temp;
                if(height[i]>=height[j]){
                     temp=(j-i)*height[j];
                    max=max>temp?max:temp;
                }else{
                     temp=(j-i)*height[i];
                    max=max>temp?max:temp;
                }
            }
        }
        return max;
    }
}
```