### 解题思路
 1、 0和9单独列了出来，
 2、如果最后一位是小于9的数字的话，直接将最后一位加一即可
 3、如果最后一位是9，那么进入循环逐步向前进位，直到不是9的位数，如果每一位都是9的话，则重新创建一个新的比数组多一位的数组，将第一位赋值为1，其余都为0
### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
         if(digits.length==1&&digits[digits.length-1]==0)
	     {
	    	 int[] ans=new int[1];
	    	 ans[0]=1;
	    	 return ans;
	     }
	     if(digits.length==1&&digits[digits.length-1]==9)
	     {
	    	 int[] ans=new int[2];
	    	 ans[0]=1;
	    	 ans[1]=0;
	    	 return ans;
	     }
	     
	     int len=digits.length;
	     if(digits[len-1]<9)
	     {
	    	 digits[len-1]+=1;
	    	 return digits;
	     }
	     digits[len-1]=0;
	     for(int i=len-2;i>0;i--)
	     {
	    	 if(digits[i]<9)
	    	 {
	    		 digits[i]++;
	    	     return digits;
	    	 }
	    	 digits[i]=0;
	     }
	     if(digits[0]<9)
	     {
	    	 digits[0]+=1;
	    	 return digits;
	     }
	     int ans[]=new int[len+1];
	     ans[0]=1;
	     for(int i=1;i<len;i++)
	    	 ans[i]=0;
	     return ans;
    }
}
```