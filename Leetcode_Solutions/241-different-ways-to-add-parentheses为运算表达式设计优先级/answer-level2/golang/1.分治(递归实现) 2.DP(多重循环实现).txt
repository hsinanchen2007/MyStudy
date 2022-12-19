# 一.分治
**思路**:以每一个运算符为界 可以分成左半边和右半边 递归得到左半边和右半边所有可能的运算结果 最后按照运算符完成1×1的笛卡尔积运算
**注意**:python3可以使用@lru_cache()装饰器来尽可能提高递归的效率 两种语言都可以用备忘录来进行优化 本人菜鸡 主要的语句都给了注释(详见py版本) 还请大家多多指教
```python []
from functools import lru_cache #使用这个可以尽量提高递归算法的效率
class Solution:
	@lru_cache()
	def diffWaysToCompute(self,input):
		ans=list()
		for i in range(len(input)):
			c=input[i]
			if c in "+-*":
				le=self.diffWaysToCompute(input[:i]) #左边部分可能的值
				ri=self.diffWaysToCompute(input[i+1:]) #右边部分可能的值
				if c=="+": #对应着三种运算符的笛卡尔积
					ans.extend(x+y for x in le for y in ri)
				elif c=="-":
					ans.extend(x-y for x in le for y in ri)
				else:
					ans.extend(x*y for x in le for y in ri)
		if not ans: #说明当前的input中是没有运算符的
			ans.append(int(input))
		return ans
```
```golang []
import "strconv"
func diffWaysToCompute(input string) (ans []int) {
	for i,v:=range input { //这边没必要用到[]rune的强制类型转换
		c:=string(v) //没有强制类型转换的话得到的是一个uint8/byte类型的值 表示字符的编码值
		if c=="+" || c=="-" || c=="*" {
			le:=diffWaysToCompute(input[:i])
			ri:=diffWaysToCompute(input[i+1:])
			for _,i:=range le {
				for _,j:=range ri {
					if c=="+" {
						ans=append(ans,i+j)
					} else if c=="-" {
						ans=append(ans,i-j)
					} else {
						ans=append(ans,i*j)
					}
				}
			}
		}
	}
	if len(ans)==0 {
		num,_:=strconv.Atoi(input) //就是将一个字符串转换成十进制的数字 要注意有两个返回值 第二个返回值是error类型的
		ans=append(ans,num)
	}
	return
}
```


# 二.DP(动态规划)
**思路**:连续的两个数字的运算结果=>连续的三个数字的运算结果=>连续的四个数字的运算结果=>...老师讲算法的时候有讲过矩阵连乘问题 感觉这题目也可以这么想 语死早 说得不清楚 具体可参考以下链接所示博文[https://blog.csdn.net/qq_32919451/article/details/80643118]()
**注意**:这种方法效率不是很好 主要的语句都添加了注释(详见py版本) 还请大家多多指教 /(ㄒoㄒ)/~~
```python []
from re import compile,findall
class Solution:
	def diffWaysToCompute(self,input):
		opes=findall(compile(r"[\*\+\-]"),input) #把参与运算的运算符们都独立出来
		nums=findall(compile(r"\d+"),input) #把参与运算的数字们都独立出来
		situ=[dict(),{i:[v] for i,v in enumerate(nums)}] #这种结构处理起来比较方便 首元素是故意留空的 <- 方便索引的理解和计算
		for i in range(2,len(opes)+2): #外层循环的次数应该len(opes) 每层最外循环来记录input中连续的i个数字的运算结果
			new=dict()
			for j in range(len(nums)-i+1): #开始索引 如：nums=[1,2,3,4] 当前的i为2 我们就需要计算(1,2),(2,3),(3,4)的值 j表示1,2,3在nums中的索引
				new[j]=list()
				for offset in range(1,i): #左边待计算部分有几个数字 <- 计算其实是分成两部分的 如：需要计算(1,2,3) 可能是1.(1)+(2,3) 2.(1,2)+(3)
					ope=opes[j+offset-1]
					new[j].extend(str(eval(x+ope+y)) for x in situ[offset][j] for y in situ[i-offset][j+offset]) #也是笛卡尔积
			situ.append(new) #接上行注释 situ的第一个索引表示左/右有多少个数字 i之所以从2开始计数,situ首元素为空dict 就是为了这里方便理解和编写 第二个索引表示这些数字中的第一个数字在nums中的索引
		return list(map(int,situ[-1][0]))
```
```golang []
import (
	"strconv"
	"regexp"
)
func diffWaysToCompute(input string) []int {
	reg:=regexp.MustCompile("\\d+")
	nums:=reg.FindAllString(input,-1) //将给定字符串中的数字独立出来
	reg=regexp.MustCompile("[\\+\\-\\*]")
	opes:=reg.FindAllString(input,-1) //将给定字符串中的运算符独立出来
	situ:=[]map[int][]int{make(map[int][]int)} //这是一个切片 切片中的元素是map map的key是int value是[]int 先给了一个空map来占位
	t:=map[int][]int{}
	for i,v:=range nums {
		v_int,_:=strconv.Atoi(v) //数字字符串->数字
		t[i]=[]int{v_int}
	}
	situ=append(situ,t)
	for i:=2;i<len(opes)+2;i++ {
		new:=map[int][]int{}
		for j:=0;j<len(nums)-i+1;j++ {
			new[j]=[]int{}
			for offset:=1;offset<i;offset++ {
				ope:=opes[j+offset-1] //相应的运算符
				p:=[]int{}
				for _,x:=range situ[offset][j] {
					for _,y:=range situ[i-offset][j+offset] {
						if ope=="-" {
							p=append(p,x-y)
						} else if ope=="+" {
							p=append(p,x+y)
						} else {
							p=append(p,x*y)
						}
					}
				}
				new[j]=append(new[j],p...)
			}
		}
		situ=append(situ,new)
	}
	return situ[len(situ)-1][0]
}
```



