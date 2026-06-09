### 解题思路
1、先将数组排序
2、判断第一个和最后一个和其后面或前面是否相等，不相等直接返回
3、循环判断剩下的，是否和其前面一个、后面一个相等，不相等直接返回
### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        Arrays.sort(nums);
        int singleNum = 0;
        if (nums[0] != nums[1]){
            return nums[0];
        }
        if (nums[nums.length-1] != nums[nums.length-2]){
            return nums[nums.length-1];
        }
        for (int i = 1; i < nums.length-1; i++){
            if (nums[i] != nums[i-1] && nums[i] != nums[i+1]){
                singleNum = nums[i];
                break;
            }
        }
        return singleNum;
    }
}
```