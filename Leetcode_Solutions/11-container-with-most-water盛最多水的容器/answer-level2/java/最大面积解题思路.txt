### 解题思路
第一种解法：笨方法
    双层循环：时间复杂度O(n^2)
第二种解法：在第一种解法上面进行升维，利用两个指针，减少一层循环
    首先保证一点长度最大（s=c*k）,其次如果想要面积超出前一种情况，只能减少长度的同时，新增高度，
这样才可能会出现面积超出前一种的情况，时间复杂度O(n)

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        //1.笨方法：双城循环O(n)
        // int max = 0;
        // for(int i = 0;i<height.length-1; i++){
        //     for(int j = 1; j< height.length;j++){
        //         int area = (j-i)*Math.min(height[i],height[j]);
        //         max = Math.max(max,area);
        //     }
        // }
        // return max;

        //双指针的方法（长度最大，在其中找最高的线）
        int i = 0 ,j = height.length-1;
        int max = (j-i)*Math.min(height[i],height[j]);
        while(i<j){
            if(height[i] <height[j]){
                i++;
            }else{
                j--;
            }
            int area = (j-i)*Math.min(height[i],height[j]);
            max = Math.max(area,max);
        }
        return max;
        
    }
}
```