### 解题思路
数组中包含两种数值，且要求分布在不同区域。容易想到用双指针。
创建一个新数组存储结果，遍历原数组，当数值为奇数时从新数组的头部开始存储，数值为偶数时从新数组的尾部开始存储，知道左右指针相等。
一定不要忘了考虑边界情况。

### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        if (nums.length < 2) return nums;
        int[] result = new int[nums.length];
        int left = 0, right = nums.length - 1;
        while (left < right) {
            for (int num : nums){
                if (num % 2 == 0) result[right--] = num;
                else result[left++] = num;
            }
        }
        return result;
    }
} 
```