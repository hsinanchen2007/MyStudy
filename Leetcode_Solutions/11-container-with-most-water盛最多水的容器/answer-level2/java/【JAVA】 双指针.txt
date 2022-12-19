### 解题思路
双指针遍历数组
每次比较保留值最大指针，另外的指针进行移动

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
               if (height.length < 2) {
            return 0;
        }
        int b = 0,e = height.length - 1,max = 0;
        while (b  < e) {
            int temp = Math.min(height[b],height[e]) * (e - b );
            if (temp > max) {
                max = temp;
            }
            if (height[b] > height[e]) {
                e--;
            } else {
                b++;
            }
        }
//        System.out.println(Arrays.toString(height));
        return max;
    }
}
```