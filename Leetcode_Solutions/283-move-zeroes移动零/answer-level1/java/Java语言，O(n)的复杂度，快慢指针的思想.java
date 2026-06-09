### 解题思路
主要是快慢指针的思想，找到非零的元素就将其交换到慢指针的索引处，并将零元素交换过去。这样做能够节省补零的操作。
#### 描述：
j指针遇到零就会停下来，然后等待i指针找到非零元素来和它进行交换。

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int j = 0;
        for(int i = 0;i < nums.length;i++){
            if(nums[i] != 0){
                int tep = nums[i];
                nums[i] = nums[j];
                nums[j] = tep;
                j++;
            }

        }

    }
}
```