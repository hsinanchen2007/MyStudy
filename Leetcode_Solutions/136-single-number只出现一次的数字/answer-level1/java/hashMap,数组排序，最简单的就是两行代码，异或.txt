### 解题思路
1.两行代码，不需要任何额外空间，将最开始的数和最后的所有数异或，这样当同时出现两次，那么就相当于没出现，比如4,1,2,1,2  4异或1再异或2那么值就又回到了4
### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        for (int i = 1; i < nums.length; i++) nums[0]=nums[0]^nums[i];
        return nums[0];
    }
}


2.hashMap,出现就删除，没出现就保留，最后剩下一个
Map<Integer, Integer> map = new HashMap();
        for (int num : nums) {
            if (map.containsKey(num)) {
                map.remove(num);
            }
            map.put(num, 1);
        }
        return map.keySet().stream().collect(Collectors.toList()).get(0);


先排序，因为只出现两次，那么两两相比，不等于的那个就是了

if (nums.length == 1) {
            return nums[0];
        }
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 1; i = i + 2) {
            if (nums[i]!=nums[i+1]){
                return nums[i];
            }
        }
return nums[nums.length-1];



```