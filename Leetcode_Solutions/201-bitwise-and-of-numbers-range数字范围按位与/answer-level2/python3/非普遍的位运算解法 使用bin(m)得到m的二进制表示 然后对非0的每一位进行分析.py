# 思路：
# ————只要m-n的中有任何一个数的第k二进制位为0 那么ans的数的第k二进制位也是0
# 关键：
# ————🚩处的解释->创建了一个二进制数x x满足三个条件
# ————————1.x_str[zero_ind]="1" 
# ————————2.x_str[:zero_ind]=bin_m[:zero_ind]
# ————————3.x_str[zero_ind+1:len(bin_m)]全是"0"
# ————这个数必然具有的性质->在所有大于m且...[zero_ind]="1"的数中 它是最小的
# 补充：
# ————不熟悉位运算 自己在做的时候没有想到大佬们的普遍解法(后续大概会补上) 以下代码也不简练 仅供参考
# ```
class Solution:
	def rangeBitwiseAnd(self,m,n):
		bin_m=bin(m)[2:]
		bin_n=bin(n)[2:]
		if not m or len(bin_n)>len(bin_m): #m=0不必说 后面一个条件表明 a,b二进制位数不一样 b进位是必然出现"100..."的情况 简单分析可知ans应该为0
			return 0
		situ=["1"]+["0" for i in range(len(bin_m)-1)]
		zero_ind=None #配合后面的循环使用 表示离当前index最近的zero的索引 初始化为None 表明没有出现0
		for i in range(1,len(bin_m)):
			if bin_m[i]=="0":
				zero_ind=i #要注意更新zero_ind的位置
			else: #遇到了"1"
				if zero_ind is None: #如果没有任何可以从"0"替换到"1"的高二进制位
					situ[i]="1"
				else: #有可以替换成"1"的高二进制位
					new=int("0b"+bin_m[:zero_ind]+"1"+"0"*(len(bin_m)-zero_ind-1),base=2) #🚩. 关键句
					if new<=n: #x_str[zero:len(bin_m)]全是"0" 且m<x<=n 所以后面就不需要看了
						break
					else: #x已经是最小的了 没有其他任何可能在满足...[zero_ind]="1"的数还能满足>m且<=n 所以该位必定是"1"
						situ[i]="1"
		return int("0b"+"".join(situ),base=2)
# ```
