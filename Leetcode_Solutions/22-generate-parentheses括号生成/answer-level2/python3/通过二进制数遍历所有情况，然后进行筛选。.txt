### 解题思路
1. 生成2n位二进制数数列从0000到1111，假设0代表(，1代表）
2. 判断这个二进制数是否符合题目要求，当左右括号数不一致，或左右括号闭合出问题时返回false
3. 替换0，1，返回数组

思路很奇葩，但是效果不好，看看大神能不能改进
### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def is_valid(bin_num):
            match = 0
            for i in bin_num:
                if i == "0":
                    match += 1
                else:
                    match -= 1
                if match < 0:
                    return False
            if match == 0:
                return True
            else:
                return False
        result = []
        bin_len = 2*n
        for num in range(0,2**(bin_len)):
            bin_num = "{0:0{bin_len}b}".format(num, bin_len=bin_len)
            if is_valid(bin_num):
                bin_num = bin_num.replace("0","(")
                bin_num = bin_num.replace("1",")")
                result += [bin_num]
        return result
```