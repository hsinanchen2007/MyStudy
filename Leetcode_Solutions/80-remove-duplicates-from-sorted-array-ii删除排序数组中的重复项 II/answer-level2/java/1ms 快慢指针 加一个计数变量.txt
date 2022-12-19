### 解题思路
当数字重复时看计数变量是否为1
不为1时跳过
### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int slow=0;
		int count =0;
		for(int fast=1;fast<nums.length;fast++) {
			if(nums[fast]==nums[slow]) {//数值重复
				count++;//计数++
				if(count==1) {//计数等于1时添加 否则跳过
					slow++;
					nums[slow]=nums[fast];
				}
			}else {
				slow++;
				nums[slow]=nums[fast];
				count=0;
			}
		}
		return slow+1;
    }
}
```