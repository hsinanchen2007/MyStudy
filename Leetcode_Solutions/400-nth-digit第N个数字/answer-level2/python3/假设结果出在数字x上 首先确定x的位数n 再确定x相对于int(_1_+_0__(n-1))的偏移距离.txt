思路：一位数字有9个 两位数字有90个 三位数字有900个...
注意：本人菜鸡 关键语句基本都写了注释 还请大家多多指教
```
class Solution:
	def findNthDigit(self,n):
		nums=9 #表示该轮数字有多少个 初始化为9 表示的是一位数字的个数是9个 即：1,2,3,4,5,6,7,8,9
		legt=1 #表示该轮数字的位数 初始化为1 即一位数字
		while n>=legt*nums:
			n-=legt*nums
			nums*=10 #更新 比如一位数字到两位数字时 两位数字共有90个 即：10~99
			legt+=1 #更新 比如一位数字-两位数字
		start=int("1"+"0"*(legt-1)) #确定了n是在legt位数字范围内得到的 start是legt位数字中最小的那个
		index_outer,index_inner=divmod(n,legt)
		if not index_inner: #比如11 到上一步时n=2 index_out=1 index_inner=0
			return str(start+index_outer-1)[-1]
		return str(start+index_outer)[index_inner-1] #比如12 到上一步时n=3 index=1 index_inner=1
```
