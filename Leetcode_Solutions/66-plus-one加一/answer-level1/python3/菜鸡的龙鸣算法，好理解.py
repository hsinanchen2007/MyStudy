### 解题思路
思路很简单，就是把最开始的列表换成整数，这样加一就很简单了。然后再把它转成字符串放入空列表。最后输入的时候把字符串类型换成整型就搞定了。

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        lens=len(digits)
        sums=0
        for i in range(lens):
            sums+=digits[i]*10**(lens-1-i)
        sums+=1
        strs=str(sums)
        list1=[]
        lens1=len(strs)
        for j in range(lens1):
            list1.append(int(strs[j]))
        return list1

```