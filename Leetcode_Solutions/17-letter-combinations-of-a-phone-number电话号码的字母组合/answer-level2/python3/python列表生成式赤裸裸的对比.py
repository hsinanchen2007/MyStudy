# 版本一
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        result = None
        dict_match = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}
        for index, digit in enumerate(digits):
            if index == 0:
                result = [i for i in dict_match[digit]]  # 根据第一个数字对应的字符串来初始化result，如2对应的'abc'，则result = ['a', 'b', 'c']
            else:
                temp_result = []
                for i in range(len(result)):  # 对于result中的每一项每次只更新一个字符
                    for j in dict_match[digit]:
                        temp_result.append(result[i]+j)
                result = temp_result
        return result


# 版本二
class Solution:  # 没有对比就没有伤害
    def letterCombinations(self, digits: str) -> List[str]:
        dict_match = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}
        result = ['']
        if not digits: return []
        for digit in digits:
            result = [y+x for y in result for x in dict_match[digit]]
        return result