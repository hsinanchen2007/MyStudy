### 解题思路
考察位运算；两个相同的数字进行异或为0.

### 代码

```java
class Solution {
    public int[] singleNumbers(int[] nums) {
        if (nums == null || nums.length <= 1) {
        	return new int[2];
        }
        int val = nums[0];
        for (int i = 1; i < nums.length; i++) {
        	val ^= nums[i];
        }

        // find the 1 在二进制中对应的位置
        int index = 0;
        while ((val & 1) == 0 && index < Integer.SIZE) {
        	val = val >> 1;
        	index++;
        }

        int num1 = 0;
        int num2 = 0;
        for (int i = 0; i < nums.length; i++) {
            // 针对每一个变量判断上一步获取到的index位置是否一致进行分组
        	if (isSame(nums[i], index)) {
        		num1 ^= nums[i];
        	} else {
        		num2 ^= nums[i];
        	}
        }

        return new int[] {num1, num2};
    }

    public boolean isSame(int val, int index) {
    	val = val >> index;
    	if ((val & 1) == 0) {
    		return false;
    	}
    	return true;
    }
}
```