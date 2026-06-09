### 解题思路
此处撰写解题思路

	思路：
		核心，以'['作为：递归入口
			  以']'作为：递归出口
				number,character用另外的2个变量：每次递归中增量

	核心算法缩略结构：
		dfs(i):
			if xxx:
				dfs(i+1) # 核心，以'['作为递归入口
		



### 代码

```python3
class Solution:
	def decodeString(self,s:str) -> str:

		def dfs(s,i):
			res , multi = "" , 0 # res 答案 ；multi 倍率

			while i < len(s):
				if '0'<=s[i]<='9': # number
					multi = multi * 10 + int(s[i]) # 考虑数字是2位/2位以上

				elif s[i] == '[': # 遇到'['括号
					i , tmp = dfs(s,i+1) # 递归到下一个[]内的字符串tmp，指针+1
					res += multi * tmp # tmp = 上一层[]的res,
					multi = 0

				# 遇到']'=递归边界，结束递归，返回这一次']'的i和从内到外目前已有的res
				elif s[i] == ']': 
					return i,res # i , tmp

				else:  # 其余都属于character
					res += s[i]

				i += 1

			return res

		return dfs(s,0)
```