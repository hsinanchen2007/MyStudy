# 回溯解法
这道题的解法是用回溯的方式，在循环里面套了递归调用。本来递归就不好理解了，再加上循环的递归，就更难理解了。
我们先不考虑递归，先看看下面这个问题怎么解决。
假设输入是2，只有一个字符，那么应该怎么解呢？
按照题目要求2=“abc"，所以结果应该是```["a","b","c"]```
先不用想着怎么去写递归，只思考下怎么打印出这个结果。
这个太简单了，一个循环就搞定了：
```java
result = List()
for(i=0;i<len("abc");i++) {
    tmp = i
    result.add(tmp)
}
return result
```
上面是伪代码，一个循环就搞定了。
如果输入的是23，应该怎么做呢？23的结果是```["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]```，我们仍然不考虑怎么去写递归，只是考虑怎么把这个结果给弄出来。代码如下：
```java
result = List()
for(i=0;i<len("abc");i++) {
    for(j=0;j<len("def");j++)
        tmp = i+j
        result.add(tmp)
}
return result
```
也就是说23这样的长度为2的字符串可以用两层循环搞定。
如果输入的是234呢，仍然不要考虑怎么去写递归，而是想怎么把结果打印出来。
```java
result = List()
for(i=0;i<len("abc");i+=1) {
    for(j=0;j<len("def");j+=1) {
        for(k=0;k<len("ghi");k+=1) {
            tmp = i+j+k
            result.add(tmp)
        }
    }
}
return result
```
这次用了三层循环。
如果输入的是2345，那么代码可以这么写：
```java
result = List()
for(i=0;i<len("abc");i+=1) {
    for(j=0;j<len("def");j+=1) {
        for(k=0;k<len("ghi");k+=1) {
            for(n=0;n<len("jkl");n+=1)
                tmp = i+j+k+n
                result.add(tmp)
        }
    }
}
return result
```
这次是用了四层循环。现在是不是能看出一些门道了？对的。循环的嵌套层数，就是输入的字符串长度。输入的字符串长度是1，循环只有1层。
输入的字符串长度是3，循环就是3层。如果输入的字符串长度是10，那么循环就是10层。
可是输入的字符串长度是不固定的，对应的循环的嵌套层数也是不固定的，那这种情况怎么解决呢？这时候递归就派上用场了。
![1573822775(1).jpg](https://pic.leetcode-cn.com/7a77fa396e92c8ceb4e6fc1581aab7233fbf88606a05558aae29efdef2ebcb9c-1573822775\(1\).jpg)

对于打印"2345"这样的字符串：
第一次递归就是上图中最下面的方格，然后处理完第一个字符2之后，将输入的字符改变成"345"并调用第二个递归函数
第二次递归处理3，将字符串改变成"45"后再次递归
第三次递归处理4，将字符串改变成"5"后继续递归
第四次递归处理5，将字符串改变成""后继续递归
最后发现字符串为空了，将结果放到列表中并返回
上面是从函数调用的角度去看的，而每次调用下一层递归时，都需要将本层的一些处理结果放到一个临时变量中，再传递给下一层，从这个变量层层传递的变化看，就像一棵树一样，这个算法的时间复杂度很高，是O(3^n)这个级别的，空间复杂度是O(n)
![1573829897(1).jpg](https://pic.leetcode-cn.com/02b0ec926e3da5f12a0a118293b8ac10dc236741ccb04414ded44a30f7fc70af-1573829897\(1\).jpg)

动态图如下：
![递归动态图.gif](https://pic.leetcode-cn.com/9a86e75bd66edbecf7f11e10d501910ac7d64c5642050bc52d86e5a0eaa83fd5-%E9%80%92%E5%BD%92%E5%8A%A8%E6%80%81%E5%9B%BE.gif)


代码实现：
```java []
class Solution {
	//一个映射表，第二个位置是"abc“,第三个位置是"def"。。。
	//这里也可以用map，用数组可以更节省点内存
	String[] letter_map = {" ","*","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	public List<String> letterCombinations(String digits) {
		//注意边界条件
		if(digits==null || digits.length()==0) {
			return new ArrayList<>();
		}
		iterStr(digits, "", 0);
		return res;
	}
	//最终输出结果的list
	List<String> res = new ArrayList<>();
	
	//递归函数
	void iterStr(String str, String letter, int index) {
		//递归的终止条件，注意这里的终止条件看上去跟动态演示图有些不同，主要是做了点优化
		//动态图中是每次截取字符串的一部分，"234"，变成"23"，再变成"3"，最后变成""，这样性能不佳
		//而用index记录每次遍历到字符串的位置，这样性能更好
		if(index == str.length()) {
			res.add(letter);
			return;
		}
		//获取index位置的字符，假设输入的字符是"234"
		//第一次递归时index为0所以c=2，第二次index为1所以c=3，第三次c=4
		//subString每次都会生成新的字符串，而index则是取当前的一个字符，所以效率更高一点
		char c = str.charAt(index);
		//map_string的下表是从0开始一直到9， c-'0'就可以取到相对的数组下标位置
		//比如c=2时候，2-'0'，获取下标为2,letter_map[2]就是"abc"
		int pos = c - '0';
		String map_string = letter_map[pos];
		//遍历字符串，比如第一次得到的是2，页就是遍历"abc"
		for(int i=0;i<map_string.length();i++) {
			//调用下一层递归，用文字很难描述，请配合动态图理解
			iterStr(str, letter+map_string.charAt(i), index+1);
		}
	}
}
```
```python []
class Solution(object):
	def letterCombinations(self, digits):
		"""
		:type digits: str
		:rtype: List[str]
		"""
		# 注意边界条件
		if not digits:
			return []
		# 一个映射表，第二个位置是"abc“,第三个位置是"def"。。。
		# 这里也可以用map，用数组可以更节省点内存
		d = [" ","*","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
		# 最终输出结果的list
		res = []
		
		# 递归函数
		def dfs(tmp,index):
			# 递归的终止条件，注意这里的终止条件看上去跟动态演示图有些不同，主要是做了点优化
			# 动态图中是每次截取字符串的一部分，"234"，变成"23"，再变成"3"，最后变成""，这样性能不佳
			# 而用index记录每次遍历到字符串的位置，这样性能更好
			if index==len(digits):
				res.append(tmp)
				return
			# 获取index位置的字符，假设输入的字符是"234"
			# 第一次递归时index为0所以c=2，第二次index为1所以c=3，第三次c=4
			# subString每次都会生成新的字符串，而index则是取当前的一个字符，所以效率更高一点
			c = digits[index]
			# map_string的下表是从0开始一直到9， ord(c)-48 是获取c的ASCII码然后-48,48是0的ASCII
			# 比如c=2时候，2-'0'，获取下标为2,letter_map[2]就是"abc"
			letters = d[ord(c)-48]
			
			# 遍历字符串，比如第一次得到的是2，页就是遍历"abc"
			for i in letters:
				# 调用下一层递归，用文字很难描述，请配合动态图理解
				dfs(tmp+i,index+1)
		dfs("",0)
		return res
```
   
   
   
# 利用队列求解

我们可以利用队列的先进先出特点，再配合循环完成题目要求。
我们先将2对应的字符"a","b","c"依次放入队列中
![队列-1.jpg](https://pic.leetcode-cn.com/18b4155eb5122b9e177a29c7320de89048b74cc5553632700a45e07aa92057bc-%E9%98%9F%E5%88%97-1.jpg)

之后再从队列中拿出第一个元素"a"，跟3对应的字符"d","e","f"挨个拼接
![队列-1.jpg](https://pic.leetcode-cn.com/5d331f111c4bc5439116bc412a57e1271f0e1997b1328009cedce5152bce292f-%E9%98%9F%E5%88%97-1.jpg)

于是队列就变成了下面这个样子：
![队列-3.jpg](https://pic.leetcode-cn.com/89f52c9185b736edec7e980db7cf1a9897d5efbf1e80e1d19296ee48917fdfb9-%E9%98%9F%E5%88%97-3.jpg)

按照同样的方式，再将"b"从队列中拿出，再跟3对应的字符"d","e","f"挨个拼接，队列又变成下面这个样子：
![队列-4.jpg](https://pic.leetcode-cn.com/7fbe1e06dc207dbc539c7f580698eaad845ae5ff913b1b048211355a72fb3bcb-%E9%98%9F%E5%88%97-4.jpg)

动态演示如下：
![队列-动态图.gif](https://pic.leetcode-cn.com/6953e7a27bff1242c37f88c9b66b524975655605d053a9f6ac6a74376582b4c5-%E9%98%9F%E5%88%97-%E5%8A%A8%E6%80%81%E5%9B%BE.gif)


代码实现：
```java []
class Solution {
	public List<String> letterCombinations(String digits) {
		if(digits==null || digits.length()==0) {
			return new ArrayList<String>();
		}
		//一个映射表，第二个位置是"abc“,第三个位置是"def"。。。
		//这里也可以用map，用数组可以更节省点内存
		String[] letter_map = {
			" ","*","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
		};
		List<String> res = new ArrayList<>();
		//先往队列中加入一个空字符
		res.add("");
		for(int i=0;i<digits.length();i++) {
			//由当前遍历到的字符，取字典表中查找对应的字符串
			String letters = letter_map[digits.charAt(i)-'0'];
			int size = res.size();
			//计算出队列长度后，将队列中的每个元素挨个拿出来
			for(int j=0;j<size;j++) {
				//每次都从队列中拿出第一个元素
				String tmp = res.remove(0);
				//然后跟"def"这样的字符串拼接，并再次放到队列中
				for(int k=0;k<letters.length();k++) {
					res.add(tmp+letters.charAt(k));
				}
			}
		}
		return res;
	}
}
```
```python []
class Solution(object):
	def letterCombinations(self, digits):
		"""
		:type digits: str
		:rtype: List[str]
		"""	
		if not digits:
			return []
		# 一个映射表，第二个位置是"abc“,第三个位置是"def"。。。
		# 这里也可以用map，用数组可以更节省点内存
		d = [" ","*","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
		# 先往队列中加入一个空字符
		res = [""]
		for i in digits:
			size = len(res)
			# 由当前遍历到的字符，取字典表中查找对应的字符串
			letters = d[ord(i)-48]
			# 计算出队列长度后，将队列中的每个元素挨个拿出来
			for _ in xrange(size):
				# 每次都从队列中拿出第一个元素
				tmp = res.pop(0)
				# 然后跟"def"这样的字符串拼接，并再次放到队列中
				for j in letters:
					res.append(tmp+j)
		return res
```
(全文完)   
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)