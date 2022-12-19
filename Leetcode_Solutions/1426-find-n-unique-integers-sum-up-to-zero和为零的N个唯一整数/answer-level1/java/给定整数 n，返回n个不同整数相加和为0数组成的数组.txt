### 解题思路
因为要求和为0，想到相反数。当给定n为偶数时，只需n/2个不同的正数加上她们的相反数。
若给定n为奇数时，在n/2个不同的正数加上她们的相反数基础上，补0；
(小菜鸟的分享，有错误帮忙指出，谢谢大家~)

### 代码

```java
class Solution {
    public int[] sumZero(int n) {
        int[] ans=new int[n];
		int j=0;
		int flag=n%2;
		int mod=n/2;
		if(flag==0) {
			for(int i=1;i<=mod;i++) {
				ans[j++]=i;
				ans[j++]=Math.negateExact(i);
			}
		}
		else {
			for(int i=1;i<=mod;i++) {
				ans[j++]=i;
				ans[j++]=Math.negateExact(i);
			}
			ans[j]=0;
		}
		return ans;
    }
}
```