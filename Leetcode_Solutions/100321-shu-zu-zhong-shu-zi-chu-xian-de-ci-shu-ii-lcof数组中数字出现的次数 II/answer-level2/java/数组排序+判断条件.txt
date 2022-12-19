### 解题思路
//1. 先判断一个特殊的情况： 长度为0，返回nums[0]
//2. 判断边界条件，第一个不等于第二个，或者倒数第一个不等于倒数第二个,返回第一个或最后一个
//3. 如果在中间的话，判断是否前后相等，都不相等，则返回这个nums[i]

### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        Arrays.sort(nums);
        if(nums.length==1) return nums[0];

        if(nums[0]!=nums[1]) return nums[0];
        if(nums[nums.length-1]!=nums[nums.length-2]) return nums[nums.length-1];

        for(int i=1;i<nums.length-1;i++){
            if(nums[i]!=nums[i+1]&&nums[i-1]!=nums[i]){
                return nums[i];
            }
        }
        return 0;
    }
}
//1. 先判断一个特殊的情况： 长度为0，返回nums[0]
//2. 判断边界条件，第一个不等于第二个，或者倒数第一个不等于倒数第二个,返回第一个或最后一个
//3. 如果在中间的话，判断是否前后相等，都不相等，则返回这个nums[i]
```