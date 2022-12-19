### 解题思路
将数值转换为二进制，如果得到的二进制长度为偶数位则二进制数不变，如果得到的二进制长度为奇数位，则在最前面补充0.将变换后的二进制数的奇数位与偶数位进行交换。

### 代码

```java
class Solution {
    public int exchangeBits(int num) {
        //将数值转换为二进制
		StringBuffer sb=new StringBuffer();
		while(num>0) {
			sb.append(num%2);
			num=num/2;
		}
		if(sb.length()%2==1) {
			sb.append(0);
		}
		sb=sb.reverse();
		int[] ans=new int[sb.length()];
		int i=0;
		for(i=0;i<sb.length()/2;i++) {
			int temp=sb.charAt(2*i)-'0';
			ans[2*i+1]=sb.charAt(2*i+1)-'0';
			ans[2*i]=ans[2*i+1];
			ans[2*i+1]=temp;
		}
		int res=0;
		for(int j=0;j<ans.length;j++) {
			res+=ans[j]*Math.pow(2, ans.length-j-1);
		}
		return res;
    }
}
```