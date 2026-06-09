### 解题思路

还是使用 HashSet，不过题目中是假设一定有重复元素，但是在写代码的时候，总是要考虑没有重复元素的情况，这时候的返回值就尴尬了


### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        HashSet<Integer> set = new HashSet<Integer>();

        for(int i = 0;i<nums.length;i++){
            if(!set.add(nums[i])){
                return nums[i];
            }

        }

        return 0;

    }
}
```