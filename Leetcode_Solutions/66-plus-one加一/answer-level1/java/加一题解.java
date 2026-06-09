### 解题思路
我的思路可能有些麻烦
1、先判断是否全为9，如果数组中全为9，就需要新数组个数加一，除了索引为0的元素为1，其他元素全为0
2、在判断是否以9结尾
   如果不是以9结尾，只需使结尾元素加1
   如果以9结尾，需要使结尾变0，前面的元素加1，
   这时要判断前面的元素是否是9，如果不会死就9，前面的元素加1，其他元素不变
   如果是9，则一直判断到不为9 为止
  

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
      int n=digits.length-1;
		int m=0;
		int a[]=null;
		for(int i=0;i<digits.length;i++) {
			if(digits[i]%9!=0) {
				m=1;
			}
		}
		digits[n]=digits[n]+1;
		if(digits[n]>9) {
			if(m==0) {
				a=new int[n+2];
				for(int j=n+1;j>0;j--) {
					a[j]=0;
				}
				a[0]=1;
			}else if(m==1) {
				int t=0;
				a=new int[n+1];
				a[n]=0;
				digits[n-1]=digits[n-1]+1;
				for(int i=n-1;i>=0;i--) {
					if(digits[i]>9) {
						a[i]=0;
						digits[i-1]=digits[i-1]+1;
						t++;
					}else {
						a[i]=digits[i];
						t++;
						break;
					}
				}
				for(int j=n-t-1;j>=0;j--) {
					a[j]=digits[j];
				}
			}
		}else {
			a=new int[n+1];
			a[n]=digits[n];
			for(int i=n-1;i>=0;i--) {
				a[i]=digits[i];
			}
		}
		return a;
    }
}
```