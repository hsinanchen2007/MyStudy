### 解题思路
上面很多大神已经给出了很详细的步骤，这里写一下自己的感想吧：
1、一开始头脑风暴想到过对数组排序，下意识的以为要自己写一个快速排序来实现数组的排序。这样的话，觉得应该不会出这样的题。没想到可以直接Arrays.sort()来辅助排序。受教了！
2、在排序好的数组的基础上，需要明白循环的具体逻辑，再开始写代码。不然想不清楚，肯定写不对。
3、胆大心细，考虑周全。很佩服15分钟视频那哥们，虽然是循环，里面包含很多细节。当自己写的时候，还是对循环逻辑研究了一会，才AC。细微处能力分高下。大佬就是大佬，需要多学习。
ps：头脑风暴否定先排序之后，想到的其他方案，很满发，还不能AC。看来一来是的算法思路很重要。
以此记录解题的思想过程。Come on!

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
		if(nums.length < 3) {
			return result;
		}
		// 排序
		Arrays.sort(nums);
		for (int i = 0; i < nums.length; i++) {
			// 去重
			if(i > 0 && nums[i] == nums[i - 1]) 
				continue;
			int target = -nums[i];
			int left = i + 1;
			int right = nums.length - 1;
			while(left < right) {
				if(target == nums[left] + nums[right]) {
					List<Integer> list = new ArrayList<>();
					list.add(nums[i]);
					list.add(nums[left]);
					list.add(nums[right]);
					result.add(list);
					left++;right--;
					while(left < nums.length && nums[left] == nums[left - 1] ) 
						left++;
					while(right > left && nums[right] == nums[right + 1]) 
						right--;
					
				}else if(target < nums[left] + nums[right]) {
					right--;
				}else {
					left++;
				}
			}
		}
		return result;
    }
}
```