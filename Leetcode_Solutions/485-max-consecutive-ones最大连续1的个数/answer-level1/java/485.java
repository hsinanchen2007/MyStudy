### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int temp=0; int res = 0;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] == 1)  ++temp;
            else temp = 0;
            res = Math.max(res,temp);
        }
    return res;
    }
}
```