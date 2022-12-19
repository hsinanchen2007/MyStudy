# 题解
从后向前依次遍历，保存每次相加后除以10的商和余数，给下个数计算。

## 一次遍历
 1. 初始化加数$tmp=1$，数组长度$n$
 2. 从后向前遍历，遍历区间[n-1,0]:
 	* 剪枝，若加和$tmp==0$，直接退出，返回结果
 	* 若首位数加上$tmp$等于$10$，将$digits[0]$更新为余数$(digits[0]+tmp)%10$，并手动在最前面加个$1$。并退出。
 	* 将$digits[i]$更新为余数，并令$tmp$更新为商。
 
 3. 返回数组

### 复杂度分析
 - 时间复杂度：$O(N)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        tmp=1
        n=len(digits)
        for i in range(n-1,-1,-1):
            if(tmp==0):
                break
            if(i==0 and (digits[i]+tmp)==10):
                digits[i]=(digits[i]+tmp)%10
                digits=[1]+digits
                continue
            cur=digits[i]+tmp
            digits[i]=cur%10
            tmp=cur//10
        return digits
```