思路：见标题
注意：在执行用时分布图表见到了不少更加精炼的正则解法 但是那些解法的pattern都写得蛮长的 我的pattern稍微简单一些 各有裨益吧 以下代码仅供参考 还请各位多多指教
```
from re import compile,match
class Solution:
	def isNumber(self,s):
		pattern=compile(r"[+-]{0,1}(?:\d*\.\d+|\d+\.\d*|\d+)") #用来匹配带+-的合法浮点数
		s=s.strip() #删掉两边的" "
		a,b,c=s.partition("e")
		if not b: #s字符串中没有e
			try:
				if a==pattern.match(a).group():
					return True
				return False
			except AttributeError: #在没有匹配到的时候使用==就会抛出AttributeError
				return False
		else:
			try:
				if "." not in c and a==pattern.match(a).group() and c==pattern.match(c).group(): #e后面不能是浮点数 只能是整数
					return True
				return False
			except AttributeError: #同上
				return False
```
