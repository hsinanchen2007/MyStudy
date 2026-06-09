### 解题思路
主要思想是通过交换数组元素，使得数组上的元素在正确的位置上。

### 代码

```java
class Solution {
        public int[] findErrorNums(int[] nums) {
            for(int i = 0;i<nums.length;i++){
                while(nums[i] != i+1 && nums[nums[i] - 1] != nums[i])
                    swap(i,nums,nums[i]-1);
            }

            for(int i = 0;i<nums.length;i++){
                if(nums[i] != i+1){
                    return new int[]{nums[i],i+1};
                }
            }
            return null;
        }
        public void swap(int i ,int[] nums,int j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
```