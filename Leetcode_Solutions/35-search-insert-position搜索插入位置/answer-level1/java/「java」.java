### 解题思路
![Screenshot_20200331_190423.png](https://pic.leetcode-cn.com/b0a9ca87d6063c249442bdbfc5d877399547e024e326dc6ac5ad7d5476f84033-Screenshot_20200331_190423.png)


分三种情况，target比最小的小；比最大的大；在居中位置；

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        if(target<=nums[0])return 0;
        for( int i=0;i<nums.length;i++)
        {
            if(i>0&&target>nums[i-1]&&target<=nums[i])return i;
        }
        return nums.length;
    }
}
```