![image.png](https://pic.leetcode-cn.com/d784abe5beeb098999c546a130e896617a267683955dad2fab27dd616180ea03-image.png)

![image.png](https://pic.leetcode-cn.com/79c5b3b22225d6916ef6033fed83a5cc23b17e544f0e9bc2cb48e046d2d11857-image.png)

方法选对了，Python也不见得这么慢。

核心思想就是把字符串看成路径，生成存在重边的有向图中更多最小环，交换次数为环的周长$-1$，所有环的周长$-1$之和就是总的交换次数。

目前各个解题报告给出的都是宽搜BFS的解法，看来这个解题方法对于这类问题应该是首创。






下面具体介绍一下这个方法：

比如用例:

```py
"aababcabcd"
"ababcabcda"
```

我们按长度把这个10个长度的串分成4组，分别是$"a""a","ab""ba"，"abc""bca"，"abcd""bcda"$

```py
"a ab abc abcd"
 ↓ ↓  ↓   ↓
"a ba bca bcda"
```
每组子串看成一个有向图的边集合，相同序号的字母一一对应。

第一组子串，$"a""a"$看成$a→a$，就是一个自环$(a)$，环的周长为$1$，交换次数$+0$。

第二组子串，$"ab""ba"$看成路径$a→b，b→a$，那$(a,b)$就是一个周长为$2$的环，所以交换次数$+1$。

第三组子串，$"abc""bca"$看成路径$a→b，b→c，c→a$，那$(a,b,c)$就是一个周长为$3$的环，交换次数$+2$。

第四组子串，$"abcd""bcda"$看成路径$a→b，b→c，c→d，d→a$，那$(a,b,c,d)$就是一个周长为$4$的环，交换次数$+3$。

所以这个用例的总交换次数为$0+1+2+3=6$。

从上述的例子可以看出，两组字符串，只有刚好错位的时候，才会出现最大的交换次数。

而这种刚好错位在图里面就是一个环，若周长为$n$，交换次数则为$n-1$，也就是$6$个字母的串最多交换$5$次。

如果是全字母表长度为$n$的串，最多交换$n//26\times25 + (n\%26)\times(n\%26-1)$次。

可以找出图里面的所有最小环，生成的最小环越多，就越接近最少的分配次数。

所以在遍历图的时候需要用到深度优先遍历，且按遍历的最深深度由$2$到$3$一直到$6$，如果一个图所有有向边恰好生成的都是长度为$2$的环，就不用继续往大的环生成了。

而在实际操作中，并不一定能保证一定能在某层生成最多最小的环。

比如某官方测试用例：

```py
"abcdefabcdefabcdef"
"acccafdeaddbbefbef"
```

在生成环的时候，会出现两种方案：
```py
"a c d e f f bcf adc abe bed"
"a c d e f f cfb dca bea edb"
```
```py
"a c d e f f abc bed adcfbe"
"a c d e f f bca edb dcfbea"
```

不看自环，可以看成一组有$12$个字母的串组。

这组串刚好可以生成（$4$个长度为$3$的环）或（$2$个长度为$3$，一个长度为$6$的环）。

前者所代表的交换次数为$4\times(3-1)=8$,后者则为$2\times(3-1)+1\times(6-1)=9$，那么显然选前者的分配更为合理。

一开始直接生成最小环，一共就三个用例过不了，这是其中一个。

这时候我们就需要用到贪心的思想了，首先把周长为$3$的环的全部生成，然后两两比较，与其他环矛盾越多的环优先级就靠后，这里的矛盾指的是两个环和比这两环更短的环放进当前图会不会发生冲突，会冲突就是矛盾判断成功，两个候选环的矛盾指数各$+1$。

以上面这个用例为例，其中环$abc$在图里面跟$bcf$ $adc$ $abe$三个环都有冲突。

按矛盾指数来排序的话$p=[(b,e,d):0,(b,c,f):1,(a,d,c):1,(a,b,e):1,(a,b,c):3]$。

所以从贪心的思想来说，肯定优先生成前$4$个环，就这样虽然环$abc$就没有足够的边去生成了，但我们也达到了我们生成最多环的目的。

综上则可以将一个图分成更多更小的环，也即可计算出对应字符串的最小交换次数。

```python []
class Solution:
    def kSimilarity(self, A: str, B: str) -> int:
        d = collections.defaultdict(list)       #生成图，用字典存邻接表，方便遍历
        c = collections.defaultdict(int)        #生成边，方便矛盾判断
        for i, j in zip(A, B):
            if i != j:
                d[i] += [j]
                c[(i, j)] += 1

        def dfs(i, dep, path):  #深搜函数，参数分别是：遍历到点，深度，当前路径
            if dep == depth:
                if i == start:  #如果到达深度且成环，就加入候选环生成队列
                    nonlocal dep_loop
                    for i in range(depth + 1):
                        path = path[1: ] + path[: 1]
                        if tuple(path) in dep_loop and start != path[0]: #不反复生成多余的环
                            return
                    dep_loop += [tuple(path)]
            else:
                for j in d[i]:  #进一步深搜遍历
                    dfs(j, dep + 1, path + [i])

        def judgment(a, b):     #判断生成同样大小的环是否矛盾的函数
            tc = collections.defaultdict(int)
            for i in range(depth + 1):
                tc[(a[i - 1], a[i])] += 1
                tc[(b[i - 1], b[i])] += 1
            for i, j in tc:
                if tc[(i, j)] > c[(i, j)]:
                    return True
            return False

        ans = 0
        depth = 1
        while d:
            if depth == 5:      #最大深度剪枝
                ans += sum(c.values()) // 6 * 5
                break
            dep_loop = []       #同一深度生成候选环队列
            for i in d:
                start = i       #候选环深搜起点标记
                for j in d[i]:  #深搜生成环
                    dfs(j, 0, [i])
            n = len(dep_loop)
            p = collections.defaultdict(int)
            for i in range(n):
                for j in range(i + 1, n):
                    if judgment(dep_loop[i], dep_loop[j]): #两两比较是否矛盾，矛盾多的环优先级靠后
                        p[dep_loop[i]] += 1
                        p[dep_loop[j]] += 1
            dep_loop.sort(key = lambda x: p[x])     #按矛盾数对候选环进行升序排序
            for loop in dep_loop:                   #在候选环队列里逐个枚举尝试生成环
                tc = collections.defaultdict(int)
                flag = False
                for i in range(depth + 1):          #检查图里面是否还有足够的边生成该候选环
                    tc[(loop[i - 1], loop[i])] += 1
                    if tc[(loop[i - 1], loop[i])] > c[(loop[i - 1], loop[i])]:
                        flag = True
                        break
                if flag:        #尝试生成环失败，继续试下一个候选环
                    continue
                ans += depth    #当前环生成成功，交换次数等于生成深度，加到总答案里面去
                for i in range(depth + 1):          #删去图中已生成环的有向边
                    d[loop[i - 1]].remove(loop[i])
                    if not d[loop[i - 1]]:
                        d.pop(loop[i - 1])
                    c[(loop[i - 1], loop[i])] -= 1
                if not d:       #如果图空了就跳出循环
                    break
            depth += 1

        return ans
```

复杂度分析，边的预处理$O(n)$，对于生成环来说如果恰好都是周长为$6$的最大环，且总长为$6$的倍数的环，每个字符串则需要生成$(6\times n/6+6\times n/6\times n/6+6\times n/6\times n/6\times n/6+6\times n/6\times n/6\times n/6\times n/6\approx n^{4}/6^{3})$个路径，时间复杂度最大就是$O(n^{4})$去乘以后面的系数，空间复杂度则是$O(n^{5})$，但实际上大部分生成的环的周长都在$2-3$之间，所以整体生成的环并不多，这也是理论上的，即使最长为$20$的用例，我手算也能直接算出来，所有测试用例的生成环应该都不超过50个，平均时间复杂度我就算不出了，应该非常低，所以我的程序才能这么快，每个环在计算矛盾情况的时候，一方面需要分别遍历环判断删除之类的，还有优先排序那就是$O(n^{4}log(n^{4})) \approx O(n^{4}log(n))$，整体复杂度最坏应该是$O(n^{4}log(n))$吧。



顺便给大家看一个$200$长的自制用例，就是随机生成然后排序，属于平均复杂度，大约生成了小$5000$个环路径，我的代码一般都是$300$~$500ms$这样，$300$长的大约$1500$~$2500ms$，$400$长才有可能超过$5000ms$（会显示超时）。

```py
"fbbbaeccadbcdfcfaffafefdbaebeacdecdabcaeeadaffccaedbfcdacddfcbbbfefddcbffbbeffbebacfecafcacaabeafefdaecbefeeacfdbfeabaafddfadbedbdcadfeefbecadafddbedadcdebaceaaadfebdefbcfaecaadccacbbedbfdbffbdaeefcfe"
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbcccccccccccccccccccccccccccccddddddddddddddddddddddddddddddddeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeefffffffffffffffffffffffffffffffffffff"
```
![image.png](https://pic.leetcode-cn.com/335066aa7eabc0623edc320eefa04954b2aa495802c664a9907637e8633c0ea1-image.png)

另附时间最坏数据，5个一组的错位无法剪枝，所以只能硬算，生成路径不多，后续操作虽然按时间复杂度来算是常数级但也很大，总体很费时间，我的代码最多撑4组。

```py
"abcdeabcdeabcdeabcde"
"bcdeabcdeabcdeabcdea"
```
![image.png](https://pic.leetcode-cn.com/273dcd0469482d9a9063cbd3705c82c09b5bf684888d8bec5b36d196e45baacd-image.png)


另附空间最坏情况的爆栈数据，$18$组最大错位，口算为$(6-1)\times18=90$，路径是开了不少，但是并没有实际参与生成环，我的代码最多也只能撑得起$18$个单位的最坏情况，不知道大家的宽搜撑得起几个？

```py
"abcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdef"
"fabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcde"
```
![image.png](https://pic.leetcode-cn.com/09d508c34d510035d74a616a10926e971d20b1b10d04c811b2285a2b89f77338-image.png)
