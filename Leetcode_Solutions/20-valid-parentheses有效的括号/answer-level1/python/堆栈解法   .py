![捕获.PNG](https://pic.leetcode-cn.com/1b2113835f675c2f95bf38f950eb16501bf834cf4ce85897dadc5e27869be322-%E6%8D%95%E8%8E%B7.PNG)


"堆栈解法，遍历字符串s \n
        情况1：遍历到的字符在字典dic的键中，则将遍历到的字符加入堆栈。 \n
        情况2：遍历到的字符不在字典dic的键中 \n
            如果堆栈不为空且遍历到的字符与栈顶元素有效闭合，则栈顶元素出栈，继续遍历,否则不是有效括号， \n
            如果堆栈为空,则说明不是是有效字符串。 \n
            如果到最后堆栈为空，则说明是有效字符串，否则不是"

class Solution:
    def isValid(self, s: str) -> bool:
        dic = {
            "(": ")",
            "[": "]",
            "{": "}",
        }
        stock = []
        for x in s:
            if x in dic:
                stock.append(x)
            else:
                if stock:
                    # stock.pop()  栈顶元素出栈并返回值
                    if dic[stock.pop()] == x:
                        continue
                    else:
                        return False

                else:
                    return False

        if len(stock) == 0:
            return True

        else:
            return False