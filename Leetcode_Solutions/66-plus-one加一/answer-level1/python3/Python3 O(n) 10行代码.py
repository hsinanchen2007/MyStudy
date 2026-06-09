
`
class Solution1:
    def plusOne(self, digits: List[int]) -> List[int]:
        results = []
        first = True  # first用于标记是否是第一位，如果是第一位需要手动加一
        plus = 0  # plus用于保存进位
        while digits:
            element = digits.pop()  # 从后向前取值

            # 只有第一位需要手动加一
            if first:
                element += 1
                first = False

            if plus:
                element += plus
            plus = element // 10  # 取余
            element %= 10  # 取模
            results.append(element)
        # 遍历之后，进位可能为1，如 [9]
        if plus:
            results.append(plus)
        return list(reversed(results))  # 翻转结果

# 精简
class Solution2:
    def plusOne(self, digits: List[int]) -> List[int]:
        results = []
        plus = 1  # plus变量用于保存进位，0或1，digits最后一位需要加一，相当于起始的plus为1
        while digits:
            element = digits.pop()  # 从后向前取数
            # 存在进位则相加
            if plus:
                element += plus
                
            plus = element // 10
            element %= 10
            results.append(element)
        if plus:
            results.append(plus)
        return list(reversed(results))

# 继续精简
class Solution3:
    def plusOne(self, digits: List[int]) -> List[int]:
        results = []
        plus = 1
        while digits:
            element = digits.pop() + plus  # 从后向前取数，直接与进位值相加，plus 为 0 或 1
            plus = element // 10
            element %= 10
            results.append(element)
        if plus:
            results.append(plus)
        return list(reversed(results))
`