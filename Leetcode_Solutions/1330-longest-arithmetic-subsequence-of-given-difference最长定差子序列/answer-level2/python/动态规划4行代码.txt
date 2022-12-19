### 解题思路
dp存储以数字n结尾的子序列最大长度
遍历数组，如果n-difference存在则代表n可以拼接在子序列后面，使长度加1
如果不存在，说明不能和任何子序列拼接，就变成一个新子序列的开头

### 代码

```python3
dp=dict()
for n in arr:
    dp[n]=(dp[n-difference] if n-difference in dp else 0)+1
return max(dp.values())
```