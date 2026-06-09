## 思路：

我们应该首先想用暴力求解的话，怎么做？

我们会遍历数组 `a`，然后看除了 `a` 数组中有没有 `target-a` 的数，这样就能保证该数组有两个数和等于 `target`；但是时间复杂度为 $O(n^2)$；

接下来，想一想如何更快一点呢？

对,我们可以借用哈希（Python 叫字典），我们遍历元素的时候，且记录元素的下标，当我们找 `target-a` 时候，只需要在字典找，就可以了，查找字典时间复杂度为 $O(1)$。

所以，

时间复杂度：$O(n)$

空间复杂度：$O(n)$

## 代码：

```Python []
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        n = len(nums)
        lookup = {}
        for i in range(n):
            tmp = target - nums[i]
            if tmp in lookup:
                return [lookup[tmp], i]
            lookup[nums[i]] = i
```
```C++ []
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> lookup;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            int num_to_find = target - nums[i];
            if(lookup.find(num_to_find) != lookup.end()) 
            {
                res.push_back(lookup[num_to_find]);
                res.push_back(i);
                return res ;     
            }
            lookup[nums[i]] = i;
        }
        return res;
        
    }
};
```
```Java []
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++){
            if (map.containsKey(target - nums[i])){
                result[1] = i ;
                result[0] = map.get(target - nums[i]);
                return result;
            }
            map.put(nums[i],i);
        }
        return result;
        
    }
}
```




