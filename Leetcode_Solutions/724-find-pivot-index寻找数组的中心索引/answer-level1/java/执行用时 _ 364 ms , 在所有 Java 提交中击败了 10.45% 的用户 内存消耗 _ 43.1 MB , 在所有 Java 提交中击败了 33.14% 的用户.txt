### 解题思路
思路比较清晰，任意一个数，左边之和等于右边之和，我们采用逆向思维，如果计算了左边之和，直接总和减去左边再减去该中间值（假设是中间值）即可，但是两个例外必须考虑，最左的元素，其左边之和为0，最右的元素，其右边之和为0，考虑到优先以最左边的中间值为准，我们把最左边元素可能是中间值放在第一种情况，而最右边放在这最后一种情况下。代码如下：

### 代码

```java
class Solution {
    public int pivotIndex(int[] nums) {
        if(nums.length<=2) {
            return -1;
        }
        int SUM = 0;
        for(int i = 0;i<nums.length;i++) {
            SUM+=nums[i];
        }

         if(SUM-nums[0]==0) {
            return 0;
        }
        
        for(int i = 1;i<nums.length-1;i++) {
            int sum = 0;
            for(int j = 0;j<i;j++) {
                sum+=nums[j];
            }
            if(sum==SUM-sum-nums[i]) {
                    return i;
            }
        }

       
        if(SUM-nums[nums.length-1]==0) {
            return nums.length-1;
        }


        return -1;
    }
}
```