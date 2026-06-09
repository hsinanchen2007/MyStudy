![image.png](https://pic.leetcode-cn.com/8daf8b95b8264c990022b2fef6be77459399a28b79e64aaf8c97c135dc8cc372-image.png)

### 解题思路
这一题比较简单
直接循环该数组，比较目标值大小就可以找到位置
为了让判断更简单一些，在开头就直接判断了目标值与最大值最小值，或者数列为空的情况，直接return结果
### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int len=nums.length;
        if(target<nums[0]||len==0){
            return 0;
        }
        else if(target>nums[len-1]){
            return len;
        }
        int i=0;
        while(i<len){
            if(target==nums[i])
                return i;
            else if(nums[i]<target&&target<nums[i+1])
                return i+1;
            i++;
        }
        return i;
    }
}
```