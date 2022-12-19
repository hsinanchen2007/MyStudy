### 解题思路
本题以map映射求解，首先把所有的字符串分别添加到指定map集合中去，并依次给予对应的索引，随后对字符串数组进行从大到小排序，并依次从map集合中由键找值，并把该值给到提前创建的字符串数组中作为索引，从大到小依次赋予“Gold Medal”、“Silver Medal”、“Bronze Medal”以及3、4、5...

### 代码

```java
class Solution {
    public String[] findRelativeRanks(int[] nums) {
        if(nums.length==1) {
            return new String[]{"Gold Medal"};
        }
        String[] arr = new String[nums.length];
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        int count = 0;
        for(int i = 0,j=0;i<nums.length && j<nums.length;i++,j++) {
            map.put(nums[i],j);
        }
        Arrays.sort(nums);
        for(int i = 0;i<nums.length/2;i++) {
            int temp = nums[nums.length-i-1];
            nums[nums.length-i-1] = nums[i];
            nums[i] = temp;
        }
        if(nums.length==2) {
            arr[map.get(nums[0])] = "Gold Medal";
            arr[map.get(nums[1])] = "Silver Medal";
            return arr;
        }
        arr[map.get(nums[0])] = "Gold Medal";
        arr[map.get(nums[1])] = "Silver Medal";
        arr[map.get(nums[2])] = "Bronze Medal";
        for(int i = 3;i<nums.length;i++) {
            arr[map.get(nums[i])] = i+1+"";
        }
        
        return arr;
    }
}
```