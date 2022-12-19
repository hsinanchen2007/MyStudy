
这完全可以看成**多个子问题**：
n个数，第k个；

求第一位，肯定是**取决于n-1个数有多少种排列**；

求第二位，取决于n-2个数有多少种排列；（此时可以把取到的第一个数给去掉，看成是有n-1个数进行全排列），**那第k个值变成多少呢**，**若k小于之前的(n-1)!，当然是不变，若大于，则取余数**，这是关键；

依次遍历，直至结束；

```
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
    	f = self.factorial(n)
    	s = ""
    	l = [i for i in range(1, n+1)]
    	for i in range(0, n):
    		k %= f
    		f /= n - i
    		s += str(self.helps(f, k, l))
    	return s

    def factorial(self, n):
    	num = 1
    	while n >0 :
    		num *= n
    		n -= 1
    	return num

    def helps(self, f: int, k: int, l) -> str:
    	c = int((k - 1) // f)
    	num = l.pop(c)
    	return num

```
