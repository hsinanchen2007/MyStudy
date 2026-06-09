### 解题思路
此题可以换种思路：确定前两个元素的位数，来匹配后面的元素是否符合斐波那契数列的规律。我们首先定义一个子函数match(m,n,S)，其中m,n分别为斐波那契数列的前两位元素的位数，根据前两个元素确定后面的元素是否在接下来的字符串中，若存在，则继续遍历，反复循环，直到遍历全部，若不存在，则返回False。遍历完之后，检查一下斐波那契数组的元素总位数是否等于字符串长度，若相等，则返回True和斐波那契数列，若不等，说明中间存在0元素，是的斐波那契数列元素总位数小于字符串长度。
由于m,n长度不可能超过数组长度的一半，设置两个for循环，依次带入match(i,j,S)函数，看是否返回True，若返回true,由于位数限制，我们只需要比较斐波那契数列最后一个元素是否大于2**31-1，若大于，返回空集，否则返回斐波那契数列。

### 代码

```python3
class Solution:
    def splitIntoFibonacci(self, S: str) -> List[int]:
        if int(S) == 0 and len(S) > 1:
            return [0]*len(S)
        def match(m,n,S):
            feibo = []
            feibo.append(int(S[:m]))
            feibo.append(int(S[m:m+n]))
            k = m + n 
            k2 = len(str(feibo[-1] + feibo[-2]))
            while(k + k2 <= len(S)):
                k1 = feibo[-1] + feibo[-2]
                k2 = len(str(k1))
                if int(S[k:k+k2]) == k1:
                    feibo.append(k1)
                    k += k2
                else:
                    return False,feibo
            str1 = ''
            for i in feibo:
                str1 += str(i)
            if str1 != S or len(feibo) < 3:
                return False,feibo
            else:
                return True,feibo

        for i in range(1,int(len(S) / 2 + 1)):
            for j in range(1,int(len(S) / 2 + 1)):
                if match(i,j,S)[0] == True:
                    if match(i,j,S)[1][-1] > 2**31 - 1:
                        return []
                    else:
                        return match(i,j,S)[1]
                else:
                    continue
        return []
```