### 解题思路
  找到空缺的就返回，找不到就在最后一个数的基础上加1

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length,i;
        for(i=0;i<n;i++){
            if(nums[i] != i){
                return i;
            }
        }
        return nums[i-1]+1;
    }
}
```