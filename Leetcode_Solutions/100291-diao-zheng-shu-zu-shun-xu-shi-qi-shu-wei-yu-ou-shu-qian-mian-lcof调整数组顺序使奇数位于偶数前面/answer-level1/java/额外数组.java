### 解题思路
我不明白，我用了额外数组，消耗内存击败100%。时间复杂度O(n)，却只击败55%。==

### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        if(nums.length == 0)
            return new int[0];
        int[] res = new int[nums.length];
        int index = 0;
        
        for(int i = 0; i < nums.length; i++){
            if(nums[i] % 2 == 1){
                res[index] = nums[i];
                index += 1;
            }
        }
        for(int i = 0; i < nums.length; i++){
            if(nums[i] % 2 == 0){
                res[index] = nums[i];
                index += 1;
            }
        }
        return res;
    }
}
```