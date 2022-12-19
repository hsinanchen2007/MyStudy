### 解题思路
一开始没审题清楚，原来是排序数组。。Arrays.sort(nums)运行耗时1秒

### 代码

```java
//import java.util.Arrays;

class Solution {
    public int removeDuplicates(int[] nums) {
        //Arrays.sort(nums);
        int length = nums.length;
        if(length < 2)
            return length;
        int i = 0;
        for(int j=i+1;j<length;j++){
            if(nums[j]!=nums[j-1]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
}
```