双指针方法的思路，主要是围绕着算面积是按最小柱子来算，也就是不管是哪一边柱子高上天，算面积还是的宽度也是低柱子的高度，所以，移动柱子的时候，要移动矮柱子，也就是提高矮柱子的高度，也就是增加柱子的宽度... ...，第一次写题解，不知道我说的明不明白代码如下：
```
// 这是我简化过的代码， 如果有大神帮忙简化一下if-else语句，想了半天没想出来
class Solution {
    public int maxArea(int[] height) {
        int max = 0;
        int start = 0;
        int end = height.length - 1;
        while(start < end) {
            max = Math.max((end - start) * Math.min(height[start], height[end]), max);
            if(height[start] < height[end]) {
                start++;
            } else {
                end--;
            }
        }
        return max;
    }
}
// 这是我没简化过的代码，更容易理解一点
class Solution {
    public int maxArea(int[] height) {
        int max = 0;
        int area = 0;
        int start = 0;
        int end = height.length - 1;
        while(start < end) {
            area = (end - start) * Math.min(height[start], height[end]);
            if (max < area) {
                max = area;
            }
            if(height[start] < height[end]) {
                start++;
            } else {
                end--;
            }
        }
        return max;
    }
}
```
当然还有一种就枚举各种结果，这样的需要两次循环，复杂度就是n的平方，双指针的复杂度是n，所以双指针复杂度更低
```

class Solution {
    public int maxArea(int[] height) {
        int max = 0;
        for (int i = 0; i < height.length - 1; i++) {
            for (int j = i + 1; j < height.length; j++) {
                max = Math.max(max, (j - i) * Math.min(height[i], height[j]));
            }
        }
        return max;
    }
}

// 代码更加清晰版
class Solution {
    public int maxArea(int[] height) {
        int max = 0;
        int area = 0;
        for (int i = 0; i < height.length - 1; i++) {
            for (int j = i + 1; j < height.length; j++) {
                area =  ( j - i ) * Math.min(height[j], height[i]);
                if(area > max) {
                    max = area;
                }
            }
        }
        return max;
    }
}
```
