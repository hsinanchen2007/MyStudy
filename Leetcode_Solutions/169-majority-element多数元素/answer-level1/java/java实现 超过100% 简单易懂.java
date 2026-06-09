### 解题思路
由于肯定有一个数的个数超过n/2（称为众数），所以我们做这样一个假设，最坏情况下，每一个众数和任意一个普通的数相抵消，最终剩余的肯定是众数，如果普通的数和普通的数相抵消，最终剩余也肯定是众数

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        int s = nums[0];
        //num记录目前与s相同的个数
        int num = 1;
        for(int i=1; i<nums.length; i++){
            if(nums[i] == s){
                num++;
            }else{
                num--;
            }
            //如果num小于0，说明之前的数刚好抵消了（最坏的情况就是一个众数和一个普通的数），就取现在的数作为s，并将num重置为0，从下一阶段继续找
            if(num < 0){
                s = nums[i];
                num = 0;
            }
        }
        return s;
    }
}
```