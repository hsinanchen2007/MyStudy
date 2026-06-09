1. 暴力法
2. 双指针法
双指针法最重要的问题就是应该移动那个指针。
对该题而言，先引入一个计算容量的表达式(right - left) * Math.min(height[left], height[right])。
因为两个指针是逐渐逼近的，所以表达式right - left肯定是渐渐变小的。
但是我们所求的是最大的容量，所以在指针移动过程中，Math.min(height[left], height[right])必须变大才有可能得到更大的容量，从这里也就可以知道双指针在移动时应该移动height[left]和height[right]中数值小的那个。
时间复杂度：O(n)

作者：karua
链接：https://leetcode-cn.com/problems/container-with-most-water/solution/java-jsde-bao-li-fa-he-shuang-zhi-zhen-fa-by-karua/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
![image.png](https://pic.leetcode-cn.com/b91d337d6de74fdc1e1f99099908c9b5b13d20c8d1379c6fd9d15847b2fac7db-image.png)
```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int res = min(height[l], height[r]) * (r-l);
        while (l < r) {
            if (height[l] < height[r]) {
                l += 1;
                res = max(res, min(height[l], height[r]) * (r-l));
            }
            else {
                r -= 1;
                res = max(res, min(height[l], height[r]) * (r-l));
            }
        }
        return res;
    }
};
```

