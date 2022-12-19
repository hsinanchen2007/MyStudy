class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> list = new ArrayList<>();
        //遍历数组，将当前位置元素对应数组上的位置的元素置为负数
        for(int i = 0;i <nums.length ;i ++) {
            nums[Math.abs(nums[i])-1] = -Math.abs(nums[Math.abs(nums[i])-1]);
        }
        //再次遍历元素，如果数组位置i上的元素为正数，则i + 1的数字未出现
        for(int i = 0; i < nums.length ;i ++) {
            if(nums[i] > 0)
                list.add(i + 1);
        }
        return list;
    }
}