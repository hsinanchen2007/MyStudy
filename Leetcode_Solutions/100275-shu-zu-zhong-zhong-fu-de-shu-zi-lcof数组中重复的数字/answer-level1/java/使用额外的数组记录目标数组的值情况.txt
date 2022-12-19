### 解题思路
根据题目的暗示，开一个长度跟nums一样的数组，进行结果的记录
过程:对目标数组进行遍历，若记录已有该数字，就返回，没有就在记录数组加1

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        int[] record=new int[nums.length];
        for(int i:nums){
            if(record[i]>0){
                return i;
            }else{
                record[i]++;
            }
        }
        return nums[0];
    }
}
```