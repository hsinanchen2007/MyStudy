### 解题思路
1, 先排序，
2，排序好的数组和原数组比较，找出开始不同的位置和最后不同的位置

### 代码

```java
class Solution {
   public int findUnsortedSubarray(int[] nums) {
        int[] sortArr = new int[nums.length];
        sortArr = Arrays.copyOf(nums, nums.length);
        Arrays.sort(sortArr);
        int beginDiffIndex = 0;
        int endDiffIndex = 0;
        for (int i = 0; i< nums.length; ++i) {
            if (nums[i] != sortArr[i]){
                beginDiffIndex = i;
                break;
            }
        }

        for (int i = 0; i< nums.length; ++i) {
            if (nums[i] != sortArr[i]) {
                endDiffIndex = i;
            }
        }

        if (endDiffIndex == beginDiffIndex){
            return 0;
        }else {
            return endDiffIndex-beginDiffIndex+1;
        }
    }
}
```