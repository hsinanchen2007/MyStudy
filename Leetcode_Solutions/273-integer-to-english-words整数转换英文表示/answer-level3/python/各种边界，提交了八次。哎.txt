### 解题思路
思路很简单 但是边界条件太多了

### 代码

```python3
class Solution:
    def numberToWords(self, num: int) -> str:
        if num <= 0:
            return "Zero"
        # 有没有发现都是3个一组的出现的....
        answer = []
        words1 = ["One", "Two", "Three", "Four", "Five", "Six",
                  "Seven", "Eight", "Nine", "Ten",
                  "Eleven", "Twelve", "Thirteen", "Fourteen",
                  "Fifteen", "Sixteen", "Seventeen", "Eighteen",
                  "Nineteen"]

        words2 = ["Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
        words3 = ['', 'Hundred', 'Thousand', 'Million', 'Billion']
        # 首先是三个一组
        level = 0
        stage = 0
        while num:
            # 每个后面都应该加上level
            tmp = num % 1000
            if 1 <= tmp <= 19:
                answer.insert(0, words1[tmp - 1] + ' ' + words3[level])
            elif 20 <= tmp <= 99:
                c = str(tmp)
                if tmp % 10 == 0:
                    answer.insert(0, words2[int(c[0]) - 2] + ' ' + words3[level])
                else:
                    high = words2[int(c[0]) - 2]
                    low = words1[int(c[1]) - 1]
                    answer.insert(0, high + ' ' + low + ' ' + words3[level])


            elif 100 <= tmp <= 999:
                # 最高位 中间一位 最低位 其实hundred是不变的
                c = str(tmp)
                high = words1[int(c[0]) - 1] + " " + 'Hundred'
                if 10 <= int(c[1:]) <= 19:
                    answer.insert(0, high + ' ' + words1[int(c[1:]) - 1] + ' ' + words3[level])
                # 可以被10 整除
                elif c[1:][0] != '0' and c[1:][1] == '0':
                    answer.insert(0, high + ' ' + words2[int(c[1]) - 2] + ' ' + words3[level])
                # 100 整除
                elif c[1:] == '00':
                    answer.insert(0, high + ' ' + words3[level])
                else:
                    mid = words2[int(c[1]) - 2] if c[1] != '0' else ''
                    low = words1[int(c[2]) - 1]
                    answer.insert(0, high + ' ' + mid + ' ' + low + ' ' + words3[level])
            level = level + 1 if level != 0 else level + 2
            num = num // 1000
            if num:
                answer.insert(0, ' ')
        answer = [' '.join(item.split()) for item in answer if item.strip() != '']
        print(answer)
        return ' '.join(answer).strip()
```