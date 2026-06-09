### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {

        int max = 0;
        int num=0;
        for (int i = 0; i < nums.length; i++) {
            if(nums[i]==0){
                num=0;
            }else {
                num++;
            }
            max=Math.max(num,max);
        }

        return max;
    }
}
```