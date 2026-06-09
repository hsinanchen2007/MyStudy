### 解题思路
缓存两端最大值，从最大值较小的一边进行储水结算、移动，并更新最大值。

![微信截图_20200227215758.png](https://pic.leetcode-cn.com/b1eed5a1a6d0e4821da10fd28fbe504bccbfb528a106d87c8cb3fd60ac6fd2a8-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200227215758.png)


### 代码

```java
class Solution {
    public int trap(int[] height) {
        if(height.length < 3) return 0;

        int left = 0, right = height.length - 1;
        int leftmax = height[left], rightmax = height[right];
        int res = 0;

        while(left < right){
            if(leftmax < rightmax){
                res += leftmax - height[left++];
                leftmax = Math.max(height[left], leftmax);
            }else{
                res += rightmax - height[right--];
                rightmax = Math.max(height[right], rightmax);
            }
        }

        return res;
    }
}
```