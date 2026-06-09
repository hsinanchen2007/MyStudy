按字典序生成
class Solution(object):
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        if not n:return []
        num = 1
        result = []
        for i in range(n):
            result.append(num)
            if num * 10 <= n:#1,10,100,...
                num = num * 10
            else:
                if num >= n:
                    num = num // 10
                num = num + 1#跳到另一分支
                while num % 10 == 0:#分支遍历完毕，跳到上一层级
                    num = num // 10
        return result