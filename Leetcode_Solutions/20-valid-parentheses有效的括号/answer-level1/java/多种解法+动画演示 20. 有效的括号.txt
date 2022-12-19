# 栈实现
这个简单，用一个栈来保存```(```，```[```,```{```
当遍历到这三个字符的时候，就将其保存到栈中。
如果遍历到的是```)```就从栈中弹出一个元素，检查是否能跟```)```配对
如果遍历到的是```]```就从栈中弹出一个元素，检查是否能跟```]```配对
如果遍历到的是```}```就从栈中弹出一个元素，检查是否能跟```}```配对
怎么配对呢？
这里用一个map来存储，key和value分别如下：
```)``` ：```(```
```]``` ：```[```
```}``` ：```{```
如果遍历到的是)，就可以从map中找到对应的value是(，再跟栈中弹出的元素对比就可以了。   
![222.gif](https://pic.leetcode-cn.com/ad81170ca2d72c323be7b9af3d5a326899380843a4551729a8812fcb0b705ee1-222.gif)


代码实现: 
```java []
class Solution {
    public boolean isValid(String s) {
		if(s==null || "".equals(s)) {
			return true;
		}
		//用栈保存 (，[，{
		Stack<Character> stack = new Stack<Character>();
		//map中保存的是 ):(, ]:[,}:{
		//当遍历到 )时候就会去map中找对应的value，也就是(
		//再用这个value和stack弹出的元素比较，如果相等则匹配上，不等则返回false
		//这里也可以用数组来存，我为了简单就用map表示了
		HashMap<Character,Character> map = new HashMap<Character,Character>();
		map.put(')','(');
		map.put(']','[');
		map.put('}','{');
		for(int i=0;i<s.length();i++) {
			char c = s.charAt(i);
			//如果map中不包含 (,[,{，就将这个字符放入栈中
			if(!map.containsKey(c)) {
				stack.add(c);
			} else {
				//如果遍历的字符不再map中，也就是说这个字符是),],}，那么就要跟栈中的元素比较
				//首先要判断栈是否为空，如果输入的字符是 )() ，那么当遍历到第一个)时，栈为空
				if(stack.size()==0) {
					return false;
				}
				//取出栈顶的元素
				Character tmp = stack.pop();
				//假设当前遍历到的元素是 ]，那么从map中取到的value就是 [
				//如果栈顶的元素是 (，则不匹配返回false，否则继续
				if(map.get(c)!=tmp) {
					return false;
				}
			}
		}
		//返回的时候还要判断栈是否为空
		//如果输入的字符串是 (((，那么最后栈就不为空
		return (stack.empty()? true : false);
    }
}
```
```python []
class Solution(object):
	def isValid(self, s):
		"""
		:type s: str
		:rtype: bool
		"""
		if not s:
			return True
		# 用栈保存 (，[，{
		stack = []
		# map中保存的是 ):(, ]:[,}:{
		# 当遍历到 )时候就会去map中找对应的value，也就是(
		# 再用这个value和stack弹出的元素比较，如果相等则匹配上，不等则返回false
		# 这里也可以用数组来存，我为了简单就用map表示了
		d = {")":"(", "]":"[","}":"{"}
		# 开始遍历字符串
		for i in s:
			# 如果map中不包含 (,[,{，就将这个字符放入栈中
			if i not in d:
				stack.append(i)
			else:
				# 如果遍历的字符不再map中，也就是说这个字符是),],}，那么就要跟栈中的元素比较
				# 首先要判断栈是否为空，如果输入的字符是 )() ，那么当遍历到第一个)时，栈为空
				if not stack:
					return False
				# 取出栈顶的元素	
				tmp = stack.pop()
				# 假设当前遍历到的元素是 ]，那么从map中取到的value就是 [
				# 如果栈顶的元素是 (，则不匹配返回false，否则继续
				if d[i]!=tmp:
					return False
		# 返回的时候还要判断栈是否为空
		# 如果输入的字符串是 (((，那么最后栈就不为空
		return True if not stack else False
```
   
   
   
# 字符串替换方式
假设输入的字符串是:   
```(([[{}]]))```
如果字符串是有效的，不管是嵌套结构，还是非嵌套结构，最里面肯定有一对括号是配对的，不是```()```，就是```[]```，或者是```{}```      
然后我们就将```{}```替换成```""```   
于是字符串就变成了```(([[]]))```      
重复这个逻辑，再不断的替换```[]```，将其改为""    
再将```()```替换为""   
最终全部替换完，得到的就是一个"" 空字符串。   
![111.gif](https://pic.leetcode-cn.com/474e6a38813b9c3912ef2884ff0f95f022505354f94b478f8156d34d9bf147fa-111.gif)
   


代码实现：
```java []
class Solution {
	public boolean isValid(String s) {
		if(s==null || "".equals(s)) {
			return true;
		}
		//循环判断的条件是，字符串是否包含 (),[],{}
		//不管是单层次的()[]{}，还是嵌套的 ((([[{}]])))
		//如果字符串是合法的，一定会包含一个最基本的括号对 ()，[]或者{}
		while(s.contains("()") || s.contains("[]") || s.contains("{}")) {
			//假设输入的字符是((()))，第一次替换完字符串就变成了(())
			//第二次替换变成()，第三次就是""
			if(s.contains("()")) {
				s = s.replaceAll("\\(\\)","");
			}
			//对于嵌套包含也是一样，([{}])
			//第一次会被替换成([])，第二次替换成()，第三次是""
			if(s.contains("[]")) {
				s = s.replaceAll("\\[\\]","");
			}
			if(s.contains("{}")) {
				s = s.replaceAll("\\{\\}","");
			}
		}
		//如果输入的字符串是合法的，经过不断替换最终就会变成""
		//如果不合法，肯定就不为空
		return "".equals(s)? true : false;
	}
}
```
```python []
class Solution(object):
	def isValid(self, s):
		"""
		:type s: str
		:rtype: bool
		"""
		if not s:
			return True
		# 循环判断的条件是，字符串是否包含 (),[],{}
		# 不管是单层次的()[]{}，还是嵌套的 ((([[{}]])))
		# 如果字符串是合法的，一定会包含一个最基本的括号对 ()，[]或者{}
		while s.find("()")>-1 or s.find("[]")>-1 or s.find("{}")>-1:
			# 假设输入的字符是((()))，第一次替换完字符串就变成了(())
			# 第二次替换变成()，第三次就是""
			if s.find("()")>-1:
				s = s.replace("()","")
			# 对于嵌套包含也是一样，([{}])
			# 第一次会被替换成([])，第二次替换成()，第三次是""
			if s.find("[]")>-1:
				s = s.replace("[]","")
			if s.find("{}")>-1:
				s = s.replace("{}","")
		# 如果输入的字符串是合法的，经过不断替换最终就会变成""
		# 如果不合法，肯定就不为空
		return True if not s else False
```
(全文完)
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)