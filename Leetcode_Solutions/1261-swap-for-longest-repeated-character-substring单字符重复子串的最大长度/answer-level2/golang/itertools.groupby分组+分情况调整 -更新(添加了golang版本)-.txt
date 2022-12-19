**思路**:在分组的基础上对结果有影响的其实就只有三种情况
	- 1.如:aabaaa<-两组可以合并成一个新组
	- 2.如:abbaaa<-较长的一组可以长度+1
	- 3.1-2的结合 如:aabaaacdea<-aaaaaacdeb
**注意**:之所以我觉得这方法还可以主要是因为py3有提供groupby,defaultdict,Counter...写起来比较方便 ac之后有看到大佬们的滑动窗口法 那当然更好 本人菜鸡 主要的语句都添加了注释(详见py版本 go版本只对部分区别于py的语句加了注释) 还请大家多多指教

```python []
from itertools import groupby
from collections import defaultdict,Counter
class Solution:
	def maxRepOpt1(self,text): #核心/基础就是使用groupby来分段
		char=[] #char[i]表示的是第i段的字符
		legt=[] #legt[i]表示的是第i段的长度
		p_ans=defaultdict(int) #每种字符组成的段的最大长度 初始化都是0 <- 使用defaultdict主要是图方便
		for i,j in groupby(text):
			char.append(i) #字符
			l=len(list(j)) #长度
			legt.append(l)
			p_ans[i]=max(p_ans[i],l) #更新
		cnt=Counter(char) #每种字符的段各有多少个
		for i in cnt:
			if cnt[i]!=1: #段数不止一个 就可以调换一个相应的字符过来 使得相应段的长度+1 如:abbbaaaaaaaa -> bbbaaaaaaaaa
				p_ans[i]+=1
		for i in range(2,len(char)): #从索引2开始的理由往下看
			t_bfe,t_aft=char[i-2],char[i]
			if t_bfe==t_aft and legt[i-1]==1: #符号是一样的 并且 中间隔着的一组只有一个字符 如:abaaa  /  aabaaacdea
				if cnt[t_aft]==2: #上面的第一个示例 两个合并已经是最佳解了
					p_ans[t_aft]=max(p_ans[t_aft],legt[i-2]+legt[i])
				else: #上面的第二个示例 可以调换两组之外的一个相应字符作为两段的纽带
					p_ans[t_aft]=max(p_ans[t_aft],legt[i-2]+legt[i]+1)
		return max(p_ans.values())
```
```golang []
func maxRepOpt1(text string) (ans int) {
	s_slice:=[]rune{}
	for _,i:=range text+" " { //对字符串range遍历就相当于string->[]rune再遍历
		s_slice=append(s_slice,i) //为了使得最后一组也能和其他组一样及时地记录char和legt 所以在s的最后添加了一个不可能出现在给定text中的字符
	}
	chars:=[]rune{}
	legts:=[]int{}
	p_ans:=map[rune]int{}
	cnts:=map[rune]int{}
	for i,char,legt:=1,s_slice[0],1;i<len(s_slice);i++ { //分组 相当于itertools.groupby
		if s_slice[i]==char {
			legt++
		} else {
			chars=append(chars,char)
			legts=append(legts,legt)
			if legt>p_ans[char] {
				p_ans[char]=legt
			}
			cnts[char]+=1
			char=s_slice[i]
			legt=1
		}
	}
	for i:=range p_ans { //一个字符对应着多组(>1)即可+1 更新p_ans
		if cnts[i]>1 {
			p_ans[i]+=1
		}
	}
	for i:=2;i<len(chars);i++ { //可连接 更新p_ans
		c:=chars[i]
		if c==chars[i-2] && legts[i-1]==1 {
			if cnts[c]==2 {
				t_len:=legts[i]+legts[i-2]
				if t_len>p_ans[c] {
					p_ans[c]=t_len
				}
			} else {
				t_len:=legts[i]+legts[i-2]+1
				if t_len>p_ans[c] {
					p_ans[c]=t_len
				}
			}
		}
	}
	for _,i:=range p_ans { //相当于py3的max(p_ans.values())
		if i>ans {
			ans=i
		}
	}
	return
}
```


