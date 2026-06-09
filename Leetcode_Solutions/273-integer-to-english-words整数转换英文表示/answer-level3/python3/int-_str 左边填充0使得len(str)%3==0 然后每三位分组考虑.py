# 本人菜鸡 比较关键的语句都有注释 哪里写的不行 还行各位多多指教
# ```
from re import findall,sub
from math import ceil
class Solution:
	def numberToWords(self,num):
		if not num:
			return "Zero"
		table={
			"0":"",
			"1":"One",
			"2":"Two",
			"3":"Three",
			"4":"Four",
			"5":"Five",
			"6":"Six",
			"7":"Seven",
			"8":"Eight",
			"9":"Nine",
			"00":"", #配合🚩处看
			"10":"Ten",
			"11":"Eleven",
			"12":"Twelve",
			"13":"Thirteen",
			"14":"Fourteen",
			"15":"Fifteen",
			"16":"Sixteen",
			"17":"Seventeen",
			"18":"Eighteen",
			"19":"Nineteen",
			"20":"Twenty",
			"30":"Thirty",
			"40":"Forty",
			"50":"Fifty",
			"60":"Sixty",
			"70":"Seventy",
			"80":"Eighty",
			"90":"Ninety",
		}
		ans="" #收集结果
		a=["","Thousand","Million","Billion"] #三个数量级 ""是为了方便计算
		str_num=str(num) #数字->str
		str_num=str_num.zfill(ceil(len(str_num)/3)*3) #用0填充数字str 保证len为3的倍数
		parts=findall(r"\w{3}",str_num)[::-1] #使用正则三三分组
		prep=(" Hundred","","")
		for i,j in zip(a,parts): #i表示的是数量级 j表示的是数字
			if j=="000":
				continue
			j=list(j)
			if j[1]=="1": #1x的数字需要特殊处理 🚩
				j[1]=j[1]+j[2]
				j[2]="0"
			else:
				j[1]=j[1]+"0" #配合个位数字 统一使用table查询
			ans=" ".join(table[x]+(y if x!="0" else "") for x,y in zip(j,prep))+" "+i+" "+ans #()里得主要避免百位上数字为0
		ans=ans.strip() #清除两边多下来的" "
		ans=sub(r"\s+"," ",ans) #清除多余的" " 避免" {n>1}"的情况
		return ans
# ```

