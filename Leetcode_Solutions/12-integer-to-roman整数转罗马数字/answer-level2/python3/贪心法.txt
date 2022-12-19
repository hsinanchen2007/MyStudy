### 解题思路
本题主要运用算法是**贪心法**：

- 给一个固定大小的数值，我们需要选定最少使用钞票张数来组成这个数值，那么就用到了贪心的思想，
- 我们每次选用满足面额的最大的，所以，要先进行排序，从大到小取满足的面额

- 像IV这种特殊值，也要放到构建的字典中

### 代码

```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        rmb = [1,4, 5, 9,10,40, 50,90, 100,400, 500, 900,1000]
        dd = ['I','IV','V','IX','X','XL','L','XC', 'C','CD','D','CM', 'M']
        s = dict(zip(dd[::-1],rmb[::-1])) #构建从大到小排序的字典
        sum = {}
        str1 = ""
        for i,j in s.items():

            use = num // j
            num = num - j*use
            if use>0:
                sum[i] = use

        for i,j in sum.items():          
            str1 += i*j
        return str1
        
      
```