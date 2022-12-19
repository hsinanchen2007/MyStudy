![image.png](https://pic.leetcode-cn.com/0d5718daee0360187531a02f8f86d89b1c0b3635f8c5cadc35b968c46db9bfeb-image.png)


```
class Solution:

    def get3BitStr(self, s: str):

        if len(s) != 3:
            s = '0' * (3 - len(s)) + s

        m = {
            0: 'Zero', 1: 'One', 2: 'Two', 3: 'Three', 4: 'Four', 5: 'Five', 6: 'Six', 7:'Seven', 8: 'Eight', 9:'Nine',
            10: 'Ten', 11: 'Eleven', 12: 'Twelve', 13: 'Thirteen', 14: 'Fourteen', 15: 'Fifteen', 16: 'Sixteen', 17: 'Seventeen', 18: 'Eighteen', 19: 'Nineteen',
            20: 'Twenty',
            30: 'Thirty',
            40: 'Forty',
            50: 'Fifty',
            60: 'Sixty',
            70: 'Seventy',
            80: 'Eighty',
            90: 'Ninety'
        }

        val = int(s[1:])
        ans = m[ord(s[0]) - ord('0')] + ' Hundred' if s[0] != '0'  else ""

        if val % 10 == 0 and val != 0:
            if ans != '':
                return ans + ' ' + m[val]
            else:
                return m[val]

        if val == 0:
            return ans

        if val <= 20:
            if ans != '':
                return ans + ' ' + m[val]
            else:
                return m[val]
        else:
            if ans != '':
                return ans + ' ' + m[val // 10 * 10] + ' ' + m[val % 10]
            else:
                return m[val // 10 * 10] + ' ' + m[val % 10]

    def numberToWords(self, num: int) -> str:
        if num == 0:
            return 'Zero'

        # 1 234 567 891
        # *   *   *
        #     1 000 000
        s = str(num)
        n = len(s)

        buf = []
        if n <= 3:
            return self.get3BitStr(s)
        elif n <= 6:
            ss = self.get3BitStr(s[:n-3])
            if ss != '':
                buf.extend([ss, 'Thousand'])
            buf.append(self.get3BitStr(s[n-3:]))

        elif n <= 9:
            ss = self.get3BitStr(s[:n-6])
            if ss != '':
                buf.extend([ss, 'Million'])

            ss = self.get3BitStr(s[n-6: n-3])
            if ss != '':
                buf.extend([ss, 'Thousand'])

            buf.append(self.get3BitStr(s[n - 3:]))

        else:
            ss = self.get3BitStr(s[:n-9])
            if ss != '':
                buf.extend([ss, 'Billion'])

            ss = self.get3BitStr(s[n-9:n - 6])
            if ss != '':
                buf.extend([ss, 'Million'])

            ss = self.get3BitStr(s[n - 6: n - 3])
            if ss != '':
                buf.extend([ss, 'Thousand'])

            buf.append(self.get3BitStr(s[n - 3:]))

        buf = [s for s in buf if s != '']
        return ' '.join(buf)
```
