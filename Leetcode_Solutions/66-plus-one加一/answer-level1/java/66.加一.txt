### 解题思路
为了防止溢出和进位,使用栈来操作

### 代码

```java
class Solution {
    public static int[] plusOne(int[] digits){

		int mod=1;//表示进位的数,初始化为1
		
        Stack<Integer> stack = new Stack<>(); 
        for(int i=digits.length-1;i>=0;i--) {
        	if(digits[i]+mod>9) {
        		stack.push(0);
        		mod=1;
        	}
        	else {
        		stack.push(digits[i]+mod);
        		mod=0;
        	}	
        }
        
        //注意：判断进位最后digits遍历完了还存在进位mod
        if(mod==1) stack.push(mod);
        int[] nums = new int[stack.size()];
        
        for(int i=0;i<nums.length;i++) {
        	nums[i]=stack.pop();
        }
       	
		return nums;
	}
}
```