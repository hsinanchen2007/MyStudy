### 解题思路
此处撰写解题思路
刚开始想到的便是双for（）语句，但是时间复杂度很高，看题解后用双指针，在数据量大的时候可以大大降低时间复杂度；

1.先将两个指针分别指向两个端点，
2.替换掉height值较小的那个指针，将指向height值较小的指针向内移动一位 
  （因为面积的大小在长度固定的情况下取决于height值较小的那一条边，所以需比较两个指针所指值得height值）
3.通过max函数取最大值，重复比较。

时间复杂度：O(n) 取决于比较的次数
空间复杂度：O(1)，使用的空间是不变的，定义了三个变量
### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        int area=0,i=0,j=height.length-1;
        while(i<j){
            area=Math.max(area,(j-i)*Math.min(height[i],height[j]));
            if(height[i]<=height[j])
                i++;
            else
                j--;
        }
        return area;
    }
}
```

刚开始的双for（）
时间复杂度：O(n^2)
空间复杂度：O(1),使用的空间恒定不变，定义了三个变量
```java 
 class Solution {
    public int maxArea(int[] height) {
        int area=0;
        for(int i=0;i<height.length-1;i++){
            for(int j=i+1;j<height.length;j++){
                area=Math.max(area,(j-i)*Math.min(height[i],height[j]));
            }
        }
        return area;
    }
}
```
