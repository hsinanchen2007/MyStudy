### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] newArray = new int[]{-1,-1};
        for (int i = 0; i < nums.length; i++){
            for (int j = i+1; j < nums.length; j++){
                if((nums[i] + nums[j]) == target){
                    newArray[0] = i;
                    newArray[1] = j;
                }
            }
        }
        return newArray;
    }
}
```
初学者的暴力解法，哈哈哈哈