### 解题思路
思路是 找出最大值，然后对比最大值和其他值*2的大小
要注意的是索引的保存
### 代码

```java
class Solution {
    public int dominantIndex(int[] nums) {
        int max = nums[0];
        int index = 0;
        for(int i = 1; i < nums.length; i++){
            if(nums[i] > max){
                max = nums[i];
                index = i;
            }
        }

        for(int num:nums) 
            if(max < num * 2 && max != num)
                return -1;
        
        return index;
    }
}
```