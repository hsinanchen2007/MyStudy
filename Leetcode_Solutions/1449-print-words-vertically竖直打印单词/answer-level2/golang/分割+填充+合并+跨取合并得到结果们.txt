**思路**:见标题+注释(这题目比较直白 我感觉直接看代码理解起来更加高效 /(ㄒoㄒ)/~~)
**注意**:本人菜鸡 效率也不一定很高 还请大家多多指教
```python []
class Solution:
	def printVertically(self,s):
		words=s.split() #本来的单词们
		legt=max(len(w) for w in words) #最长的单词长度
		new_s="".join(w.ljust(legt) for w in words) #用" "填充之前的各个单词并保持左对齐
		return [new_s[i::legt].rstrip() for i in range(legt)] #rstrip()用来去除右边多余的" "
```
```golang []
func printVertically(s string) []string { //主要就是strings包里面的四个函数 Split()+Join()+Repeat()+TrimRight()
	words:=strings.Split(s," ") //原来的单词们
	legt:=0 //原来单词的最大长度 初始化为0
	lens:=[]int{} //每个单词的长度
	for _,w:=range words { //遍历求出最大单词的长度
		t_len:=len(w)
		lens=append(lens,t_len)
		if t_len>legt {
			legt=t_len
		}
	}
	for i:=range words {
		words[i]+=strings.Repeat(" ",legt-lens[i]) //相当于py的ljust 就是填充" "并且保持原来字符串的左对齐
	}
	new_s:=[]rune(strings.Join(words,"")) //用经过处理的单词们来创建新的字符
	ans:=[]string{} //结果
	i,s_len:=0,len(new_s)
	for i<legt { //主体部分 按照规则取出相应的单个字符们组成结果
		idx,t:=i,[]rune{}
		for idx<s_len {
			t=append(t,new_s[idx])
			idx+=legt
		}
		ans=append(ans,strings.TrimRight(string(t)," ")) //去除掉字符串右边多出来的" "
		i++
	}
}
```
