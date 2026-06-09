### 解题思路
要想找一个数最近的俩数，那么就找01 和 10 这中特殊的位置，进行翻转
找较小时，将10 变成01，并将后面所有的1都排在前面，0排在后面
找较大时，将01变成10，后面的先0后1
注意，较大数是可以进位的，比如10，较大的那个数是100，所以在每个二进制前面先加一个0便于应对这种情况

### 代码

```python3
class Solution:
    def findClosedNumbers(self, num):
        #较大就找'01'变成'10'
        num = str(bin(num))[2:] #去掉'0b'
        if not '0' in num:
            res = '10' + num[1:]
            return [int('0b' + res,2),-1]

        num = '0' + num #在前面添加一个0
        temp = num[::]
        small = -1
        big = -1
        for i in range(len(temp)-1,-1,-1):
            # print(temp)
            if temp[i:i+2] == '10':
                t = temp[i+2:]
                temp = temp[0:i] + '01' + '1' * t.count('1') + '0'*t.count('0')
                small = temp[::]
                break
        temp = num[::]
        # print(temp)
        for i in range(len(temp)-1,-1,-1):
            if temp[i:i+2] == '01':
                t = temp[i+2:]
                temp = temp[0:i] + '10' + '0' * t.count('0') + '1' * t.count('1')
                big = temp[::]
                break
        if small != -1:
            small = int('0b' + small,2)
        if big != -1:
            big = int('0b' + big,2)
        return [big,small]
```