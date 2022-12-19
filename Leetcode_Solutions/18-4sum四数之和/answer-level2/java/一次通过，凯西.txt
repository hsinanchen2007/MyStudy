### 解题思路
应该是参考第十六题最接近的三数之和
双指针low 、high 可以代替for循环遍历最里层的两个数字，

### 代码

```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        //首先排好序
		Arrays.sort(nums);
		
		List<List<Integer>> result = new LinkedList<List<Integer>>();
		
		for (int i = 0; i < nums.length - 3; i++) {
			//去重
			if(i == 0 || (i > 0 && nums[i] != nums[i-1])) {
				for(int j = i+1;j < nums.length - 2;j ++) {
					if(j == i+1 || (j > i+1 && nums[j] != nums[j-1])) {
						int low = j + 1,high = nums.length - 1;
						while(low < high) {
							int count = target - nums[i] - nums[j];
							if(nums[low] + nums[high] == count) {
								result.add(Arrays.asList(nums[i], nums[j], nums[low], nums[high]));
								while(low < high && (nums[low] == nums[low + 1])) low ++;
								while(low < high && (nums[high] == nums[high - 1])) high --;
								
								low ++;
								high --;
							}else if(nums[low] + nums[high] > count) high --;
							else low ++;
						}
						
					}
				}
			}
			
		}
		
		return result;
    }
}
```
![image.png](https://pic.leetcode-cn.com/b9e23c5e79c5383e37f3140699599bfe870fa6fe65d0dabe9f012692729e8de7-image.png)
