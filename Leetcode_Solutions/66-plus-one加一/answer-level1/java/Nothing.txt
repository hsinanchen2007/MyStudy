### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
      int len=digits.length;
       digits[len-1]=digits[len-1]+1;
       digits= replace(digits,len-1);
       return digits;
    }

	private int[] replace(int[] digits, int i) {
		if(i>=0&&digits[i]<10){
			return digits;
		}else if(i>0&&digits[i]==10){
			digits[i]=0;
			digits[i-1]=digits[i-1]+1;
			digits=replace(digits,i-1);
		   return digits;
		}else if(i==0&&digits[0]==10){
			int n=digits.length;
			int[] a=new int[n+1];
			a[0]=1;
			a[1]=0;
			for(int j=2;j<n+1;j++){
				a[j]=digits[j-1];
			}
			return a;
		}
		return digits;
	}
} 
```