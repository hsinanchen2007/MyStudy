### 解题思路
在循环的同时筛选奇数和偶数分别从新数组的前端和后端赋值

### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        int res[] = new int[nums.length];
		for (int i = 0, k = 0, j = nums.length - 1; i < nums.length; i++) {
			if (nums[i] % 2 == 1) {//奇数则从前端开始赋值
				res[k++] = nums[i];
			} else {//偶数则从后端开始赋值
				res[j--] = nums[i];
			}
		}
		return res;
    }
}
```