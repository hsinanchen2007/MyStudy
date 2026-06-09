思路：将数组从小到大排序，每个数的索引值 = 小于该数的个数，考虑会有重复数字，我们只需要保存出现该数的第一个索引值即可。

```
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] bak = nums.clone();
        Arrays.sort(bak);
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < bak.length; i++) {
            if(!map.containsKey(bak[i]))
                map.put(bak[i], i);
        }
        for (int i = 0; i < nums.length; i++)
            nums[i] = map.get(nums[i]);
        return nums;
    }
}
```
