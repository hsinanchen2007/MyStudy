##### 1. 暴力法
- 利用两层遍历，计算任意两个柱子所形成的容器的容量，保存最大的容量即可。
- 时间复杂度：O($n^{2}$)
```java []
class Solution {
    public int maxArea(int[] height) {
        int res = 0;
        for (int i = 0; i < height.length - 1; i++) {
            for (int j = i + 1; j < height.length; j++) {
                int temp = (j - i) * Math.min(height[i],height[j]);
                if (temp > res) {
                    res = temp;
                }
            }
        }
        return res;
    }
}
```

```javascript []
var maxArea = function(height) {
    var res = 0;
    for (var i = 0; i < height.length - 1; i++) {
        for (var j = i + 1; j < height.length; j++) {
            var temp = (j - i) * Math.min(height[i],height[j]);
            if (temp > res) {
                res = temp;
            }
        }
    }
    return res;
};
```

##### 2. 双指针法
- 双指针法最重要的问题就是应该移动那个指针。
- 对该题而言，先引入一个计算容量的表达式`(right - left) * Math.min(height[left], height[right])`。
- 因为两个指针是逐渐逼近的，所以表达式`right - left`肯定是渐渐变小的。
- 但是我们所求的是最大的容量，所以在指针移动过程中，`Math.min(height[left], height[right])`必须变大才有可能得到更大的容量，从这里也就可以知道双指针在移动时应该移动`height[left]`和`height[right]`中数值小的那个。
- 时间复杂度：O(n)
```java []
class Solution {
    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int res = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                int temp = (right - left) * height[left];
                if (res < temp) {
                    res = temp;
                }
                left++;
            } else {
                int temp = (right - left) * height[right];
                if (res < temp) {
                    res = temp;
                }
                right--;
            }
        }
        return res;
    }
}
```

```javascript []
var maxArea = function(height) {
    var res = 0;
    var left = 0;
    var right = height.length - 1;
    while (left < right) {
        if (height[left] < height[right]) {
            var temp = (right - left) * height[left];
            if (temp > res) {
                res = temp;
            }
            left++;
        } else {
            var temp = (right - left) * height[right];
            if (temp > res) {
                res = temp;
            }
            right--;
        }
    }
    return res;
};
```
