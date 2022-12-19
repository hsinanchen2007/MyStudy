
class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        int[] target = new int[nums.length];
		for(int i = 0;i<index.length-1;i++) {
			int temp = 0;
			for(int j = i+1;j<index.length;j++) {
				if(temp+index[i]>=index[j]) {
					temp++;
				}
			}
			target[index[i]+temp] = nums[i];
		}
		target[index[index.length-1]] = nums[nums.length-1];
		return target;
    }
}

