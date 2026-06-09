### 解题思路
大概就是设置一个数组记录缺失位，然后遍历该数组输出缺失位

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        
        int[] flag = new int[nums.length + 1];
		for (int i = 0; i < nums.length; i++) {
			flag[nums[i]] = 1;
 		}
		for(int i = 0; i < flag.length;i++) {
			if(flag[i] == 0)
				return i;
		}
		return 0;
    }
}
```