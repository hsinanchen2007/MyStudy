### 解题思路

第一反应是和快排相似

双指针，一个指针 i 指头，一个 j 指尾

当 尾部的元素为偶数时，j 就一直往前移动，直到不为偶数为止

同理，当头部的元素为奇数时，就一直往后移动，直到不为奇数为止

当然，上述两个步骤要保证 i < j

一直到 i == j 的时候，奇数偶数就分明了

### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        if(nums == null){
            return nums;
        }

        int arrLen = nums.length;

        if(arrLen == 0 || arrLen == 1){
            return nums;
        }

        int i = 0;
        int j = arrLen - 1;

        while(i < j){
            while(i < j && nums[j] % 2 == 0){
                j --;
            }

            while (i < j && nums[i] % 2 != 0){
                i ++;
            }

            if(i < j){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }

        }

        return nums;
    }
}
```