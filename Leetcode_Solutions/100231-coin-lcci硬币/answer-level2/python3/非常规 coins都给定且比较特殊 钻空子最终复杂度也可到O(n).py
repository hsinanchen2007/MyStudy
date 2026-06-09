**思路**：首先设置一个函数helper(n,coin) coin用来表示币值可以取1,5,10,25 假如说现在要求100分有多少种组成 那么肯定首先调用helper(100,25) 然后根据常规DP的思想 helper(100,25)=helper(100,10)+helper(75,10)+helper(50,10)+helper(25,10)+helper(0,10) helper(25,10)=helper(25,5)+helper(15,5)+helper(5,5)... 我们会意识到当coin==1时 对于任何n helper(n,1)的返回值都是1 再接着利用这一个性质可以发现当coin==5时 helper(n,5)的返回值应该就是n//5+1 再接着利用这个性质可以发现当coin==10时 helper(n,10)的返回值应该就是sum(i//5+1 for i in range(n,-1,-10)) 于是我们可以写出一个解决方案了
```
class Solution:
	def waysToChange(self,n):
		def helper(n,coin):
			if coin==10:
				return sum(i//5+1 for i in range(n,-1,-10))
			return sum(helper(i,10) for i in range(n,-1,-25))
		return helper(n,25)%1000000007
```
继续拿上面例子来看
helper(100,10)->sum(21,19,17,...,1) 公差为-2的等差数列且最后一个元素为1
helper(75,10)->sum(20,18,...,0) 公差为-2的等差数列且最后一个元素为0
...
因为range(n,-1,-10)和n//5+1 所以上面两个为等差数列不是偶然的 这样子的话helper(n,10)就转化为等差数列求和了
也就是(首尾元素之和/2)*总元素的个数 这样子最终的结果也就应运而生了
```python []
class Solution:
	def waysToChange(self,n):
		return (sum((i//2+1)**2 if i%2 else (i//2)*(i//2+1) for i in range(n//5+1,0,-5)))%1000000007
```
```golang []
func waysToChange(n int) (ans int) {
	const v int=1000000007
	for i:=n;i>0;i=i-25 {
		if t:=i%2;t==1 {
			t_v:=(i+1)/2
			ans=(ans+(t_v*t_v)%v)%v //过程数字可能会超出golang数字表示范围 所以每次都要%v
		} else {
			t_v:=i/2
			ans=(ans+(t_v*(t_v+1))%v)%v
		}
	}
	return
}
```
**注意**：硬币找零常规做法可以参见322题 对应这题复杂度也是O(n)


