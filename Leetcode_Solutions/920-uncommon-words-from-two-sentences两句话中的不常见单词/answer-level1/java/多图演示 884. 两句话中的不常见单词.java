# 题解
假设有下面这两个句子   
![1.jpg](https://pic.leetcode-cn.com/38d6f010e74a47af8450c66003de906e03bba968636ce720b8049cf85469b63d-1.jpg)
要实现题目的要求，就要先建立两个map，分别统计A和B句子中每个单词的出现频率，就像下面这样：   
![2.jpg](https://pic.leetcode-cn.com/f0f89085347bdeb358c39f7e9bebbe666d5eb487b75ef1351f52ee37bc780918-2.jpg)
我们不能简单的取中间交集的部分，因为右边黄色区域bb出现了两次，所以中间红色交集部分还的把bb去掉，最终结果应该是cc，dd。
这样弄起来还挺麻烦，我们不如换个思路，将A，B句子中所有的单词都加入到一个map中看看。   
![3.jpg](https://pic.leetcode-cn.com/69587221edfe8a8b3f8b359a10abe9b01f5915eeeeb5ea82f5f9725efc3ef3b5-3.jpg)
   
通过上图中的map，我们很容易统计出map中每个单词出现的频率，然后将频率大于1的单词去掉。   
![4.jpg](https://pic.leetcode-cn.com/0e19f2ea67ef37c0dbc8f0a8065fe97b7984acb03cd3fba70ed792e6c9bcd6d5-4.jpg)
   
最终剩下的就是我们要的结果啦   
![5.jpg](https://pic.leetcode-cn.com/d0dceef70cbae99ff4e612874e60ff913f31bd5da0556accfccc4f34cc71805e-5.jpg)
   
这个解法的空间复杂度是O(n+m)，时间复杂度也是O(n+m)。   
   
代码实现：
```java []
import java.util.Iterator;
import java.util.Map.Entry;
class Solution {
	public String[] uncommonFromSentences(String A, String B) {
		if(A==null || "".equals(A) || B==null || "".equals(B)) {
			return new String[]{};
		}
		Map<String,Integer> map = new HashMap<String,Integer>();
		// 按空格分割A，B两个句子
		String[] splitA = A.split(" ");
		String[] splitB = B.split(" ");
		List<String> res = new ArrayList<String>();
		//统计A句子中每个单词出现的频率
		for(String s : splitA) {
			map.put(s, map.getOrDefault(s, 0)+1 );
		}
		//统计B句子中每个单词的出现频率
		for(String s : splitB) {
			map.put(s, map.getOrDefault(s, 0)+1 );		
		}
		//扫面一遍字典，统计字典中单词频率==1的单词
		for(Iterator<Entry<String, Integer>> iter=map.entrySet().iterator();iter.hasNext();) {
			Entry<String,Integer> entry = iter.next();
			if(map.get(entry.getKey())==1) {
				res.add(entry.getKey());
			}
		}
		return res.toArray(new String[] {});
	}
}
```
```python []
class Solution(object):
	def uncommonFromSentences(self, A, B):
		"""
		:type A: str
		:type B: str
		:rtype: List[str]
		"""
		if not (A or B):
			return []
		d,res = dict(),[]
		# 统计A句子中每个单词出现的频率
		for i in A.split(" "):
			# 如果d.get()获取不到就用默认值0并加1
			d[i] = d.get(i,0)+1
		# 统计B句子中每个单词的出现频率
		for i in B.split(" "):
			d[i] = d.get(i,0)+1
		# 扫面一遍字典，统计字典中单词频率==1的单词
		for i in d:
			if d[i]==1:
				res.append(i)
		return res
```
(全文完) 
   
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)