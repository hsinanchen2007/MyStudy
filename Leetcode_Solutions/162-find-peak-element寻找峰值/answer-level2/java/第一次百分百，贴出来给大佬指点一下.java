### 解题思路
第一次打败百分百，贴出来给大佬们指导一下
![~5}U`P$}}4E~)DEP)2\[3{}0.png](https://pic.leetcode-cn.com/1a1065c77225c6cfe1bca7fafd008309ee521f289946183f4cf2127ff5e2a698-~5%7DU%60P$%7D%7D4E~\)DEP\)2%5B3%7B%7D0.png)


### 代码

```java
class Solution {
    public int findPeakElement(int[] nums) {
        for(int i=1; i<nums.length; i++){
            if(i == (nums.length-1)){
                if((nums[i] > nums[i-1])){
                    return i;
                }else {
                    return 0;
                }

            }
            if(nums[i]>nums[i+1] &&nums[i] > nums[i-1]){
                return i;
            }
        }
        return 0;
    }
}
```