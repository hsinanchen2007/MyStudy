
这个题是回溯法的题目，我在博客中已经总结了所有常见的算法模板，[【LeetCode】代码模板，刷题必会](https://blog.csdn.net/fuxuemingzhu/article/details/101900729)，直接拿来用！


判断回溯很简单，拿到一个问题，你感觉如果不穷举一下就没法知道答案，那就可以开始回溯了。

一般回溯的问题有三种：

1. Find a path to success 有没有解
1. Find all paths to success 求所有解
	- 求所有解的个数
	- 求所有解的具体信息
1. Find the best path to success 求最优解


回溯法是一个剪枝了的二叉树。我们要得到的结果是可以 good leaf，如果不满足 good leaf 就继续向下搜索，搜索的时候需要满足一定的条件。


![image.png](https://pic.leetcode-cn.com/a9944722e9307ade27ab98e36e3f29e4f5acd242007ae46c50e01ead122b9d45-image.png)

从上面的图片中我们可以很明显的看到，最后五条画黑线的就是最终的结果，其中左分支都是添加左括号，右分支都是添加右括号。

那么我们在什么情况下添加左括号呢？很明显，最多能添加 n 个左括号，在递归调用的时候，在能传递到最底层的共用字符串中先添加 `”(“` ，然后 left-1，递归调用就可以。

那什么时候添加右括号呢？当左括号个数大于右括号的个数时添加右括号。

总之，向下搜索要满足两个条件：

1. 插入数量不超过n
2. 可以插入 `）` 的前提是 `(` 的数量大于 `）`

**回溯法的代码套路**是使用两个变量： `res` 和 `path`，res 表示最终的结果，path 保存已经走过的路径。如果搜到一个状态满足题目要求，就把 path 放到 res 中。

代码后面的判断条件都是 if，而不是 elif，因为是满足两个条件的任意一个就可以继续向下搜索，而不是同时只能满足其中的一个。

Python代码如下：

```python
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []
        self.dfs(res, n, n, '')
        return res
        
    def dfs(self, res, left, right, path):
        if left == 0 and right == 0:
            res.append(path)
            return
        if left > 0:
            self.dfs(res, left - 1, right, path + '(')
        if left < right:
            self.dfs(res, left, right - 1, path + ')')
```

使用C++，基本结构和上面一样，不过这里 lc 和 rc 分别表示左括号的个数和右括号的个数。vector的push_back()方法调用的时候实际上是使用的值传递，也就是会进行赋值到vector里。

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int lc = 0, rc = 0;
        dfs(res, "", n, lc, rc);
        return res;
    }
    void dfs(vector<string>& res, string path, int n, int lc, int rc) {
        if (rc > lc || lc > n || rc > n) return;
        if (lc == rc && lc == n) {
            res.push_back(path);
            return;
        }
        dfs(res, path + '(', n, lc + 1, rc);
        dfs(res, path + ')', n, lc, rc + 1);
    }
};
```
