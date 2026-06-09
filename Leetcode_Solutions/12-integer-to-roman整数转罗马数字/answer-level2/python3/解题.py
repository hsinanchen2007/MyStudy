### 解题思路
执行用时 : 60 ms, 在所有 Python3 提交中击败了48.81%的用户
内存消耗 : 13.6 MB, 在所有 Python3 提交中击败了7.92%的用户

### 代码

```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        arr = [1,4,5,9,10,40,50,90,100,400,500,900,1000]
        strarr = ["I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"]
        lenarr = len(arr)-1
        s=""
        while num>0:
            if arr[lenarr]<=num:
                num-=arr[lenarr]
                s+=strarr[lenarr]
                
            else:
                lenarr-=1
            
        return s
```