### 解题思路
题中有说明，有序数组 和 不要求前面满足去重后数组的尾部，所以可复用原有数组

### 代码

```java
class Solution {
    //第一种解法 通过map判断是否重复
    public  int removeDuplicates(int[] nums) {
        int count = 0;
        Map<Integer,Boolean> map = new HashMap<Integer, Boolean>();
        for (int i = 0; i < nums.length; i++) {
            if(!map.containsKey(nums[i])){
                map.put(nums[i],true);
                nums[count] = nums[i];
                count++;
            }
        }
        return count;
    }
    //第二种解法  数组有序，判断相邻是否相等
    public int removeDuplicates(int[] nums) {
        if(nums.length == 0 || nums.length == 1){
            return nums.length;
        }
        int count = 1;
        for (int i = 1; i < nums.length; i++) {
            if(nums[i] != nums[i-1]){
              nums[count] = nums[i];
              count++;
            }
        }
        return count;
    }
}
```