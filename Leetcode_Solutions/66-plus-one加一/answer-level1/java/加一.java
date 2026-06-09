### 解题思路
执行用时 :0 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :35 MB, 在所有 java 提交中击败了41.09%的用户

没什么好说的，只是简单的实现了功能，感觉写的很垃圾。判断太多了。  

首先是两种特殊情况，一种是全是9，另外一种后面有很多9，最前面的没有。把这两种特殊情况处理就可以了。在判断是否为9的问题上，参考了其他答案，取余这个操作很好，值得学习。

可以慢慢优化


### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
  		
		//用数字的方法来写是有问题的，以为数量比较大的话，计算量感人
		//只能用逻辑的方法处理
		
		boolean b = false;
		int m = 1;
		
		 for (int i = 0; i < digits.length; i++) {
			 
			 if (digits.length == 1 && digits[i] == 9) {
				 b =true;
			 }
			 
			 
			 if (i == digits.length - 1) {
				break; 
			 }
			 
			
			 
			if ((digits[i] == 9 && digits[i] == digits[i+1])) {
				b= true;	
			}else {
				b= false;
				break;
			}
			 
		 }
		 
		 if (b) {
			 int[] nums = new int[digits.length + 1];
			 nums[0] = 1;
			 
				return nums;
			 
		 } else {
			 
			while (m <= digits.length) {
				if (digits[digits.length-m] != 9) {
					
					digits[digits.length-m] = digits[digits.length-m] + 1;
					
					break;
					
				}else {
					
					
					
					digits[digits.length-m] = 0;
					
				}
				
				m = m + 1;
			} 
			
			// digits[digits.length-m] =  digits[digits.length-m] +1;
		 }
		
		return digits;
    }
}
```