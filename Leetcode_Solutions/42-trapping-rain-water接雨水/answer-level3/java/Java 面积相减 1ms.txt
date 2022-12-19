### 解题思路
Java双指针
总面积 = 柱子面积 + 雨水面积
### 代码

```java
class Solution {
    public int trap(int[] height) {
        int c = 0,len = height.length, l = 0, r = len - 1, sum = 0, last = 0;
        if(len == 0)
            return 0;
        
        //求出总面积
        while(l < r){
            //找到下一个可用左指针
            while(l < r && height[l] <= last)
                l++;
            
            //找到右指针
            while(l < r && height[r] <= last)
                r--;

            //没有可用指针
            if(l >= r)
                break;

            //求出这次层次雨水和柱子总面积
            sum += (Math.min(height[l], height[r]) - last) * (r - l + 1);
            last = Math.min(height[l], height[r]);
        }
        //加上最高柱子的剩余面积
        sum += height[l] - last;

        //柱子总面积
        for(int i = 0; i < len; i++){
            c += height[i];
        }
        return sum - c;
    }
}
```