### 解题思路
首先时算出结果的数组长度，然后已两个长度单位遍历数组，在每次遍历过程中，将num[i+1]个值赋值num[i]次即可,用时1ms，占用内存38.1
### 代码

```java
import java.util.*;
class Solution {
    public int[] decompressRLElist(int[] nums) {
        int sum=0;
        for(int i=0;i<nums.length;i+=2){
            sum=sum+nums[i];
        }
        int ans[]=new int[sum];
        int a=0,b;
        for (int i = 0; i < nums.length; i += 2) {
			b =nums[i];
			while (b>0) {
				ans[a++] = nums[i + 1];
                b--;
			}
		}
        return ans;
    }
}
```