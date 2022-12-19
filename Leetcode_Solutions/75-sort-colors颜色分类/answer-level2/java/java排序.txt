### 解题思路
此处撰写解题思路
![捕获.PNG](https://pic.leetcode-cn.com/51c78dbad4ab1d2f46978d79aa2a316858d5639393d896c39f4c678de3fc7d0b-%E6%8D%95%E8%8E%B7.PNG)

### 代码

```java
class Solution {
    public void sortColors(int[] nums) {
    	int redindex=0;
    	int blueindex=nums.length-1;
    	for ( int i=0;i<nums.length;i++) {
    		if (nums[i]==0&&i>redindex) {
    			int temp=nums[redindex];
    			nums[redindex]=nums[i];
    			nums[i]=temp;
    			redindex++;
    			i--;
    		}
    		else if (nums[i]==2&&i<blueindex) {
    			int temp=nums[blueindex];
    			nums[blueindex]=nums[i];
    			nums[i]=temp;
    			blueindex--;
    			i--;
    		}
    	}
        for (int i=redindex+1;i<blueindex;i++) {
        	nums[i]=1;
        }
       
    }
}
```