### 解题思路


### 代码

```java
class Solution {
    //有一个1~n的数组合成n+1的数组。所以必出现一个重复，重复的数字也并不是重复一次。找出重复的数。
    public int findDuplicate(int[] nums) {
        Arrays.sort(nums);
        int i;
        for(i = 0; i < nums.length - 2; i++){
            if(nums[i] == nums[i+1])
                break;
        }
        return nums[i];
    }
}
```