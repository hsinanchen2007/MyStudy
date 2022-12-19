### 解题思路
![image.png](https://pic.leetcode-cn.com/8f0d0db0c3000804bafb6e69278d62fd611ac77a8e0498284ae642f5bd512284-image.png)


### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
      if(nums.length == 0)
        return -1;
      int l = 0, r = nums.length - 1;
      int mid = 0;
      while(l <= r){
        mid = l + r >>> 1;
        if(nums[mid] > target)
          r = mid - 1;
        else if(nums[mid] < target)
          l = mid + 1;
        else
          return mid;
      }
      return -1;
    }
}
```