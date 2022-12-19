### 解题思路
暴力解法，便利数组，把元素放入 容器中，如果有重复的元素则直接返回，
时间复杂度 O(n)

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        List<Integer> list = new ArrayList<>();    
        for (int i=0; i<nums.length; i++){
            if (list.contains(nums[i]))
                return nums[i];
            else
                list.add(nums[i]);
        }
        //如果没有重复的数字，返回-1
        return -1;
    }
}
```