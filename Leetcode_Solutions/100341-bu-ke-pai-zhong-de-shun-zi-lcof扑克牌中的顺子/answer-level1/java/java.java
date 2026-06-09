### 解题思路
1. 若是非零的数字中包含重复数字，则一定不是顺子。
2. 若是非零的数字中的最大值与最小值之差大于4，则一定不是顺子。否则一定是顺子。

### 代码

```java
class Solution {
    public boolean isStraight(int[] nums) {
        if(containsDupNumExcludeZero(nums)) return false;
        int len = nums.length;
        int min = 0,max = 0;
        boolean flag = false;
        for(int i = 0;i < len;i++){
            if(nums[i]==0) continue;// find first non-zero number
            if(!flag){
                min = nums[i] ;max = nums[i];//set the first non-zero number to be min and max
                flag = true;
                continue;
            } 
            min = min < nums[i]?min:nums[i];
            max = max > nums[i]?max:nums[i];
        }
        boolean ans = (max - min) <= 4?true:false;
        return ans;
    }
    //非零的数字中是否包含重复数字
    boolean containsDupNumExcludeZero(int[] nums){
        List<Integer> list = new ArrayList<>();
        for(int i : nums){
            if(list.contains(i)) return true;
            if(i!=0) list.add(i);
        }
        return false;
    }
}
```