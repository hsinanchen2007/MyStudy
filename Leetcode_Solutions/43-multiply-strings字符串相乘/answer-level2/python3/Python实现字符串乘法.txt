import collections


class Solution(object):
    """
       字符串乘法，严格字符串相乘。最多用到个位数相乘，对于每个字符转成数字，然后相乘，如果完全避免乘法，
       可以使用乘法表实现.
    """
    def multiply(self, num1, num2):
        n_num1 = len(num1)
        n_num2 = len(num2)
        mul_res = ''
        if n_num1 == 0 or n_num2 == 0:
            return res
        if num2 == '0' or num1 == '0':
            return '0'
        digit_map = {str(x): x for x in range(10)} # 字符-数字映射
        alpha_map = {x : str(x) for x in digit_map.values()} # 数字-字符映射
        
        mul_level = 0
        for i in range(n_num2 - 1, -1, -1):
            m_ply = num2[i] # 逐个10进制位相乘，然后再相加
            part_prod = self.str_multiply(num1, m_ply, digit_map, alpha_map) # 逐个数字位相乘
            mul_res = self.str_add(mul_res, part_prod, digit_map, alpha_map, mul_level) # 错位相加，进位
            mul_level += 1
        return mul_res

    def str_add(self, add_str1, add_str2, digit_map, alpha_map, mul_level):
        if mul_level == 0:
            return add_str2
        # 进位开始
        len_num1 = len(add_str1)
        len_num2 = len(add_str2)
        tail_pos1 = len_num1 - 1
        tail_pos2 = len_num2 - 1
        sum_res = collections.deque()
        sum_res.appendleft(add_str1[-mul_level:])
        carry_val = 0
        for i in range(len_num2):
            if tail_pos1 - mul_level - i >= 0:
                add_1 = add_str1[tail_pos1 - mul_level - i]
            else:
                add_1 = '0'
            add_2 = add_str2[tail_pos2 - i]
            part_sum = digit_map[add_1] + digit_map[add_2] + carry_val
            res_val = part_sum % 10
            carry_val = part_sum // 10
            sum_res.appendleft(alpha_map[res_val])
        if carry_val != 0:
            sum_res.appendleft(alpha_map[carry_val])
        return ''.join(sum_res)

    def str_multiply(self, nums, mul, digit_map, alpha_map):
        n_nums = len(nums)
        carry_val = 0
        prod_res = collections.deque()
        for i in range(n_nums - 1, -1, -1):
            m_plc = nums[i]
            part_prod = digit_map[m_plc] * digit_map[mul] + carry_val
            res_val = part_prod % 10
            carry_val = part_prod // 10
            prod_res.appendleft(alpha_map[res_val])
        if carry_val != 0:
            prod_res.appendleft(alpha_map[carry_val])

        return ''.join(list(prod_res))