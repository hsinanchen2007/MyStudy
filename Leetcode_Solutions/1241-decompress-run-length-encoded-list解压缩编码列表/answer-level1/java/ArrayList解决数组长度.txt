### 解题思路
该题主要在于数组的长度，所以此处使用一个ArrayList解决


class Solution {
    public int[] decompressRLElist(int[] nums) {
if (nums.length < 2 || nums.length > 100 || nums.length % 2 != 0) {
			return null;
		}
		ArrayList<Integer> res0 = new ArrayList<>();
		for(int i = 0; i < nums.length/2; i++) {
			for(int j = 0; j < nums[2*i]; j++) {
				res0.add(nums[2*i+1]);
			}
		}
		int[] res = new int[res0.size()];
		for(int i = 0; i < res.length; i++) {
			res[i] = res0.get(i);
			System.out.print(res[i]+" ");
		}
		return res;
}