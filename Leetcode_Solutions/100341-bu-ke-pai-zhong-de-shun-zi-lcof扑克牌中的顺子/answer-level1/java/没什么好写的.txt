### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isStraight(int[] nums) {
        int min = Integer.MAX_VALUE ;
        int max = Integer.MIN_VALUE ;
        HashSet<Integer> set = new HashSet<Integer>() ;

        for (int i=0 ;i < nums.length ; i++) {
            if (nums[i] != 0){
                min = Math.min(min,nums[i]) ;
                if (set.contains(nums[i]))
                    return false ;
                set.add(nums[i]) ;
            }
            max = Math.max(max,nums[i]) ;
        }
        if (max - min + 1 <= nums.length)
            return true ;
        else
            return false ;

    }
}
```