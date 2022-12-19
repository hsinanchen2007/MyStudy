### 解题思路
0.一般的思路是去统计数字出现的次数，次数大于数组长度的一半的数字就是答案，且一定存在
1.摩尔投票法：只适用于找一个出现次数大于一半的数字
1.1 记录一个数字出现，则count++
1.2 如果一个数字和这个数字不一样，则两个数字“抵消”，count--
1.3 当count为0时，就需要修改记录的数字
1.4 最后记录的数字就是出现最多的数字

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
    	int mirror = nums[0];
    	int count = 1;
    	for (int i = 1; i < nums.length; i++) {
    		if (count == 0) {
				mirror = nums[i];
				count++;
			} else {
				if (mirror != nums[i]) {
					count--;
				} else {
					count++;
				}
			}
		}
    	return mirror;
    }
}
```