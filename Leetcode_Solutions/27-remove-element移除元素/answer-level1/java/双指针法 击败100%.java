### 解题思路
击败100%

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
         int i = 0;
		 for (int j = 0; j < nums.length; j++) {
			int num = nums[j];
			if(num != val) {
				nums[i] = num;
				i++;
			}
		}
		 return i;
    }
}
```