# 思路
先将每个元素及其对应索引所有保存到HashMap中，然后对数组进行排序，最后只需要验证数组的最后一个元素是否是倒数第二个元素的两倍即可。
该方法时间复杂度不理想，但能通过。
```
class Solution {
    public int dominantIndex(int[] nums) {
        // 此处个人觉得应该返回-1，但官方返回0，只有一个元素怎么还是自己的两倍，除非是0
        if (nums.length < 2)    return 0;
        Map<Integer, Integer> map = new HashMap<>();
        int len = nums.length;
        for (int i = 0; i < len; i++)
            map.put(nums[i], i);
        Arrays.sort(nums);
        return (nums[len - 1] / 2 >= nums[len - 2]) ? map.get(nums[len - 1]) : -1;
    }
}
```
