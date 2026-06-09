### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findDuplicate(int[] nums) {
        HashSet<Integer> set = new HashSet<>();
        for(int i=0;i<nums.length;i++){
            if(set.contains(nums[i])){
                return nums[i];
            }
            set.add(nums[i]);
        }
        return 0;
        //     Arrays.sort(nums);
        // for (int i = 1; i < nums.length; i++) {
        //     if(nums[i-1] == nums[i]){
        //         return nums[i];
        //     }
        // }
        // return 0;
    }

}
```