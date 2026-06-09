# 双指针+set
我们用set集合+双指针的方式模拟滑动窗口来实现这道题。   
滑动窗口就是在一个区间范围内，左边和右边指针中间的那片区域。    
![1.jpg](https://pic.leetcode-cn.com/513709b1c444248638340b38443675033d64f9181f39a54bd71447f18cbbf2a6-1.jpg)
   
当右指针往前移动时，窗口就在扩大。当左指针向前移动时候窗口就在收缩。注意指针只能向前(也就是往右边)移动，不能往回(左边)移动。这点跟TCP的滑动窗口模型是非常类似的。   
我们定义一个set和i，j两个指针。set是用来判断某个字符是否重复出现了，i和j用来模拟滑动窗口，i和j之间的字符串，就是当前的最长子串。   
我们在遍历的时候i和j之间的长度是不断变化的，只要每次记住最大值，最终遍历完后，就能确定无重复最长子串的长度了。   
![动态图.gif](https://pic.leetcode-cn.com/f7f4aa0f5e3e42c2e1ff8786c113fc14373f9dca0202ec7ebe8b3e3f523b8709-%E5%8A%A8%E6%80%81%E5%9B%BE.gif)

每次遍历的时候，只要当前字符不在set中，就放进去，同时j++。   
如果当前字符在set中，就更新i指针，将i到j这段的字符都从set中去掉。这实际上是将窗口左边往右移动。   
代码的空间空间复杂度是O(n)，时间复杂度也是O(n)。   
代码实现：
```java []
class Solution {
	public int lengthOfLongestSubstring(String s) {
		if(s==null || "".equals(s)) {
			return 0;
		}
		int n = s.length();
		//定义两个指针i和j
		int i = 0;
		int j = 0;
		Set<Character> set = new HashSet<Character>();
		int res = 0;
		while(i<n && j<n) {
			//j指向的元素不在set中，就放进去，同时更新窗口(j++)，并计算窗口大小
			if(!set.contains(s.charAt(j))) {
				set.add(s.charAt(j));
				j++;
				res = Math.max(res,j-i);
			//如果j指向的元素在set中，删除重复的元素，i往前移动一位
			} else {
				set.remove(s.charAt(i));
				i++;
			}
		}
		return res;
	}
}
```
```python []
class Solution(object):
	def lengthOfLongestSubstring(self, s):
		"""
		:type s: str
		:rtype: int
		"""
		if not s:
			return 0
		# 定义两个指针i和j
		i,j,size = 0,0,len(s)
		letter,res = set(),0
		while i<size and j<size:
			# j指向的元素不在set中，就放进去，同时更新窗口(j++)，并计算窗口大小
			if s[j] not in letter:
				letter.add(s[j])
				j += 1
				res = max(res,j-i)
			# 如果j指向的元素在set中，删除重复的元素，i往前移动一位
			else:
				letter.remove(s[i])
				i += 1
		return res
```
   
   
   
# 优化后的滑动窗口
前面的例子中，我们用了滑动窗口，但这个滑动窗口性能不是最好的，最坏的情况下两个指针i和j都需要移动n次，也就是需要两次遍历。
我们可以在上面代码基础上做优化，前面我们用"pwwkew"举了例子，当j指针遍历到第二个w的时候，出现重复了，于是i指针开始往前走，最后落在第二个w处。   
这里是一个优化点，可以直接让i指针跳到第二个w处。   
借助一个map，key是字符，value是字符的下标。当字符重复的时候，我们就找到这个map中这个重复的字符的下标，然后让指针再移动一位即可。   
![2.jpg](https://pic.leetcode-cn.com/9f29a99f80978ce7c9d57e5ba543ba4c887d31aac21c3c2a3424ded23cf97277-2.jpg)


代码如下：
```java []
class Solution {
	public int lengthOfLongestSubstring(String s) {
		if(s==null || "".equals(s)) {
			return 0;
		}
		Map<Character,Integer> map = new HashMap<Character,Integer>();
		int left = 0;
		int res = 0;
		for(int i=0;i<s.length();i++) {
			//如果当前遍历的字符在map中，就更新左窗口
			//假设当前字符是‘a'，map.get(s.charAt(i))就是上一个’a'的位置
			if(map.containsKey(s.charAt(i))) {
				left = Math.max(left,map.get(s.charAt(i))+1);
			}
			//记录当前字符和下标，并更新窗口的大小
			map.put(s.charAt(i),i);
			res = Math.max(res,i-left+1);
		}
		return res;
	}
}
```
```python []
class Solution(object):
	def lengthOfLongestSubstring(self, s):
		"""
		:type s: str
		:rtype: int
		"""
		if not s:
			return 0			
		d,left,res, = dict(),0,0
		for i in xrange(len(s)):
			# 如果当前遍历的字符在字典中，就更新左窗口
			# 假设当前字符是‘a'，d[s[i]]就是上一个’a'的位置
			if s[i] in d:
				left = max(left,d[s[i]]+1)
			# 记录当前字符和下标，并更新窗口的大小	
			d[s[i]] = i
			res = max(res,i-left+1)
		return res
```
(全文完)   
   
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)