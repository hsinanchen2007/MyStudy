BM方法和什么KMP算法大家加油实现
```py
# 方法一：内置函数法
class Solution1:
    def strStr(self, haystack, needle):
        if not needle:
            return 0
        return haystack.find(needle)


# 方法二：python切片法
class Solution2:
    def strStr(self, haystack, needle):
        if not needle:
            return 0
        else:
            n = len(needle)
            for i in range(len(haystack)-n+1):
                if haystack[i:i+n] == needle:
                    return i
            return -1


# 方法三：BF(Brute Force)纯暴力算法
class Solution3:
    def strStr(self, haystack, needle):
        if not needle:
            return 0
        else:
            n = len(needle)
            for i in range(len(haystack) - n + 1):
                for j in range(n):
                    if haystack[i + j] != needle[j]:
                        break
                    if j == n - 1:
                        return i
            return -1


# 方法四：RK(Rabin-Karp)算法，BF(Brute Force)纯暴力算法的改进（比较哈希值）
# 思路参考链接：https://mp.weixin.qq.com/s/67uf7pRxXh7Iwm7MMpqJoA
class Solution4:
    def strStr(self, haystack, needle):
        if not needle:
            return 0
        else:
            # 可先逐个比较主串和模式串的第一个字符是否匹配，再进行下面的程序
            # 将模式串转哈希值（此处为ASCII码数字相加）
            n_hash = 0
            for each in needle:
                n_hash += ord(each)
            # 主串中等长子串的哈希值
            h_hash = 0
            n = len(needle)
            for each in haystack[0: n]:
                h_hash += ord(each)
            # 逐个比较
            for i in range(len(haystack) - n + 1):
                # 若哈希值相同，为避免哈希值冲突，需进一步比较
                if n_hash == h_hash:
                    # 逐个匹配
                    if haystack[i: i + n] == needle:
                        return i
                # 若哈希值不同，且索引到主串中的最后一个子串时，可判定 -1
                elif i == len(haystack) - n:
                        return -1
                else:
                    h_hash = h_hash - ord(haystack[i]) + ord(haystack[i + n])

            return -1
```
