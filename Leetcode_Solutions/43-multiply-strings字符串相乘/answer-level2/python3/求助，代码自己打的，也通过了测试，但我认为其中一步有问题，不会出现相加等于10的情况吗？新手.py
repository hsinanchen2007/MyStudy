```
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1=='0' or num2 == '0':
            return '0'
        len1 = len(num1)
        len2 = len(num2)
        ps = [0]
        k, count = 0, 0
        for i in range(len2):
            k = count
            for j in range(len1 - 1, -1, -1):
                temp = str(int(num2[-1]) * int(num1[j]))
                if len(temp) < 2:
                    temp = '0' + temp
                if ps[k] + int(temp[1]) >= 10:
                    ps[k] = ps[k] + int(temp[1]) - 10
                    ps.append(0)
                    if ps[k+1] + int(temp[0]) + 1 >=10:
                        ps[k+1] = ps[k+1] + int(temp[0]) + 1 -10
                        ps.append(0)
                        ps[k+2] = ps[k+2] + 1           ##### 我个人认为这步有问题，难道不会出现相加等于10的情况吗？？
                    else:
                        ps[k+1] = ps[k+1] + int(temp[0]) + 1
                else:
                     ps[k] = ps[k] + int(temp[1])
                     ps.append(0)
                     if ps[k + 1] + int(temp[0]) >= 10:
                         ps[k + 1] = ps[k + 1] + int(temp[0]) - 10
                         ps.append(0)
                         ps[k + 2] = ps[k+2] + 1
                     else:
                         ps[k + 1] = ps[k + 1] + int(temp[0])
                k = k + 1
            count = count + 1
            num2 = num2[:-1]
        ps.reverse()
        ps = list(map(str, ps))
        ss = ''.join(ps)
        return ''.join(ps).lstrip('0')


if __name__ == "__main__":
    ss = Solution()
    num1 = "999"
    num2 = "999"
    print(ss.multiply(num1, num2))

```
