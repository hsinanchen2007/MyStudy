**思路**:很明显核心问题是列表的扁平化 题目中是有一个自定义的类型 我们可以先考虑一下例如[1,[2,3]]这种已有的类型然后再拓展 再者扁平化其实类似于常见的括号的有效匹配问题 所以可以考虑栈和递归的解决方案
**注意**:我会先给参数为嵌套list的两种解法 最后再以递归方法给一个该题完整的代码 本人菜鸡 还请大家多多指教

# 一.递归(rtype是generator)
```
def flatten(lst):
    for i in lst:
        try:
            yield from flatten(i) #yield from flatten(i+[])更好理解 首先需要明确递归有一种树状结构 两者的区别在于前者try-except捕获的是下一层未处理的异常 而后者捕获的就是本层的异常 可以用一个简单的例子理解一下(※其实前者也是我无意中整出来的 后来理解了一会))
        except TypeError:
            yield i
```

# 二.栈(rtype是list)
```
def flatten(lst):
    ans,stack=[],[lst]
    while stack:
        cur=stack.pop()
        for i,j in enumerate(cur,1):
            try:
                ans.append(j+0)
            except TypeError:
                stack[len(stack):len(stack)]=[cur[i:],j] #或者extend([cur[i:],j])这样也是可以的 关键就是把还没处理的部分加入到栈中
                break
    return ans
```

# 三.递归法的完整代码(flatten函数有一定的变化 但是根本思想是一样的)
```
class NestedIterator:
	def __init__(self,nestedList):
		def flatten(nestedList):
			if not nestedList: #普通的嵌套list会因为数字不能迭代报错 这边就手动报错
				raise TypeError
			for i in nestedList:
				try:
					yield from flatten(i.getList())
				except TypeError:
					if i.getInteger() is not None: #[]的时候i.getInteger()会返回None 但None是不需要的
						yield i.getInteger()
		self.gen=flatten(nestedList)
		self.prev=None #预读一个数字
	def next(self):
		if self.prev is not None:
			ans,self.prev=self.prev,None
			return ans
		return next(self.gen)
	def hasNext(self):
		if self.prev is not None:
			return True
		try:
			self.prev=next(self.gen)
			return True
		except (StopIteration,TypeError): #一般来说只要StopIteration TypeError是为了应对[[]],[]...这种特殊情况
			return False
```

