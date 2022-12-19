思路:见标题 本人菜鸡 以下代码仅供参考 还请大家多多指教(注:python3的第二种纯属整活儿/(ㄒoㄒ)/~~
```python [1]
#namedtuple其实完全没必要用的 算是简易地创建了complex类 表达更清晰
from functools import namedtuple
class Solution:
	def complexNumberMultiply(self,a,b):
		c_1,c_2=(namedtuple("Complex","real imag")(*map(int,i[:-1].split("+"))) for i in (a,b))
		return "{}+{}i".format(c_1.real*c_2.real-c_1.imag*c_2.imag,c_1.real*c_2.imag+c_1.imag*c_2.real)
```
```python [1]
#各种没必要的操作的集合 很是没事找事 放上来给大家伙儿乐呵乐呵
from itertools import product
class Solution:
	def complexNumberMultiply(self,a,b):
		r_and_i,funcs=[list(map(int,i[:-1].split("+"))) for i in (a,b)],[lambda x:x[0]-x[1],lambda x:x[0]+x[1]]
		return "{1}+{0}i".format(*(funcs.reverse() is None and funcs[0](i) for i in zip(*[r_and_i[1].reverse() is None and [x*y for x,y in product([i],r_and_i[1])] for i in r_and_i[0]])))
```
```golang [1]
import (
	"strings"
	"strconv"
)
func complexNumberMultiply(a string, b string) string {
	num_str,num_int:=make([]string,0,4),make([]int,0,4)
	for _,i:=range [2]string{a,b} {
		num_str=append(num_str,strings.Split(i[:len(i)-1],"+")...)
	}
	for _,i:=range num_str {
		t,_:=strconv.Atoi(i)
		num_int=append(num_int,t)
	}
	return fmt.Sprintf("%d+%di",num_int[0]*num_int[2]-num_int[1]*num_int[3],num_int[0]*num_int[3]+num_int[2]*num_int[1])
}
```
```golang [1]
import "strings"
func complexNumberMultiply(a,b string) string {
	var c,d,ans complex128
	fmt.Sscanf(strings.Replace(a,"+-","-",-1),"%v",&c)
	fmt.Sscanf(strings.Replace(b,"+-","-",-1),"%v",&d)
	ans=c*d
	return fmt.Sprintf("%v+%vi",real(ans),imag(ans))
}
```
