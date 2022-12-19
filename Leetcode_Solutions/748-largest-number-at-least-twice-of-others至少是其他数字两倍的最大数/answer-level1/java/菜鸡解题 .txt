### 解题思路
先找到最大值，然后遍历数组，记录最大值的索引

### 代码

```java
class Solution {
    public int dominantIndex(int[] nums) {
        int[] arrNums = nums.clone();
        Arrays.sort(arrNums);
        int index = 0;
        int maxNum = arrNums[arrNums.length-1];
        for(int i = 0;i < nums.length;i++){
            if(nums[i] == maxNum){
                index = i;
            }
            if(maxNum < 2*nums[i] && nums[i] != maxNum){
                return -1;
            }
        }
        return index;
    }
}
```