### 解题思路
先求出整个数组非0的乘积total，由于0是特殊情况，当数组有一个0时，非0位置对应值都为0，0位置对应值为total.
当数组有有两个以上的0时，所有位置都应值都为0

### 代码

```java
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int total = 1;
		int num_count = 0;
		for (int num : nums) {
			if (num == 0) {
				num_count++;
				continue;
			}
			total *= num;
		}
		for (int i = 0; i < nums.length; i++) {
			if (num_count > 0) {
				if (num_count == 1 && nums[i] == 0) {
					nums[i] = total;
				}else {
					nums[i] = 0;
				}
				continue;
			}
			nums[i] = total / nums[i];
		}
		return nums;
    }
}
```