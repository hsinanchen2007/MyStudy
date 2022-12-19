#### 一、热身

第一步，我们暂时不管正则符号，如果是两个普通的字符串进行比较，如何进行匹配？我想这个算法应该谁都会写：

```cpp [-C++]
bool isMatch(string text, string pattern) {
    if (text.size() != pattern.size()) 
        return false;
    for (int j = 0; j < pattern.size(); j++) {
        if (pattern[j] != text[j])
            return false;
    }
    return true;
}
```

然后，我稍微改造一下上面的代码，略微复杂了一点，但意思还是一样的，很容易理解吧：

```cpp [-C++]
bool isMatch(string text, string pattern) {
    int i = 0; // text 的索引位置
    int j = 0; // pattern 的索引位置
    while (j < pattern.size()) {
        if (i >= text.size()) 
            return false;
        if (pattern[j++] != text[i++])
            return false;
    }
    // 判断 pattern 和 text 是否一样长
    return j == text.size();
}
```

如上改写，是为了将这个算法改造成递归算法（伪码）：

```python [-Python]
def isMatch(text, pattern) -> bool:
    if pattern is empty: return text is empty
    first_match = (text not empty) and pattern[0] == text[0]
    return first_match and isMatch(text[1:], pattern[1:])
}
```

如果你能够理解这段代码，恭喜你，你的递归思想已经到位，正则表达式算法虽然有点复杂，其实是基于这段递归代码逐步改造而成的。

#### 二、处理点号「.」通配符

点号可以匹配任意一个字符，万金油嘛，其实是最简单的，修改上面的伪码，再稍加改造即可：

```python [-Python]
def isMatch(text, pattern) -> bool:
    if not pattern: return not text
    first_match = bool(text) and pattern[0] in {text[0], '.'}
    return first_match and isMatch(text[1:], pattern[1:])
```

### 三、处理「*」通配符

星号通配符可以让前一个字符重复任意次数，包括零次。那到底是重复几次呢？这似乎有点困难，不过不要着急，我们起码可以把框架的搭建再进一步：

```python [-Python]
def isMatch(text, pattern) -> bool:
    if not pattern: return not text
    first_match = bool(text) and pattern[0] in {text[0], '.'}
    if len(pattern) >= 2 and pattern[1] == '*':
        # 发现 '*' 通配符
    else:
        return first_match and isMatch(text[1:], pattern[1:])
```

星号前面的那个字符到底要重复几次呢？这需要计算机暴力穷举来算，假设重复 N 次吧。前文多次强调过，写递归的技巧是管好当下，之后的事抛给递归。具体到这里，不管 N 是多少，当前的选择只有两个：匹配 0 次、匹配 1 次。所以可以这样处理：

```py [-Python]
if len(pattern) >= 2 and pattern[1] == '*':
    return isMatch(text, pattern[2:]) or \
            first_match and isMatch(text[1:], pattern)
# 解释：如果发现有字符和 '*' 结合，
    # 或者匹配该字符 0 次，然后跳过该字符和 '*'
    # 或者当 pattern[0] 和 text[0] 匹配后，移动 text
```
可以看到，我们是通过保留 pattern 中的「\*」，同时向后推移 text，来实现「\*」将字符重复匹配多次的功能。举个简单的例子就能理解这个逻辑了。假设 pattern = a*, text = aaa，画个图看看匹配过程：

![无效的图片地址](https://pic.leetcode-cn.com/7c933f57e4f71c61a9bb4eb5d80c6f54373a3787b2c17255e3cefba4ecd06ed6-file_1560139042317){:width=350}
{:align=center}

至此，正则表达式算法就基本完成了，

#### 四、动态规划

我选择使用「备忘录」递归的方法来降低复杂度。有了暴力解法，优化的过程及其简单，就是使用两个变量 `i`, `j` 记录当前匹配到的位置，从而避免使用子字符串切片，并且将 `i`, `j` 存入备忘录，避免重复计算即可。

我将暴力解法和优化解法放在一起，方便你对比，你可以发现优化解法无非就是把暴力解法「翻译」了一遍，加了个 memo 作为备忘录，仅此而已。

```py [-Python]
# 带备忘录的递归
def isMatch(text, pattern) -> bool:
    memo = dict() # 备忘录
    def dp(i, j):
        if (i, j) in memo: return memo[(i, j)]
        if j == len(pattern): return i == len(text)

        first = i < len(text) and pattern[j] in {text[i], '.'}
        
        if j <= len(pattern) - 2 and pattern[j + 1] == '*':
            ans = dp(i, j + 2) or \
                    first and dp(i + 1, j)
        else:
            ans = first and dp(i + 1, j + 1)
            
        memo[(i, j)] = ans
        return ans
    
    return dp(0, 0)

# 暴力递归
def isMatch(text, pattern) -> bool:
    if not pattern: return not text

    first = bool(text) and pattern[0] in {text[0], '.'}

    if len(pattern) >= 2 and pattern[1] == '*':
        return isMatch(text, pattern[2:]) or \
                first and isMatch(text[1:], pattern)
    else:
        return first and isMatch(text[1:], pattern[1:])
```

有的读者也许会问，__你怎么知道这个问题是个动态规划问题呢，你怎么知道它就存在「重叠子问题」呢，这似乎不容易看出来呀？__

解答这个问题，最直观的应该是随便假设一个输入，然后画递归树，肯定是可以发现相同节点的。这属于定量分析，其实不用这么麻烦，下面我来教你定性分析，一眼就能看出「重叠子问题」性质。

先拿最简单的斐波那契数列举例，我们抽象出递归算法的框架：

```py [-Python]
def fib(n):
    fib(n - 1)
    fib(n - 2)
```

看着这个框架，请问原问题 $f(n)$，如何触达子问题 $f(n - 2)$？有两种路径，一是 `f(n) -> f(n-1) -> f(n - 1 - 1)`, 二是 `f(n) -> f(n - 2)`。前者经过两次递归，后者进过一次递归而已。两条不同的计算路径都到达了同一个问题，这就是「重叠子问题」，而且可以肯定的是，只要你发现一条重复路径，这样的重复路径一定存在千万条，意味着巨量子问题重叠。

同理，对于本问题，我们依然先抽象出算法框架：

```py [-Python]
def dp(i, j):
    dp(i, j + 2)     #1
    dp(i + 1, j)     #2
    dp(i + 1, j + 1) #3
```

提出类似的问题，请问如何从原问题 $dp(i, j)$，触达子问题 $dp(i + 2, j + 2)$？至少有两种路径，一是 `dp(i, j) -> #3 -> #3`，二是 `dp(i, j) -> #1 -> #2 -> #2`。因此，本问题一定存在重叠子问题，一定需要动态规划的优化技巧来处理。

#### 五、最后总结

通过本文，你深入理解了正则表达式的两种常用通配符的算法实现。其实点号「.」的实现及其简单，关键是星号「*」的实现需要用到动态规划技巧，稍微复杂些，但是也架不住我们对问题的层层拆解，逐个击破。另外，你掌握了一种快速分析「重叠子问题」性质的技巧，可以快速判断一个问题是否可以使用动态规划套路解决。

回顾整个解题过程，你应该能够体会到算法设计的流程：从简单的类似问题入手，给基本的框架逐渐组装新的逻辑，最终成为一个比较复杂、精巧的算法。所以说，读者不必畏惧一些比较复杂的算法问题，多思考多类比，再高大上的算法在你眼里也不过一个脆皮。


**推荐阅读：**

[KMP 算法详解](https://leetcode-cn.com/problems/implement-strstr/solution/kmp-suan-fa-xiang-jie-by-labuladong/)

[动态规划方法解决博弈问题](https://leetcode-cn.com/problems/stone-game/solution/jie-jue-bo-yi-wen-ti-de-dong-tai-gui-hua-tong-yong/)

[腾讯面试题详解：编辑距离](https://leetcode-cn.com/problems/edit-distance/solution/bian-ji-ju-chi-mian-shi-ti-xiang-jie-by-labuladong/)

最后，点击我的头像可以查看更多详细题解，希望读者多多点赞，让我感受到你的认可～


PS：**我的所有算法文章都已经上传到了 Github 仓库**：[**fucking-algorithm**](https://github.com/labuladong/fucking-algorithm)，共 60 多篇，绝对精品，肯定让你收获满满，**求个 star 不过分吧**～

PPS：我最近精心制作了一份电子书《labuladong的算法小抄》，分为「动态规划」「数据结构」「算法思维」「高频面试」四个章节，目录如下，限时开放下载，如有需要可扫码到我的公众号 **labuladong** 后台回复关键词「pdf」下载：

![目录](https://pic.leetcode-cn.com/66b9e7466b8c493b67a709f3ebd87c88daa7ca0b85d960288dec10aff8c7fc3e.jpg){:width=500}
{:align=center}
