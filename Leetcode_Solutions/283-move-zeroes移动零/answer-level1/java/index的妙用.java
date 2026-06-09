### 解题思路
见注释

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int index = 0;                   //index记录下标
        for(int num:nums){                    
            if(num!=0){
                nums[index++]=num;       //不为0的数依次从前排
            }
        }
        while(index<nums.length){       //index后面循环补0
            nums[index++] = 0;
        }

    }
}
```