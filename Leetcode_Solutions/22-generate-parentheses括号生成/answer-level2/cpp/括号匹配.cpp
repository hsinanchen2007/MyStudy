### 解题思路
从最开始就想用递归作，但是一直找不到递归出口。最后最认同回溯法（DFS）的方法；

回溯法想的是用一个string 变量暂存当前括号搭配，考虑当前剩余需要搭配的左括号和右括号数进行添加**''('' ** 或者 **'')''** 最后n对括号都使用完毕时，回溯，加入vector；

回溯像是在画一棵树，这棵树每次有两个选择。

+ 1、在L<N的时候可以直接添加左括号
+ 2、在L<R的时候可以直接添加右括号

在这样的情况下，为当前括号组合cur 进行添加 ( 或者  )  然后每种情况进行回溯：（消除刚刚添加的字符）.

也可以直接在迭代时，cur传入时不进行引用，直接传入cur+‘（’ 作为参数。

### 代码

```python3
class Solution:
    def generateParenthesis(self, n) -> List[str]:
        self.ans = []
        self.Iter('', n, n)
        return self.ans

    def Iter(self, str1, r, l):
        if r == 0 and l == 0:
            self.ans.append(str1)
        if l > 0:
            self.Iter(str1+'(',r,l-1)
        if l<r:
            self.Iter(str1+')',r-1,l)

```

C++
```
class Solution {
public:
	vector<string> str;
	vector<string> generateParenthesis(int n) {
		dfs(0, 0, n, "");
		return str;
	}
	void dfs(int l, int r, int n, string cur)
	{
		if (l == n && r == n)
			str.push_back(cur);
		if (l < n)
			dfs(l + 1, r, n, cur+'(');
		if (l > r)
			dfs(l, r + 1, n, cur+')');
	}
};
```