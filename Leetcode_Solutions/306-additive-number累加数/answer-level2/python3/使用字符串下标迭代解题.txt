### 解题思路
思路很直接，就是先定位第一个和第二个数字，然后校验字符串，只要符合累加条件，就返回true；
解题可一分层以下几个步骤：
1.确定第一个数字的边界。第一个数字位数最小为1位，最大为(len(num)-1)//2（假设第二个数字是一位，只有三个数字，因为第三个数字肯定比第一位数字大，因此假设第三个数字位数跟第一个数字相同）。因此第一层循环范围是：
```python3
    # i最小为1，最大为(len(num)-1)//2+1
    for i in range(1, (len(num)+1)//2):
        fst = num[:i]
```
2.确定第二个数字的边界。同理可推出第二层循环的范围：
```python3
    # 第二个数字位数最小为1位，最大为(len(num)-i)//2
    for j in range(i+1, (len(num)-i)//2+i+1):
        sed = num[i:j]
```
3.遍历字符串，校验是否累加数。有两种方法，一种是用减治法，使用递归（dfs）。检查剩余字符串前缀是否前两个数的累加。是的话继续递归剩余字符串。还有一种方法，使用迭代其实更加直白。定义一个指针start指向当前字符串已经遍历的位置，while循环检查累加数，start指针继续后移，但start指针到达字符串末位时，表示字符串是累加数。

### 代码

```python3
class Solution:
    # 迭代
    def isAdditiveNumber(self, num: str) -> bool:
        if len(num) < 3:
            return False
        def check(fst: int, sed: int, start: int) -> bool:
            while start != len(num):
                thrd = fst + sed
                thrdStr = str(thrd)
                if num.startswith(thrdStr, start):
                    start += len(thrdStr)
                    fst, sed = sed, thrd
                else:
                    return False
            return True
        # 第一个数字位数最小为1位，最大为(len(num)-1)//2
        for i in range(1, (len(num)+1)//2):
            fst = num[:i]
            # 检查0开头
            if len(fst) > 1 and fst[0] == '0':
                continue 
            # 第二个数字位数最小为1位，最大为(len(num)-i)//2
            for j in range(i+1, (len(num)-i)//2+i+1):
                sed = num[i:j]
                # 检查0开头
                if len(sed) > 1 and sed[0] == '0':
                    continue 
                if check(int(fst), int(sed), j):
                    return True
        return False
```