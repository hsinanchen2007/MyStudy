**思路**：每一个二进制位表示一种技能 要求找到最少的人数组合满足他们的技能的|(或)是'0b111...'(1的个数等于len(req_skills))
**注意**：本人菜鸡 很多东西表述不清楚 主要的语句都有注释 以下代码仅供参考 还请大家多多指教
``` python
class Solution:
	def smallestSufficientTeam(self,req_skills,people):
		legt=len(req_skills)
		end,table=legt-1,dict(zip(req_skills,range(16))) #table是一个技能和代表的二进制数字的位数的对照表
		bins,dp=[],[[] for _ in range(2<<end)] #dp的索引转换成二进制表示时每一位如果是1表示该项技能是需要的 否则表示该项技能不需要
		for i,skills in enumerate(people):
			if skills: #没啥技能的可能会影响到后来结果的正确性(主要是我不会正确排除影响/(ㄒoㄒ)/~~)
				tmp=["0"]*legt #每位都表示技能的具备与否(1:具备 0:不具备)
				for skill in skills:
					tmp[end-table[skill]]="1"
				bins.append((int("".join(tmp),base=2),i))
		for num,person in bins: #num表示的是数字 person表示的是people这个列表中的索引
			new_dp=dp[:]
			for idx,comb in enumerate(dp):
				if not idx or comb:
					tmp=idx|num
					new_comb=new_dp[idx]+[person] #全新的组合形式
					new_dp[tmp]=new_comb if not new_dp[tmp] or len(new_comb)<len(new_dp[tmp]) else new_dp[tmp]
			dp=new_dp #接上 如果本来没有可行的组合或者新的组合比原先的组合需要的人数要少就换成新的组合
		return dp[-1]
```
