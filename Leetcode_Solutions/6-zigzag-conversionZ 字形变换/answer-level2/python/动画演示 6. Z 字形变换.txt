## 题解
以```"1234567890abcdefg"```为例，先看下变换的动态图:   
![1.gif](https://pic.leetcode-cn.com/fa7addad85c6e6bf270e2779074b9cec1094fadcca3b220ed06d96d6b3bdf742-1.gif)
这就相当于我们创建了```numRows```个数组，然后将遍历字符串，并将遍历到的字符往数组里面放，第一个字符放到```arr[0]```中，第二个放到```arr[1]```中，第numRows-1个字符放到```arr[numRows-1]```。   
而到了```arr[numRows-1]```之后，就要开始反向走了，往```arr[numRows-2]```，```arr[numRows-3]```，一直到```arr[0]```。     
所以这个过程是不断的往下、往上、往下、往上如此反复。   
但是```第一行```和```最后一行```特殊，当遍历到第一行时，整个顺序就要往下，而遍历到最后一行时，遍历顺序就要往上。   
我们只需要一个特殊的标志位，根据是否是```第一行```或者```最后一行```来判断是否要向上或者向下。   
当nunRows个数组都按顺序放好后，就挨个把他们拼接起来，最后返回。
```
19g
280f
37ae
46bd
5c
```
时间复杂度:O(N)   
空间复杂度:O(N)   
   
代码实现:
```java []
class Solution {
	public String convert(String s, int numRows) {
		if(s==null || numRows<=1) {
			return s;
		}
		int n = s.length();
		//取numRows，字符串s长度的较小值，用这个较小值来创建n个StringBuilder
		int rows = Math.min(n,numRows);
		StringBuilder[] arr = new StringBuilder[rows];
		for(int i=0;i<arr.length;++i) {
			arr[i] = new StringBuilder();
		}
		int j = 0;
		//向上还是向下的标志位
		boolean isDown = false;
		StringBuilder res = arr[0];
		//遍历字符串s，并将字符放到arr[j]中，之后根据标志位来判断是继续往下还是往上
		for(int i=0;i<n;++i) {
			arr[j].append(s.charAt(i));
			if(j==0 || j==numRows-1) {
				isDown = !isDown;
			}
			if(isDown) {
				++j;
			} else {
				--j;
			}
		}
		//将数组中的字符串挨个合并最后返回
		for(int i=1;i<arr.length;++i) {
			res.append(arr[i]);
		}
		return res.toString();
	}
}
```
```python []
class Solution(object):
	def convert(self, s, numRows):
		if not s or numRows<=1:
			return s
		# 取numRows，字符串s长度的较小值，用这个较小值来创建n个StringBuilder	
		res = [[] for _ in xrange(min(numRows,len(s)))]
		# 向上还是向下的标志位
		is_going_down = False
		n = len(s)
		j = 0
		string = ""
		# 遍历字符串s，并将字符放到arr[j]中，之后根据标志位来判断是继续往下还是往上
		for i in xrange(n):
			res[j].append(s[i])
			if j==0 or j==numRows-1:
				is_going_down = not is_going_down
			j = j+1 if is_going_down else j-1
		# 将数组中的字符串挨个合并最后返回	
		for i in res:
			string += "".join(i)
		return string
```
(全文完)

**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)