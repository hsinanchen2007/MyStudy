### 解题思路
方案1：引入HashSet，存储所有整数，从1daon遍历，找到最小整数，但是不满足空间复杂度要求，[]返回1，[1]返回2，[1,2,3]返回4

### 代码

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for(int i = 0; i < nums.length; i ++){
            if(nums[i] >= 0){
                set.add(nums[i]);
            }
        }
        [0,1,2]返回3，可以在for循环中实现
        for(int i = 1; i <= nums.length; i++){
            if(!set.contains(i)){
                return i;
            }
        }
        return nums.length  + 1;
    }
}
```