似乎既不是暴力 也不是回溯 大概就是个怪胎吧
本人菜鸡 下面的代码仅供参考 主要的内容都通过注释呈现了
有哪里能优化的希望大家能多多提供意见
```
class Solution:
	def judge(self,num1,num2): #见🚩处 用来判断"第二部分","第三部分"是否可行
		len_1,len_2=len(num1),len(num2)
		if (len_1==1 or not num1.startswith("0")) and (len_2==1 or not num2.startswith("0")): #判断数字的合法性
			if int(num1)<=255 and int(num2)<=255: #判断数字的有效性
				return True
		return False		
	def restoreIpAddresses(self,s):
		legt=len(s)
		if legt<4 or legt>12: #合理性判断
			return []
		ans=[] #收集结果
		first=[i for i in range(1,4) if int(s[:i])<=255 and (i==1 or int(s[0]))] #首先确定的是IP地址的第一部分的情况
		fourth=[legt-i for i in range(3,0,-1) if int(s[-i:])<=255 and (i==1 or int(s[-i]))] #然后确定的是IP地址的第四部分的情况
		for i in first:
			a=s[:i] #已确定的第一部分
			for j in fourth:
				b=s[j:] #已确定的第四部分
				length=j-i #表示中间部分的长度
				if length>6 or length<2:
					if length>6:
						break
					continue
				tmp=s[i:j] #准备一下中间部分 然后分割成两个 -> 第二部分,第三部分
				alter={1,2,3}&{length-1,length-2,length-3} #左右考虑能进行分割的索引(可见往下数第二行) 取∩
				for ind in alter:
					t_le,t_ri=tmp[:ind],tmp[ind:]
					if self.judge(t_le,t_ri): #🚩
						ans.append(a+"."+t_le+"."+t_ri+"."+b) #对可行的情况的IP地址的四个部分进行连接
		return ans
```
