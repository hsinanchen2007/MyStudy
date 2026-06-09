### 解题思路
1. 先定义一个长度为2的int型数组，用于存放最终结果；
2. 第一层循环，从数组第一个元素开始到最后一个元素；
3. 第二层循环，从第一层循环的后一个元素到最后一个元素；
4. 若第一层和第二层循环两元素之和等于target，则返回两层的下标给第1步中所定义的数组；
5. 返回最终结果数组；
### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] resultArr = new int[2];
		for (int i =0; i < nums.length; i++){
			for (int j = i + 1; j < nums.length; j++){
				if ((nums[i] + nums[j]) == target){
					resultArr = new int[]{i, j};
				}
			}
		}
		return resultArr;
    }
}
```