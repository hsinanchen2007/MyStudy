解题思路：使用HashMap来存储元素和元素对应的索引。遍历数组，如果HashMap中包含当前元素，计算重复元素之间的距离，并更新该元素在HashMap里面的索引；如果不存在，添加当前元素。

遍历结束，目的是寻找重复元素之间的最小距离，再与k比较。看了他人的解题思路，用长度为k的滑动窗口在空间复杂度上更好，但是不是那么容易想到，所以贴上自己的代码供参考。
```java []
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        int minDistance = Integer.MAX_VALUE;
        Map<Integer, Integer> numMap = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (numMap.containsKey(nums[i])){
                int prevIndex = numMap.get(nums[i]);
                if (i-prevIndex < minDistance){
                    minDistance = i - prevIndex;
                }
            }
            numMap.put(nums[i],i);
        }
        if (minDistance <= k){
            return true;
        }else {
            return false;
        }
    }
}
```

