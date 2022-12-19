### 解题思路
只是计算去掉重复项以后的数组大小，，，，，

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {

        if(nums.length == 0){
            return 0;
        }
        //慢指针
        int i = 0;

        for(int j = 1;j<nums.length;j++){

            if(nums[i] != nums[j]){
                i++;
                
                nums[i] = nums[j];

            }

        }
        return i+1;

    }
}
```