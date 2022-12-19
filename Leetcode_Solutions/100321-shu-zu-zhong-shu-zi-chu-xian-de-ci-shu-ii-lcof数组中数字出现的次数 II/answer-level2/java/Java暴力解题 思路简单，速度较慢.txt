### 解题思路
找到次数为1那个便可以输出

### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        int i,j;
        int[] arr = new int[nums.length];
        for(i=0;i<nums.length;i++){
            for(j=0;j<nums.length;j++){
                if(nums[i] == nums[j]){
                    arr[i]++;
                }
            }
        }
        for(i=0;i<arr.length;i++){
            if(arr[i] == 1)
            return nums[i];
        }
        return 0;
    }
}
```