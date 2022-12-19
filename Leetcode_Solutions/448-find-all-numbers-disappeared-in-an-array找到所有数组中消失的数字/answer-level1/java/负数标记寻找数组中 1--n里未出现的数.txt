### 解题思路

### 代码

```java
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> res = new ArrayList<>();
        /*
          用数组中的元素 - 1当作下标
          如果对应下标中的元素为正则赋值为负数
          一遍完成后，数组元素大于0的位置的下标加1即是没出现过的数
        */
        for(int num : nums)
            nums[Math.abs(num) - 1] = -Math.abs(nums[Math.abs(num) - 1]);
        for(int i = 0; i < nums.length; i++){
            if(nums[i] > 0)
                res.add(i + 1);
        }
        return res;
        
    }
}
```