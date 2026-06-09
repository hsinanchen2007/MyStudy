```
class Solution {
    public boolean find132pattern(int[] nums) {
        if (nums == null || nums.length == 0) return false;
        int leftMin = nums[0];
		int right = 0;
		for (int i = 1; i < nums.length - 1; i++) {
			// 獲取當中的數字
			int num2 = nums[i];
                        // 左邊始終獲取最小值
			if (leftMin > nums[i-1]) leftMin = nums[i-1];
			if (leftMin > num2) continue;
                        // 右邊遍歷，得到符合條件的就返回true
			for (int j = i + 1; j < nums.length; j++) {
				right = nums[j];
				if (right < num2 && right > leftMin) return true;
			}
		}
		return false;
    }
}
```