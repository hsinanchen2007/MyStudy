### 解题思路
1 l r
2 判断如果没有换顺序 return nums[0]
3 mid 
4 二段性质是 nums[mid] < nums[0]；这里严格没有=
5 更新l, r

### 代码

```java
class Solution {
    public int findMin(int[] nums) {

        int l = 0, r =nums.length - 1;
        if(nums[r] > nums[l]) return nums[0];
        while(l < r)
        {
            int mid = (l + r) / 2;
            if(nums[mid] < nums[0]) r = mid;
            else l = mid + 1;
        }
        return nums[l];
    }
}
```