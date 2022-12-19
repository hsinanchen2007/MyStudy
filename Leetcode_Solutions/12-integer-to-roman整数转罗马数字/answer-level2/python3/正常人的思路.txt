### 解题思路
but
![1.png](https://pic.leetcode-cn.com/6f0ba20e476f78c33439da823c34f55747319c5dcf5a4c55e5f9eb7f6a4aba2d-1.png)
额额额


### 代码

```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        arr = [[1000,'M'],[900,"CM"],[500,'D'],[400,"CD"],[100,'C'],[90,"XC"],[50,'L'],[40,"XL"],[10,'X'],[9,"IX"],[5,'V'],[4,"IV"],[1,'I']]
        length = len(arr)
        result = ""

        for i in range(0,length):
            quality = int(num/arr[i][0])
            if quality > 0:
                num -= quality * arr[i][0]
                for j in range(0, quality):
                    result += arr[i][1]

        return result
```