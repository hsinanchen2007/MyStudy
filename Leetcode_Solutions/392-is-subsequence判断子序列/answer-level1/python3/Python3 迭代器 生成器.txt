class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        iter_t = iter(t)
        return all(i in iter_t for i in s)

将t转化成一个迭代器 
s的遍历使用生成器 
all函数用来判断一个迭代器的元素是否全部为 True，如果是则返回 True，否则就返回 False