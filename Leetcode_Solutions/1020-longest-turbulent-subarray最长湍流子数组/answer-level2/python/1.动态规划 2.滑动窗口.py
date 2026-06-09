# 一.DP
**思路**：比较常规 分成两种情况
```python []
class Solution:
	def maxTurbulenceSize(self,A):
		dp_1=dp_2=ans=1 #一个是↗ 一个是↘
		for prev,cur in zip(A[:-1],A[1:]):
			if cur>prev:
				dp_1,dp_2=1,dp_1+1
				if dp_2>ans:
					ans=dp_2
			elif cur==prev:
				dp_1=dp_2=1
			else:
				dp_1,dp_2=dp_2+1,1
				if dp_1>ans:
					ans=dp_1 #也可以直接在最后ans=max(ans,dp_1,dp_2) 不需要写两个判断了
		return ans
```
```golang []
func maxTurbulenceSize(A []int) int {
	dp_1,dp_2,ans:=1,1,1
	for i:=1;i<len(A);i++ {
		if cur,prev:=A[i],A[i-1];cur>prev {
			dp_1,dp_2=1,dp_1+1
			if dp_2>ans {
				ans=dp_2
			}
		} else if cur==prev {
			dp_1,dp_2=1,1
		} else {
			dp_1,dp_2=dp_2+1,1
			if dp_1>ans {
				ans=dp_1	
			}
		}
	}
	return ans
}
```
# 二.滑动窗口
**思路**：断掉的地方就可能是新的起点
```python []
class Solution:
	def maxTurbulenceSize(self,A):
		ans,legt,i=1,len(A),1 #i遍历A时的索引
		try:
			while True:
				while i<legt and A[i]==A[i-1]: #先把一连串的==全都过掉 比如[1,1,1,2]直接来到i==3的位置
					i+=1
				assert i!=legt
				l,flag=2,A[i]>A[i-1] #True:↗ False:↘ l表示当前的湍流子数组的长度
				i+=1
				while i<legt and A[i]!=A[i-1] and (A[i]>A[i-1])!=flag: #这边两个比较有点浪费 可以flag=A[i]-A[i-1] 然后比较乘积是否是负数
					l+=1
					i+=1
					flag=not flag #转换
				ans=l if l>ans else ans
		except AssertionError:
			return ans
```
```golang []
func maxTurbulenceSize(A []int) int {
	ans,i,legt:=1,1,len(A) //i遍历A时的索引
	for {
		for i<legt && A[i]==A[i-1] { //先把一连串的==全都过掉 比如[1,1,1,2]直接来到i==3的位置
			i++
		}
		if i==legt {
			return ans
		}
		l,flag:=2,A[i]>A[i-1] //True:↗ False:↘ l表示当前的湍流子数组的长度
		i++
		for i<legt && A[i]!=A[i-1] && (A[i]>A[i-1])!=flag {
			l++
			i++
			flag=!flag //转换
		}
		if l>ans {
			ans=l
		}
	}
}
```
**注意**：本人菜鸡 尤其是滑动窗口的代码写得比较繁杂 还请大家多多指教

