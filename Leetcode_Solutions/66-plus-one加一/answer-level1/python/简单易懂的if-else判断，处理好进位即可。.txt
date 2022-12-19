

> 关键是判断好最后一位加1之后是否需要进位，进位之后，还要判断后续是否需要进一步进位。

```python
from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if digits[-1] < 9:  # 不会进位 相加即可
            digits[-1] += 1
        else:  # 最后一位是9会进位
            i = -1
            while True:
                digits[i] = 0  # 先将最后一位置为0
                if abs(i-1) <= len(digits):  # 然后判断后续是否需要进一步进位
                    if digits[i-1] < 9:  # 进位到此处即可停止
                        digits[i-1] += 1
                        break
                    else:  # 会依次进位 继续循环
                        i = i - 1
                else:  # 到最高位了
                    digits.insert(0, 1)  # 在开始位置前添加1即可 不需要额外空间
                    break

        return  digits

Input = [[9,9], [9], [9, 9, 9], [6, 9, 9]]
Answer = [[1, 0, 0], [1, 0], [1, 0, 0, 0], [7, 0, 0]]

if __name__ == "__main__":
    solution = Solution()
    for i in range(len(Input)):
        print("-"*50)
        reslut = solution.plusOne(Input[i])
        if reslut == Answer[i]:
            print(True)
        else:
            print(False)
            print(Input[i])
```


时间复杂度：$O(n)$，当输入的n个数都是9时，就会循环n遍进行持续进位。  
空间复杂度：$O(1)$，没有使用额外的空间。  
执行用时 :40 ms, 在所有 Python3 提交中击败了50%的用户  
内存消耗 :13.6 MB, 在所有 Python3 提交中击败了5.06%的用户  