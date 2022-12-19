### 解题思路
这个方法远远比建立数组遍历两次找最多值要简单的多

### 代码

```java
class Solution {
	public int majorityElement(int[] nums) {
		int res=nums[0];
		int num=0;
		for(int i : nums) {
			if(i==res) num++;
			else {
				num--;
				if(num<0) {
					num=0;
					res=i;
				}
			}
		}
		return res;
    }
}
```