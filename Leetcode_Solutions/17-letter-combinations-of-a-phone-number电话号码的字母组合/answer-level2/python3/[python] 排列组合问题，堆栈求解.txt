首先这是一个排列组合问题，见精选题解。
这道提的难点在于，你也不知道digits的长度有多长，遍历比较麻烦。
如果disgits='23',对应的手机letter是pre=['a', 'b', 'c'],cur=['d', 'e', 'f']
    此时两个遍历就解决了，pre中的每个字符后面都分别加上cur中的字符，得到res=['ad', 'ae', 'af', 'bd', 'be', 'bf', 'cd', 'ce', 'cf']
如果digits='234'，那么此时pre为disgits=’23’的res，cur=['g', 'h', 'i']

以此类推，只需要
1. 将digits先转化成数字对应的字符list,作为堆栈digits
2. 初始化pre=digits.pop
3. 当digits非空时，pop出cur,for循环拼接字符，作为新的new_pre
4. 更新pre=new_pre
```
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits)==0:
            return []
        letter = {'2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z']}
        digits = [letter[d] for d in digits]
        digits.reverse()
        # init
        pre = digits.pop()
        while digits:
            cur = digits.pop()
            new_pre = []
            for p in pre:
                for c in cur:
                    new_pre.append(p + c)
            pre = new_pre
        return pre
```
