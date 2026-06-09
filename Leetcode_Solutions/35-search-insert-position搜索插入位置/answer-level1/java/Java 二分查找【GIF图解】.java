### 解题思路

**题目的任务：** 在一个 *已排序的数组* 中找到目标值的位置。
**思路：**
从头到尾逐个对元素进行比较。
1. 当前元素等于目标元素时，返回当前元素下标。
2. 当前元素大于目标元素时，即目标元素位置在当前元素的前面，所以当前元素需要右移让出位置，返回的仍然时当前下标。
3. 遍历完整个数组时，说明目标元素比所有的元素都要大，所以返回最后一个元素下标加一，即 `nums.length`。
![搜索插入位置1.gif](https://pic.leetcode-cn.com/f54ef2afceea37dba1dd4105b564b99098168d43cb310b8bf5e91976f307f025-%E6%90%9C%E7%B4%A2%E6%8F%92%E5%85%A5%E4%BD%8D%E7%BD%AE1.gif)

**代码：**
```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int length = nums.length;
        for (int i = 0; i < length; i++){
            if (nums[i] >= target)  return i;
        }

        // 遍历完整个数组仍没有找到符合元素，则目标元素比所有元素都要大
        return length;
    }
}
```
**改进思路：**
如果数组非常大，则最坏的情况需要对整个数组进行比较。避免这种情况，我们可以在遍历前找出目标元素可以能存在的范围。
1. 先取数组中间的元素进行比较。
2. 如果大于目标元素，则范围在 [0,mid]。如果小于目标元素，则范围在 [mid-1, length-1]。
3. 这样，需要遍历的元素就减少了一半了。

**改进代码：**
```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int length = nums.length;
        int left = 0, right = length - 1;
        int mid = (left + right)/2;

        // 判断范围
        if (nums[mid] > target){
            right = mid;
        }else if(nums[mid] < target){
            left = mid + 1;
        }else{
            return mid;
        }

        for (int i = left; i <= right; i++){
            if (nums[i] >= target)  return i;
        }

        // 遍历完整个数组仍没有找到符合元素，则目标元素比所有元素都要大
        return length;
    }
}
```
**二分查找思路：**
其实上面的思路就是二分查找，当我们将范围缩小到只有一个元素的时候，答案自然就出来了。
![搜索插入位置2.gif](https://pic.leetcode-cn.com/3b7e91b0b4864e89d6562f09b7ed3a7c2262898f3b59b86f5422bbb7487edba7-%E6%90%9C%E7%B4%A2%E6%8F%92%E5%85%A5%E4%BD%8D%E7%BD%AE2.gif)

**二分查找代码：**
```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int length = nums.length;
        int left = 0, right = length - 1;
        int mid = (left + right)/2;

        while(left != right){
            if (nums[mid] > target){
                right = mid;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else{
                return mid;
            }
            mid = (left + right)/2;
        }

        if (nums[right] >= target) return right;

        return right + 1;
    }
}
```

博客：www.lxiaocode.com