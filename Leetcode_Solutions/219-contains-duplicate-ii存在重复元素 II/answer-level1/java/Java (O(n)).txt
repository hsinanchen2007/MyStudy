### 解题思路
利用HashMap存储每个num[i]的最新位置。

### 代码

```java
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap();
        for (int j = 0; j < nums.length; j++){
            // 查看当前是否有对应的num[i]
            if (map.containsKey(nums[j])){
                if (j - map.get(nums[j]) <= k){
                    return true;
                }
            } 
            // 更新当前nums[j]为nums[i]，因为想找个绝对值最大为k，因此距离越近越好
            map.put(nums[j], j);
        }
        return false;
    }
}
```