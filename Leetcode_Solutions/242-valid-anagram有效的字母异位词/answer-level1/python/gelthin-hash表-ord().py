### 解题思路
同习题 [gelthin-计数数组-遍历一个加另一个减](https://leetcode-cn.com/problems/bulls-and-cows/solution/gelthin-ji-shu-shu-zu-by-gelthin/)

习题[面试题 01.02. 判定是否互为字符重排](https://leetcode-cn.com/problems/check-permutation-lcci/solution/gelthin-yi-wei-ci-by-gelthin/)


使用一个 hash 表的方法非常好，这个有点像 查找子序列的题目，先对输入数据进行预处理，在进行题目所需的功能的判断, 可以很方便地处理大量数据。
hash 表不仅可是是 计数数组，还可以是 dict() 还可以是 set() 等各种不同的结构。

python3 语言特性： 两个字符没有减法，但可以使用 ord('b')-ord('a') 返回 ASCII 码相减值。

自己的原答案是进行排序，然后再进行处理。

参见官方题解 [242.有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/solution/you-xiao-de-zi-mu-yi-wei-ci-by-leetcode/)
有两种方法

+ 使用1个 hash 表，遍历时 +1 以及-1.
+ 也可以先用计数器表计算 ss，然后用 tt 减少计数器表中的每个字母的计数器。如果在任何时候计数器低于零，我们知道 tt 包含一个不在 ss 中的额外字母，并立即返回 FALSE。




### 代码

```python3
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        m, n = len(s), len(t)
        if m!=n:
            return False
        hash_table = [0]*26
        for x, y in zip(s, t):
            hash_table[ord(x)-ord('a')] += 1
            hash_table[ord(y)-ord('a')] -= 1
        for t in hash_table:
            if t != 0:
                return False
        return True

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        m, n = len(s), len(t)
        if m!=n:
            return False
        s = sorted(s)
        t = sorted(t)
        a, b = 0, 0
        while a<m and b<n:
            if s[a] != t[b]:
                break
            a += 1
            b += 1
        if a == m:
            return True
        else:
            return False

```