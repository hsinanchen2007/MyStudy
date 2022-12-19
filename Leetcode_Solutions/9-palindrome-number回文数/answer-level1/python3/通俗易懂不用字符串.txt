拆解数值, 装入list中, 然后遍历一下.

class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        elif x == 0:
            return True
        _x = x
        temp_list = []
        while _x:
            temp_list.append(_x % 10)
            _x = _x // 10
        
        for i in range(len(temp_list)):
            if temp_list[i] != temp_list[-1-i]:
                return False
        return True