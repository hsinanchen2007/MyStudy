class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> result = new ArrayList<>();
        for (int i = 1; i <= nums.length; i++) {
            result.add(i);
        }
        Arrays.stream(nums).forEach(x -> result.remove((Integer) x));
        return result;
    }
}