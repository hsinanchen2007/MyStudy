### 解题思路
**思路1：**
这道题可以通过两次遍历暴力解决。
1. 第一次遍历，找出数组元素最大值。
2. 第二次遍历，计算其他元素是否满足条件。

**暴力破解代码：**
```java
class Solution {
    public int dominantIndex(int[] nums) {
        int maxIndex = 0;
        // 找出最大值
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        for (int i = 0; i < nums.length; ++i) {
            // 不满足条件返回 -1 
            if (maxIndex != i && nums[maxIndex] < 2 * nums[i])
                return -1;
        }
        return maxIndex;
    }
}
```

**思路2：**
简单推理可知，当最大元素是第二大元素的两倍及以上，那么其他的元素自然也符合条件。
所以，我们只需要将，最大元素和第二大元素找出来比较即可。
与思路1相比，思路2只需要计算比较一次。

**第二大元素比较代码：**
```java
class Solution {
    public int dominantIndex(int[] nums) {
        int maxIndex = 0;
        int second = Integer.MIN_VALUE;
        int length = nums.length;
        
        // 最大的元素
        for (int i = 1; i < length; i++){
            if (nums[i] > nums[maxIndex]){
                maxIndex = i;
            }
        }
        // 第二大的元素
        for (int i = 0; i < length; i++){
            if (i == maxIndex) continue;
            if (nums[i] >= second) second = nums[i];
        }
        
        if (second == Integer.MIN_VALUE || nums[maxIndex] >= second * 2) return maxIndex;
        
        return -1;
    }
}
```