### 解题思路
此处撰写解题思路
小白努力呀~

### 代码

```java
class Solution {
    public int findPeakElement(int[] nums) {
        if(nums.length == 1)
			return 0;
		
		//只需要判断当前元素和笑一个元素
		for (int i = 0; i < nums.length - 1; i++) {
			if(nums[i] > nums[i+1]) {
				return i;
			}
		}
		return nums.length - 1;
    }
}
```
![image.png](https://pic.leetcode-cn.com/ec6f259d17108c87fe717649f03927ef85040e0054b81b055f5777db9ecad1e1-image.png)
