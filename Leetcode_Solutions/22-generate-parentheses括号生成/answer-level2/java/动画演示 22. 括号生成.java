# 回溯解法
回溯算法一开始并不容易想到，那我们就从简单的伪代码开始，再一点点的往里面加东西。
首先生成一个左括号，当然这是死循环：   
```java
void generate(tmp):
	generate(tmp+"(")
```
当我们输入3时候，实际一共要生成6个括号，3个左括号，3个右括号,再修改下代码，根据n来判断，
```java
void generate(n,tmp):
	if n==括号数量*2:
		result.add(tmp)
		return
	generate(tmp+"(")
```
上面的代码光输出个左括号看着就不对，那就再补一个右括号：
```java
void generate(n,tmp):
	if n==括号数量*2:
		result.add(tmp)
		return
	generate(tmp+"(")
	generate(tmp+")")
```
上面的代码基本上把一个框架给弄出来了，但很遗憾结果还是不对。
上面那段代码输出的结果是：   
```["((((","((()","(()(","(())","()((","()()","())(","()))",")(((",")(()",")()(",")())","))((","))()",")))(","))))"]```
输出的内容大部分都是不合法的，所以我们需要在上面那个模板代码基础上做一些修改。
先看下那段模板代码的执行调用过程：
![生成树.jpg](https://pic.leetcode-cn.com/d0116b14df1d82a4d4a914509e9dcf03dca4be69b5a097c7fcaa96097bf97103-%E7%94%9F%E6%88%90%E6%A0%91.jpg)

一共会生成16个叶子节点，这里只列出了8个，因为我的电脑屏幕太小已经画不下了。。。
其中很多节点一眼看过去就不合法，比如根节点的右子树，是)开头的，这明显就不合法，所以我们需要剪枝，将一些不合法的节点去掉：
![剪枝.jpg](https://pic.leetcode-cn.com/496491da38dad1f8230ea43b8de27b85777b769252b9f246feeca9299704c8b3-%E5%89%AA%E6%9E%9D.jpg)

根据上图就很好理解了，最终递归函数返回时候的判断应该是：
1. 左节点的数量==输入的参数n
2. 右节点的数量==输入的参数n 
    
同时在做递归的时候，需要这么判断：
1. 左括号的数量<输入的参数
2. 同时右节点的数量<输入的参数
3. 左括号的数量>右括号的数量
   
对于第三个条件可以这么理解：剪枝那副图中根节点的右子树，它先生成了)，这也是不合理的。   
每次生成括号的时候，应该先生成(，再生成)，左括号始终是要先生成，而当左括号的数量<输入的参数n时，就停止生成，所以左括号的数量应该是 > 右括号的数量。     
动态图如下：
![动态图.gif](https://pic.leetcode-cn.com/89828d1a1b06ea7cb2bba618b29122ae5b474c81a5efcd307119cea86415c094-%E5%8A%A8%E6%80%81%E5%9B%BE.gif)


代码实现：
```java []
class Solution {
	public List<String> generateParenthesis(int n) {
		dfs(0,0,"",n);
		return res;
	}
	
	List<String> res = new ArrayList<String>();
	//递归函数
	void dfs(int left,int right,String tmp,int n) {
		//递归函数的终止条件
		if(left==n && right==n) {
			res.add(tmp);
			return;
		}
		//注意左括号的数量要小于参数n，即输入的n为3时
		//最多只能生成3个左括号
		if(left<n) {
			dfs(left+1,right,tmp+"(",n);
		}
		//右括号的数量也要小于n，左括号的数量要 大于 右括号数量
		//因为 ((( 是合法的(假设程序还没处理完)
		//而),)),)))都是不合法的
		if(left>right && right<n) {
			dfs(left,right+1,tmp+")",n);
		}
	}
}
```
```python []
class Solution(object):
	def generateParenthesis(self, n):
		"""
		:type n: int
		:rtype: List[str]
		"""
		res = []
		# 递归函数
		def dfs(left,right,tmp):
			# 递归函数的终止条件
			if left==n and right==n:
				res.append(tmp)
				return
			# 注意左括号的数量要小于参数n，即输入的n为3时
			# 最多只能生成3个左括号
			if left<n:
				dfs(left+1,right,tmp+"(")
			# 右括号的数量也要小于n，左括号的数量要 大于 右括号数量
			# 因为 ((( 是合法的(假设程序还没处理完)
			# 而),)),)))都是不合法的
			if left>right and right<n:
				dfs(left,right+1,tmp+")")
		dfs(0,0,"")
		return res
```
(全文完)   
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)