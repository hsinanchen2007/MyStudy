### 解题思路
使用散列表维护数组中的元素及其对应下标。
对数组中的每一个元素，如果散列表中存在重复元素，且两者下标差不大于k，返回true。否则，如果散列表中存在重复元素但下标不满足要求，更新该键值对，将散列表中存储的该元素的下标更新为当前下标；如果散列表中不含该元素，则向其新增一个键值对，存储该元素的值和其在数组中的下标。
时间复杂度：O(n)。
空间复杂度：O(n)。

### 代码

```java
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer,Integer> map=new HashMap<Integer,Integer>();
        for(int i=0;i<nums.length;i++)
        {
            if(map.containsKey(nums[i]) && i-map.get(nums[i])<=k)
                return true;
            map.put(nums[i],i);
        }
        return false;
    }
}
```