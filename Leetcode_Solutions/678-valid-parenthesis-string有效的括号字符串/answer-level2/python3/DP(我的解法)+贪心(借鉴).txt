1.DP 时间复杂度O(n²) 空间复杂度O(n)
```
def leetcode_678(s):
	if not s or s[0]==")":
		return not s
	legt=len(s)
	situ=[s[0]=="*"]+[True]+[False for i in range(legt-1)] #如果已遍历的s剩下的"("有n个 则situ[n]=True
	for i in s[1:]:
		if i=="(":
			for i in range(legt-1,-1,-1):
				if situ[i]:
					situ[i]=False #以下两句来更新situ的状态
					situ[i+1]=True
		elif i==")":
			has=False
			for i in range(legt):
				if situ[i]:
					situ[i]=False
					if i:
						situ[i-1]=True
						has=True #表示还有可以匹配的"("
			if not has:
				return False
		else:
			tmp=[i for i,j in enumerate(situ) if j] #比较特殊 不能向上面两种情况一样直接处理
			for i in tmp:
				situ[i+1]=True
				if i:
					situ[i-1]=True
	return situ[0]
```
2.贪心算法 时间复杂度O(n) 空间复杂度O(1)
```
def leetcode_678(s):
	legt=len(s)
	le,ri=0,0 #le表示→遍历 "*"+"("的个数   ri表示←遍历 "*"+")"的个数
	for i in range(legt):
		if s[i]==")":
			le-=1
		le+=1
		if le*2<(i+1):
			return False #")"太多了 直接就是False
	for i in range(legt-1,-1,-1):
		if s[i]=="(":
			ri-=1
		ri+=1
		if ri*2<(legt-i):
			return False #"("太多了 直接就是False
	return True
```
