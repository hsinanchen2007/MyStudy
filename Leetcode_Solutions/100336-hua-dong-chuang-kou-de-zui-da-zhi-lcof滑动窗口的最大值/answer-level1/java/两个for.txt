### 解题思路
一个for遍历新数组，一个for遍历窗口

### 代码

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int[] newNums = new int[nums.length-k+1];
        if(k == 0 || nums == null) return new int[0];
        if(k > nums.length) return newNums;
        for(int i = 0;i < newNums.length;i++){
            int maxNum = nums[i];
            for(int j = i+1;j < k+i;j++){
                if(nums[j] > maxNum){
                    maxNum = nums[j];
                }
            }   
            newNums[i] = maxNum;
        }
        return newNums;
    }
}
```