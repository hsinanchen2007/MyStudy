![2020012801.PNG](https://pic.leetcode-cn.com/03a77058db8ba72f173aedab57e2fa849b7cfd034a23dd5e27aa80f73c3369d8-2020012801.PNG)
### 解题思路
声明左指针left记录第一个非较小值数字的位置;
声明右指针right记录第一个非较大值数字的位置;
(较小值可能为0或1;较大值可能为1或2)
声明遍历指针i;
在遍历过程中,当nums[i]为较小值时,与nums[left]交换,left++;
当nums[i]为较大值时,与nums[right]交换,right++;
循环终止条件(i<=right)
### 代码

```java
class Solution {
    public void sortColors(int[] nums) {
    	int left = 0;
    	int right = nums.length-1;
    	int i = 0;
    	int temp=0;
    	while(i<=right) {
    		if(nums[i]==1) {
    			i++;
    		}else if(nums[i]==0) {
    			if(left==i) {
    				left++;
    				i++;
    			}else {
        			temp = nums[i];
        			nums[i] = nums[left];
        			nums[left] = temp;
        			left++;
    			}
    		}else if(nums[i]==2) {
    			temp = nums[i];
    			nums[i] = nums[right];
    			nums[right] = temp;
    			right--;
    		}
    	}
    }
}
```