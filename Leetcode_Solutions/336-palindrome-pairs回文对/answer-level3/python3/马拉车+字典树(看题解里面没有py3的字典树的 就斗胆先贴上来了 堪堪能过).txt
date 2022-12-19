**注意**：本人菜鸡(马拉车还是今早刚糙糙学的 Trie也没用过几次) 主要的语句都添加了注释 还请大家多多指教 欢迎提出改进意见!
``` python
from itertools import zip_longest
class Solution:
	def palindromePairs(self,words):
		try: null=words.index("") #""太特殊了 还是特殊处理比较方便
		except:	null=-1
		def manacher(s): #马拉车算法
			ori_size=len(s) #字符串原本的长度
			s="{#"+"#".join(s)+"#}" #变化字符串 马拉车算法实现的根基
			cur_size=len(s)
			p=[0]*(cur_size-1)
			Id=Max=0
			for i,c in enumerate(s[1:-1],1):
				if Max>i:
					p[i]=min(p[(Id<<1)-i],Max-i)
				else:
					p[i]=1
				while s[i-p[i]]==s[i+p[i]]: #上面虽然是马拉车的关键 但是这边也是不能少的 一开始我就是没注意这个所以死活没完全理解马拉车/(ㄒoㄒ)/~~
					p[i]+=1
				if p[i]+i>Max:
					Id,Max=i,p[i]+i
			return [n-1==i for i,n in enumerate(p[2:1+ori_size],1)] #前缀字符串是不是回文
		prefixTrie=dict() #创建一个前缀字典树
		for i,word in enumerate(words):
			tmp,p=prefixTrie,manacher(word[::-1])
			for char,flag in zip_longest(word,p[::-1],fillvalue=True):
				tmp=tmp.setdefault(char,{})
				if flag: #一定要注意这边的先后顺序 先tmp到下一层 然后再看flag
					tmp.setdefault("can",[]).append(i)
			tmp["#"]=i #字符串的结束标志
		ans=[]
		for i,word in enumerate(words):
			tmp,p=prefixTrie,manacher(word)
			try:
				for char,flag in zip_longest(word[::-1],p[::-1]):
					tmp=tmp[char]
					if flag and "#" in tmp:
						ans.append([tmp["#"],i])
				for idx in tmp.get("can",[]):
					if i==idx:
						if null!=-1:
							ans+=[[null,i],[i,null]]
					else:
						ans.append([idx,i])
			except KeyError: #找不到匹配的路径了
				continue
		return ans
```

