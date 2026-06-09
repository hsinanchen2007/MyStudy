class Solution:
    def balancedStringSplit(self, s: str) -> int:
        count =   0                 # 记录分割到的子字符串数
        r_count = 0                 # 遍历时用于记录R的个数
        l_count = 0                 # 遍历时用于记录L的个数
        for i in s:
            if i =='R':
                r_count+=1
            else:
                l_count+=1
            if r_count == l_count:  # 当两个计数相等时 count加一
                count+=1
        return count