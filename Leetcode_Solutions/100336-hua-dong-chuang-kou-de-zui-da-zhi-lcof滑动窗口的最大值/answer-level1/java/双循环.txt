### 解题思路
先确定c起始位置，再选择最大值

### 代码

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int[] b = new int[nums.length];
		int i,coun = 0,j = 0;
        for(i = 0;i < nums.length;i++) {
			if(i + k <= nums.length) {
				b[i] = nums[i];
				for(j = i;j < i + k;j++) {
					b[i] = Math.max(b[i], nums[j]);
				}
				coun++;
			}
		}
        int[] c = new int[coun];
        for(i = 0; i< coun;i++){
            c[i] = b[i];
        }
        return c;
    }
}
```