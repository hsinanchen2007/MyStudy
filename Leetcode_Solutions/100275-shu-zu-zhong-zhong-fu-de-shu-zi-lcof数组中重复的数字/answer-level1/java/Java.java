### 解题思路
先调用Arrays类的sort方法排序，依次比较数组中相邻的两个数；如果相等就直接返回，循环结束没有相等的就返回-1。

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        Arrays.sort(nums);
        for(int i = 0; i < nums.length - 1; i++){
            if(nums[i] == nums[i+1]){
                return nums[i];
            }
        }
        return -1;
    }
}
```