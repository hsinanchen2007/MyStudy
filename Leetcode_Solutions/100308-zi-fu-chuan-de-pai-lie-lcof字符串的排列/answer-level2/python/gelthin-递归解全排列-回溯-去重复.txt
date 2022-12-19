### 解题思路

#### 1. 使用递归方法，不是回溯法。
这里效率比较低，大量重复子问题, 选 b 和 c  与 选 c 和 b 的子问题是一样的，但都要重复求解。
代码好写。
需要用 set 去重。

#### 2. 回溯法
参见题解 [回溯，使用set去重](https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/solution/hui-su-shi-yong-setqu-zhong-by-wonderwall-2/)
效率我不会分析，不知道是不是比递归快一些。感觉和递归效率一样。也在大量重复求解子问题。
仍然要用 set 去重。

#### 3. [回溯法并进行去重复](https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/solution/hui-su-fa-by-luo-jing-yu-yu/)


#### 4. 交换法，这个方法比较强。待学习。


```
*
 * 回溯法
 *
 * 字符串的排列和数字的排列都属于回溯的经典问题
 *
 * 回溯算法框架：解决一个问题，实际上就是一个决策树的遍历过程：
 * 1. 路径：做出的选择
 * 2. 选择列表：当前可以做的选择
 * 3. 结束条件：到达决策树底层，无法再做选择的条件
 *
 * 伪代码：
 * result = []
 * def backtrack(路径，选择列表):
 *     if 满足结束条件：
 *         result.add(路径)
 *         return
 *     for 选择 in 选择列表:
 *         做选择
 *         backtrack(路径，选择列表)
 *         撤销选择
 *
 * 核心是for循环中的递归，在递归调用之前“做选择”，
 * 在递归调用之后“撤销选择”。
 *
 * 字符串的排列可以抽象为一棵决策树：
 *                       [ ]
 *          [a]          [b]         [c]
 *      [ab]   [ac]  [bc]   [ba]  [ca]  [cb]
 *     [abc]  [acb] [bca]  [bac]  [cab] [cba]
 *
 * 考虑字符重复情况：
 *                       [ ]
 *          [a]          [a]         [c]
 *      [aa]   [ac]  [ac]   [aa]  [ca]  [ca]
 *     [aac]  [aca] [aca]  [aac]  [caa] [caa]
 *
 * 字符串在做排列时，等于从a字符开始，对决策树进行遍历，
 * "a"就是路径，"b""c"是"a"的选择列表，"ab"和"ac"就是做出的选择，
 * “结束条件”是遍历到树的底层，此处为选择列表为空。
 *
 * 本题定义backtrack函数像一个指针，在树上遍历，
 * 同时维护每个点的属性，每当走到树的底层，其“路径”就是一个全排列。
 * 当字符出现重复，且重复位置不一定时，需要先对字符串进行排序，
 * 再对字符串进行“去重”处理，之后按照回溯框架即可。
 * */
```


[我关于去重的理解](https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/solution/hui-su-fa-by-luo-jing-yu-yu/307947)

这里可以这么理解, 对于 aab, 记为 "a1a2b", 为了保证不出现重复，我们可以规定一个顺序，当我们需要使用字符 a 的时候，必须先用字符 a1, 后再用字符 a2； 或者当我们需要使用字符 a 时，必须先用字符a2, 后用字符 a1. 这样就是要保证在生成的字符串排列中不会因为 a1 和 a2 的位置发生对换，而产生新的重复的字符串。

我们可以有以下两种方式：
+ a1a2b, a1ba2, ba1a2 # 对应 !visit[i-1]
+ a2a1b, a2ba1, ba2a1 # 对应 visit[i-1]

这里解释似乎不对，!visit[i-1] 和 visit[i-1] 都是对应 a1a2b, a1ba2, ba1a2.
考虑到 for 循环都是从左到右遍历的, s[i-1] == s[i] 也是和左边比较。
如果和右边比较才有， a2a1b, a2ba1, ba2a1 的可能。

似乎没有错，当使用 visit[i-1]时，若第一次取了 a1, 那么 a2 不会被取，最终循环会被终结。不会进入更深的 dfs



这里对于三重复 aaab, 也是成立的。



#### 回溯法去重的代码

```python3
class Solution:
    def permutation(self, s: str) -> List[str]:
        def dfs(tmp):
            if len(tmp) == len(s):
                res.append(tmp)
            
            for i in range(len(s)):
                if i>0 and s[i-1]==s[i] and not visited[i-1]:  # 当 s[i-1] 还没有被访问过
                    continue
                elif not visited[i]:
                    visited[i] = True
                    dfs(tmp+s[i])
                    visited[i] = False

        s = sorted(list(s))  # 先排序然后去重
        visited = [False]*len(s)
        res = []
        dfs("")
        return res
```

### 代码

```python3
class Solution:
    def permutation(self, s: str) -> List[str]:
        if len(s) == 1:
            return [s]
        res = []
        for i in range(len(s)):
            rest = s[:i] + s[i+1:]
            for t in self.permutation(rest):
                res.append(s[i]+t)
        return list(set(res))  # 用set 去重，不然 “aabc” 过不去
```

#### 回溯法，采用一个 visited 数组标记是否访问过

```python3
class Solution:
    def permutation(self, s: str) -> List[str]:
        def dfs(tmp):
            if len(tmp) == len(s):
                res.append(tmp)
            
            for i in range(len(s)):
                if not visited[i]:
                    visited[i] = True
                    dfs(tmp+s[i])
                    visited[i] = False

        visited = [False]*len(s)
        res = []
        dfs("")
        return list(set(res))     
```