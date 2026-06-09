### 解题思路

从末尾开始，找到一个decrease，置换一个后面升序序列比它大的里面最小的那个，然后翻转后面的序列

### 代码

```java
class Solution {
    public void nextPermutation(int[] nums) {
       if(nums.length <= 1)return;
    	int i;
    	//找到减少的位置，如7891321，找到这个1，这里i指向3
        for(i = nums.length - 1; i > 0; i--) {
        	if(nums[i] > nums[i-1])break;
        }
        //如果能找到一个降序，则1,2互换位置
        if(i > 0) {
        	for(int j = nums.length - 1; j >= i; j--) {
            	if(nums[j] > nums[i - 1]) {
            		int in = nums[j];
            		nums[j] = nums[i-1];
            		nums[i-1] = in;
            		break;
            	}
            }
        }
		//不管找没找到，i开始到结尾的部分反转
        for(int j = nums.length - 1; j > 0; j--) {
        	if(j <= i)break;
        	int in = nums[j];
        	nums[j] = nums[i];
    		nums[i] = in;
    		i++;
        }
    }
}
```