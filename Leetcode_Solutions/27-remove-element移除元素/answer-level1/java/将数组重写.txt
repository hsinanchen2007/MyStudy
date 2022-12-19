### 解题思路
此处撰写解题思路
等于val的不要，不等的重新写入。

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int j =0;
        for(int i=0;i<nums.length;i++){
            if(nums[i] != val)
            {
                nums[j] = nums[i];
                j++;
            }
            
        }
        return j;
    }
}
```