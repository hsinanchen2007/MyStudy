单调栈的方法做的时候没有考虑到/(ㄒoㄒ)/~~
本人菜鸡 我的解法的关键的地方都注释了 以下代码仅供参考 还请大家多多指教
注：后续应该会把单调栈的解法加进来的
```
class Solution:
	def longestWPI(self,hours):
		situ=[1 if i>8 else -1 for i in hours] #超过8小时记为1 反之记为-1 主要是方便运算
		high={0:-1} #不同索引可以sum成一个相同的前缀和 high保存其中最大的索引值 low保留其中最小的索引值
		low={0:-1} #※注意一下 初始化的时候使用的0:-1相当于在hours前又添加了一个0 方便后续统一处理
		curr_sum=0 #当前的前缀和
		legt=len(situ)
		for i in range(legt): #遍历hours 同时注意更新high和low
			curr_sum+=situ[i]
			if high.get(curr_sum,None) is None:
				high[curr_sum]=i
				low[curr_sum]=i
			else:
				high[curr_sum]=i
		ans=0 #表示结果 初始化置0
		for c_sum,ind in high.items():
			try:
				t=ind-low[c_sum-1] #只寻找low[c_sum-1]是因为除非ind所表示的索引已经是legt-1 否则ind必然可以重复+1以追求一个子段满足sum==1/直接ind到底
				if t>ans:
					ans=t
			except KeyError: pass
		t_ind=0 #这里就是处理上面说过的(ind所表示的索引已经是legt-1的情况)
		while curr_sum<=0:
			curr_sum-=situ[t_ind]
			if t_ind==legt-1:
				break
			t_ind+=1
		else:
			ans=max(ans,legt-t_ind)
		return ans
```
