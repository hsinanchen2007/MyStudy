### 解题思路
先计算长度，再填充

### 代码

```java
class Solution {
    public int[] decompressRLElist(int[] nums) {
        int len = 0;
		//计算长度
		for(int i=0;i<nums.length;i++) {
			len+=nums[i];
			i++;
		}
		
		//填充
		int[] rst = new int[len];
		int idx = 0;
		for(int i=0;i<nums.length;i++) {
			for(int j=0;j<nums[i];j++) {
				rst[idx++] = nums[i+1];
			}
			i++;
		}
		
		return rst;
    }
}
```