```
# 执行用时 :32 ms, 在所有 python3 提交中击败了98.02%的用户
# 内存消耗 :12.5 MB, 在所有 python3 提交中击败了100.00%的用户

class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        # 题意解读：确认前两个数字，后面即被确认
        # 思路：遍历前两个数字，优化是遍历不超过num_str的一半即可
        # 限制:开头不可为0--->但有'000'的情况，len(num)至少为3
        # 0可以作为一个数字，但不能有以0开头的数字
        len_num = len(num)
        if len_num<3:
            return False

        for i in range(len_num//2 + 1):
            num1 = num[:i+1]
            # 若num1是以0开头的数字，return Fasle
            if len(num1) != len(str(int(num1))):
                return False
            
            for j in range(i+1, len_num//2+i+1):
                num2 = num[i+1:j+1]
                if len(num2) != len(str(int(num2))):
                    # 若num2以0开头，break
                    break
                num3 = num[j+1:]
                if self.isValid(num1, num2, num3) and num3:
                    return True
        # print(1)
        return False

    def isValid(self, num1, num2, num3):
        # 已确定前两个数字，判断是否合法
        # print(num1, num2, num3)
        while num3:
            sum_num = str(int(num1) + int(num2))
            # print(sum_num)
            len_sum = len(sum_num)
            if num3.startswith(sum_num):
                num1 = num2
                num2 = sum_num
                num3 = num3[len(sum_num):]
            else:
                return False
        return True


```
