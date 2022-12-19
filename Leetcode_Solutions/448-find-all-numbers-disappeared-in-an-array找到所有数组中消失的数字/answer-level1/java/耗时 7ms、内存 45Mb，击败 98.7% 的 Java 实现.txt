原理是遍历数组中所有元素，将元素值 - 1对应下标处的值减去数组大小作为标记，最后数组中依然大于0的即为未出现的元素
```Java []
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int elem;
        for (int i = 0; i < nums.length; i++) {
            elem = nums[i] - 1;
            while (elem < 0) {
                elem += nums.length;
            } 
            nums[elem] = nums[elem] - nums.length;  
        }
        List<Integer> ans = new ArrayList<>();
        for (int j = 0; j < nums.length; j++) {
            if(nums[j] > 0) {
                ans.add(j + 1);
            }
        }
        return ans;
    }
}
```