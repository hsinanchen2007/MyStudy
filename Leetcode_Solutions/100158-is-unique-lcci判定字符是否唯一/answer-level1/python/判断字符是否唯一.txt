class Solution(object):
    def isUnique(self, astr):
        """
        :type astr: str
        :rtype: bool
        """
        test_map = {}
        for ch in astr:
            test_map[ch] = 1
        if len(test_map) == len(astr):
            return True
        return False

    def is_unique(self, astr):
        """
        :param astr:
        :return:
        """
        for i in range(0, len(astr)):
            if len(astr.split(astr[i])) != 2:
                return False
        return True

提供了两种方法来解答此题
方法1：使用额外的存储结构，时间复杂度为O(N),空间复杂度为O(N)
方法2：不使用额外的存储结构，时间复杂度为O(N^2),空间复杂度为O(1)
这两种方法各有好坏，如果放在计算机刚刚发明出来的时代，方法2会更好一点。总之需要看使用场景才能够决定使用哪一种方法，不能一概而论