### 解题思路
我寻思我做的也是O(N)时间复杂度，应该不用优化了吧。。。

### 代码

```java
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int res = 0;
        int tmp = 0;

        for(int i = 0; i < nums.length; i++){
            if(nums[i] == 1){
                tmp = tmp + 1;
            }
            else{
                res = res > tmp ? res : tmp;
                tmp = 0;
            }
        }
        
        return res = res > tmp ? res : tmp;
    }
}
```