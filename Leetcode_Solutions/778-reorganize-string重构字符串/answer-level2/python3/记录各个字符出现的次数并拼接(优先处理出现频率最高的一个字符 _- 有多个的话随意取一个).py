**思路**：首先给定的原字符串的len假设为n，原字符串中出现得最频繁得一种字符(设为x)的出现次数为m。n可以是奇数也可以是偶数。n为奇数时：如果m>n//2必然不能重构；n为偶数时：如果m>n//2+1必然不能重构 -> m个x从idx=0开始放置，每次idx+=2，如果idx>=n的话，idx重置为1再按照上述规则进行放置(但出现这种情况就已经说明无法重构了)。排除了无法重构的情况，我们就可以考虑如何构造一个可行解了。假设给定的原字符串除了x还有char_1，char_2...，出现次数分别是num_1，num_2...(字符顺序无所谓和出现次数无关)，首先设置一个空字符串s，其次s+=x*m，然后依次s+=char_i\*num_i，然后再按照上述的重构规则进行重构就可以了。最后想说一下为什么最高出现频率字符一定要放在最前面：首先明确为了统一规范，索引0的字符的确定优先于索引1的字符，然后参见"212"(√)和"122"(×)可见先放置最高出现频率字符的话，对m更加宽容。
**注意**：本人菜鸡+语死早，很多地方可能表述得很不清楚，主要的语句都添加了注释，还请各位多多指教。
```python []
from collections import Counter
class Solution:
	def reorganizeString(self,S):
		cnt,n=Counter(S),sum(divmod(len(S),2)) #n就是用来评判是否可以重构的一个基准
		char,num=cnt.most_common(1)[0] #出现频率最高的字符及其出现的次数
		if num>n: #重构不了直接返回""
			return ""
		del cnt[char] #少不了
		t=char*num+"".join(i*j for i,j in cnt.items()) #出现频率最高的字符*出现次数+按任意顺序拼合的其他字符们
		ans=" "*len(S) #重构规则的具体实现 <- 可能最后被注释的那一行的写法更好理解一些
		ans[::2],ans[1::2]=t[:n],t[n:] #注意ans=" "*len(S)是不能这样来的 字符串不允许直接这样赋值 因为str本身虽是序列但是元素不可变 就像tuple一样
		return "".join(ans)
		#也可以是 -> from itertools import zip_longest return "".join(i+j for i,j in zip_longest(t[:n],t[n:],fillvalue=""))
```
```golang []
import "strings"
func reorganizeString(S string) string {
	count,legt:=make(map[rune]int),len(S)
	n:=legt/2+legt%2 //后续会用到 用来判断是否可以重构的一个基准
	info:=struct{ //也可以
		char rune //出现次数最多的字符
		cnt int //出现次数最多的字符出现的次数
	}{'0',0} //char随便设置只要cnt初始化为0就可以了
	for _,c:=range S {
		count[c]=count[c]+1
		if t_cnt:=count[c];t_cnt>info.cnt {
			info.char,info.cnt=c,t_cnt //更新info的信息
		}
	}
	if info.cnt>n { //不可重构直接return ""
		return ""
	}
	ans:=strings.Repeat(string(info.char),info.cnt) //出现频率最高的字符*出现次数
	delete(count,info.char) //少不得
	for i,j:=range count { //按照任意顺序加上其他的字符们
		ans=ans+strings.Repeat(string(i),j)
	}
	f_ans:=make([]byte,legt) //重构规则的具体实现
	for i,k:=0,0;i<n;i++ {
		for j:=i;j<legt;j=j+n {
			f_ans[k]=ans[j]
			k++
		}
	}
	return string(f_ans)
}
```
