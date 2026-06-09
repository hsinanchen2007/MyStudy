![微信图片_20190915013206.png](https://pic.leetcode-cn.com/9e93f8caa10399f2f60d41d33ecd3297cf69e3acfb504996cd5adfdb1fb3e6d0-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20190915013206.png)


##### 截图奉上， 32ms仅供参考

##### 思路1是：如果能归纳出str1和str2的结构，那么问题就解决了。比如aabcc和ccbee，我们其实不关心具体的字母，而需要把 “{oo} {o} {oo}”的结构抽象出来。
##### 又比如sssppuu和zzzoooo，结构分别是 {ooo} {oo} {oo} 和 {ooo} {oooo} 。只要对str1的每一个{}去验证是str2的相同位置的{}的子集（可以相等，也可以是真子集）

##### 思路2是：直接匹配，效率比思路1稍高。

##### 1. 归纳结构法: 
分为两步，先归纳出跟字母无关的结构，再判断是否是子集：
```python []
class Solution:
    def canConvert(self, str1: str, str2: str) -> bool:
        import collections

        if len(set(str2)) == 26: ## 如果str2里有所有26英文字母，那么转换的时候会“卡住”。除非str1和str2相同，就不用转换
            return str1 == str2 
        
        n = len(str1)

        refer1 = collections.defaultdict(set)  ## 创建字典来放str1中字母和所有该字母的位置
        structure1 = {}  ## 绕开字母，创建字典来放索引号和所有有相同值的位置信息（即结构）
        for i in range(n):
            refer1[str1[i]].add(i)
            structure1[i] = refer1[str1[i]]

        refer2 = collections.defaultdict(set)  ## 同上，处理str2
        structure2 = {}
        for i in range(n):
            refer2[str2[i]].add(i)
            structure2[i] = refer2[str2[i]]

        for i in range(n):
            if structure1[i] - structure2[i] != set():  ## 判断相同位置str1的{}是否是str2的{}的子集
                return False
        return True
```

##### 2. 直接匹配法: 
遍历str1、str2，如果过程中出现矛盾，直接返回False：
```python []
class Solution:
    def canConvert(self, str1: str, str2: str) -> bool:
        refer = {}  ## 创建字典用来记录str1和str2中的字母对应关系
        n = len(str1)
        for i in range(n):
            if str1[i] not in refer: ## example：如果a对应b，那么记录下refer[a] = b
                refer[str1[i]] = str2[i]
            elif refer[str1[i]] != str2[i]: ## example：已知refer[a] = b，如果出现a对应c，那么有矛盾，直接return False
                return False
        
        if len(set(str2)) == 26: ## 如果str2里有所有26英文字母，那么转换的时候会“卡住”。除非str1和str2相同，就不用转换
            return str1 == str2 

        return True ## 以上都没问题的话，就是可以对应的

```
##### 直接匹配法平均用时比归纳结构法稍短的原因是，遇到无法匹配的情况马上return False，而不用再去考察后面的信息。
##### 但如果我们有m个str1和n个str2，归纳结构法更优：先用O(m+n)的时间把每一个str1和str2的信息先行归纳了，再用O(m*n)的时间去对简化的信息做处理。
##### 直接匹配法直接对未处理的信息进行O(m*n)次处理。

