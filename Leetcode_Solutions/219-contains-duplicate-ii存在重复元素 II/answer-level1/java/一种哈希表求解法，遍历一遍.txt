变量一遍，通过哈希表来存储存最近一次出现的数字的索引，当再次出现相同数字时判断，再更新哈希表。
```
public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashMap<Integer,Integer> res = new HashMap<>();
        int n = nums.length;
        for (int i = 0;i < n;i++){
            if (res.containsKey(nums[i])){
                if (i - res.get(nums[i]) <= k)
                    return true;
            }
            res.put(nums[i],i);
        }
        return false;
    }
```
