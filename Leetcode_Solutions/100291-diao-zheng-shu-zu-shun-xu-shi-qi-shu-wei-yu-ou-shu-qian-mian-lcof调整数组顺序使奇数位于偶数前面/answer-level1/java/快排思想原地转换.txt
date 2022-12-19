### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
  public int[] exchange(int[] nums) {

        int beginIndex = 0;
        int endIndex = nums.length-1;
        while(beginIndex<endIndex){
            while(beginIndex<nums.length && nums[beginIndex] % 2 == 1)
                beginIndex++;
            while(endIndex>=0 && nums[endIndex] % 2 == 0)
                endIndex--;
            if(beginIndex<endIndex)
                swap(nums, beginIndex, endIndex);
        }
        return nums;
    }

    private void swap(int[] nums, int beginIndex, int endIndex) {
        int temp = nums[beginIndex];
        nums[beginIndex] = nums[endIndex];
        nums[endIndex] = temp;
    }
}
```