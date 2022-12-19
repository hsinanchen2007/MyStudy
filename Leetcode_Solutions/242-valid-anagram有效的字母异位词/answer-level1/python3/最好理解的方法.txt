大家都知道python中remove()函数的特性，就是只会删除一个给定的值。
于是本题的思路就出来了，先将t字符串转化为列表，再遍历S字符串，如果在t中找到对应的字符就将列表中该值删掉，
否则返回False，如果遍历到末尾则返回True


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
            return False
        list1 = list(t)
        
        for i in s:
            if i in list1:
                list1.remove(i)
            else:
                return False
        
        return True