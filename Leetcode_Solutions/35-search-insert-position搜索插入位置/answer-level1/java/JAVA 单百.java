### 解题思路
遍历数组，匹配到相等的直接返回下标，遇到比target大的也直接返回下标，否则返回数组长度（说明target比任何一个数都要大，插入末尾）

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        for(int i=0;i<nums.length;i++){
            if(nums[i]==target){
                return i;
            }else if(nums[i]>target){
                return i;
            }
        }
        return nums.length;
    }
}
```