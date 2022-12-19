### 解题思路
统计元素出现的个数，然后设置判断条件，再次设置对应元素对应个数的值

### 代码

```java
class Solution {
    public void sortColors(int[] nums) {
        int len = nums.length;
        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i < len; i++){
            if(nums[i] == 1){
                count1++;
            }
            if(nums[i] == 2){
                count2++;
            }
        }
        int count0 = len - count1 - count2;
        if(count0 > 0){
            for(int i = 0; i < count0; i++){
                nums[i] = 0;
            }
        }
        if(count1 > 0){
            for(int i = count0; i < count0 + count1; i++){
                nums[i] = 1;
            }
        }
        if(count2 > 0){
            for(int i = count0 + count1; i < len; i++){
                nums[i] = 2;
            }
        }
    }
}
```