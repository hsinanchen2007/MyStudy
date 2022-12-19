### 解题思路
![QQ截图20200217164030.png](https://pic.leetcode-cn.com/5a8dbc39e1595be43857b9e874713940aac1f982f23c2a6aff276e0e6cff60ad-QQ%E6%88%AA%E5%9B%BE20200217164030.png)
每位都在(2, 5, 6, 9, 0, 1, 8)内，且至少一位在(2, 5, 6, 9)内

### 代码

```python3
class Solution:
    def rotatedDigits(self, N: int) -> int:
        bad_num2=[3,4,7]
        good_num=[2,5,6,9]
        res=0
        for n in range(N+1):
            flag=True
            for b in bad_num2:
                if str(n).find(str(b))!=-1:
                    flag=False
                    break
            if flag==True:
                for good in good_num:
                    if str(n).find(str(good))!=-1:
                        res+=1
                        break
                    else:
                        pass
        return res
```