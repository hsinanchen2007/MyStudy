### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int i = Arrays.binarySearch(nums, target);
        if(i >= 0){
            int tmp = i;
            while(i >= 0){
                if(nums[i] == target ){
                    i--;
                }else {
                    break;
                }
            }
            i++;
            while (tmp <= nums.length - 1){
                if(nums[tmp] == target){
                    tmp++;
                }else {
                    break;
                }
            }
            tmp--;
            return new int[] {i,tmp};
        }
        return new int[]{-1,-1};
    }
}
```