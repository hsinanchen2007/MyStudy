### 解题思路
遍历时候记录每个不为0的数左边总共存在0的个数，然后当前位置减去个数就是要移动的位置。

注意当前数字移动时要将当前位置置为0。

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int count =0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==0){
                count++;
            }else{
                nums[i-count] = nums[i];
                if(count>0){
                nums[i] =0;
                }
            }
        }
    }
}
```