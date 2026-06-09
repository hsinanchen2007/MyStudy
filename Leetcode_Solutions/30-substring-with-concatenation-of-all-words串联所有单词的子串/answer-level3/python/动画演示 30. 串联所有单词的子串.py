# 题解 
这道题可以用滑动窗口的方式来解决，窗口的大小是words数组里面所有单词的总和。   
因为字符串s如果有子串能完全匹配words，那肯定是words中的每个单词都要出现若干次的(words里面的单词可能有重复)。   
以barfoothefoobarman为例，words=["foo","bar"]，那么窗口大小就是6(foo+bar的长度)。   
![img_2644.jpg](https://pic.leetcode-cn.com/008b03dade01dbb56460891a0e54ba4db32c7d1a08d025d6aa6cadde6e047047-img_2644.jpg)
   
我们从字符串s的开始位置起，每次截取6位长度记做tmp，跟words的单词比较。words中的单词都放到一个map中，key是单词，value是这个单词出现的次数。我们比较tmp和map是否完全匹配，如果是就找到了一个索引位置。   
我们按照这种方式迭代完整个数组，就可以求出解了。   
![动态图.gif](https://pic.leetcode-cn.com/93fb4436340daedd835496ea52c7b5c16761bc115f621dc656c625e044038379-%E5%8A%A8%E6%80%81%E5%9B%BE.gif)


代码实现：
```java []
class Solution {
	public List<Integer> findSubstring(String s, String[] words) {
		if(s==null || "".equals(s) || words==null || words.length==0) {
			return new ArrayList<Integer>();
		}
		//将每个单词以及出现的频率记录到map中
		Map<String,Integer> words_map = new HashMap<String,Integer>();
		for(String str : words) {
			if(words_map.containsKey(str)) {
				words_map.put(str,words_map.get(str)+1);
			} else {
				words_map.put(str,1);
			}
		}
		List<Integer> res = new ArrayList<Integer>();
		//words中一个单词的长度，以及words的总长度
		int one_word_size = words[0].length();
		int all_word_size = words.length * one_word_size;
		//遍历整个字符串，注意循环的结束条件
		for(int i=0;i<s.length()-all_word_size+1;i++) {
			//每次取 all_word_size长度的子串
			String tmp = s.substring(i,i+all_word_size);
			HashMap<String,Integer> d = new HashMap<String,Integer>(words_map);
			//将子串和临时map进行比较
			for(int j=0;j<tmp.length();j+=one_word_size) {
				//从子串tmp中取出one_word_size长度的子串，看是否出现在临时map中
				//如果是就将临时map记录的频率-1，如果不在就跳出循环
				String key = tmp.substring(j,j+one_word_size);
				if(d.containsKey(key)) {
					d.put(key,d.get(key)-1);
					if(d.get(key)==0) {
						d.remove(key);
					}
				} else {
					break;
				}
			}
			//当内层循环遍历完后，如果临时map为空则表示全部匹配上了
			//记录数组的下标
			if(d.size()==0) {
				res.add(i);
			}
		}
		return res;
	}
}
```
```python []
class Solution(object):
	def findSubstring(self, s, words):
		"""
		:type s: str
		:type words: List[str]
		:rtype: List[int]
		"""
		if not s or len(s)==0 or not words or len(words)==0:
			return []
		# 将每个单词以及出现的频率记录到字典中	
		words_map,res = dict(),[]
		for i in words:
			if i not in words_map:
				words_map[i] = 1
			else:
				words_map[i] += 1
		one_word_size = len(words[0])
		all_words_size = len(words)*one_word_size
		for i in xrange(len(s)-all_words_size+1):
			# 每次取 all_words_size长度的子串
			tmp_str,d = s[i:i+all_words_size],dict(words_map)
			# 将子串和临时字典进行比较
			for j in xrange(0,len(tmp_str),one_word_size):
				# 从子串tmp_str中取出one_word_size长度的子串，看是否出现在临时字典中
				# 如果是就将临时字典记录的频率-1，如果不在就跳出循环
				key = tmp_str[j:j+one_word_size]
				if key in d:
					d[key] -= 1
					if d[key]==0:
					del d[key]
				else:
					break
			# 当内层循环遍历完后，如果临时字典为空则表示全部匹配上了
			# 记录数组的下标
			if not d:
				res.append(i)
		return res
```
(全文完)   
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)