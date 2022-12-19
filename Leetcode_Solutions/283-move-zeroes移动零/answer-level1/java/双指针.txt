### 解题思路
i和j两个指针
0-j是不为0的数，先将不为0的j个数全部移动到数组的左边；
剩下的数全部令=0即可。

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        if(nums == null)
            return ;
        int j = 0;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] != 0){
                nums[j++] = nums[i];
            }
        }
        for(int i = j; i < nums.length; i++){
            nums[i] = 0;
        }
        return ;
    }
}
```