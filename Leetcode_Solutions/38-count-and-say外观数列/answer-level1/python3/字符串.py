### 解题思路
基本的思路就是找到连续的数字num，并记录长度，比如长度len的num
	那么就生成len+num

伪代码:
![批注 2020-04-10 110532.png](https://pic.leetcode-cn.com/8f5ed9b73b2361fb19a81adce7b0d4ba44b89fbcaeaf99f120dbf14d4a91f728-%E6%89%B9%E6%B3%A8%202020-04-10%20110532.png)



### 代码

```python3
class Solution:
    def countAndSay(self, n: int) -> str:
        res = '1'
        for i in range(2,n+1):
            new_res = ''
            while res:
                j = 1
                while j<len(res) and res[j] == res[0]:
                    j += 1
                new_res += str(j)+res[0]
                res = res[j:]
            res = new_res
        return res

```