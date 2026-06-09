### 解题思路
一個指針i用於排序從第0位開始依次排序
另一個指針從0開始,一直尋找非0數字,找到就和指針i的交換

保證了前面的肯定爲0開始都是0.. 0不斷被置換出來

### 代码

```python3
class Solution:
    def moveZeroes(self, n: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = 0
        for j in range(len(n)):
            if n[j] :
                n[i],n[j] = n[j],n[i]
                i  += 1
```