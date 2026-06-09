**利用Python语言优势，将字符串转为List，再将List逆序输出，即可简单快速解题，代码如下：**

```python []
class Solution:
    def reverseWords(self, s: str) -> str:        
        l = s.split(' ')
        ans = []
        for i in range(len(l)):
            ll = l.pop()
            if ll != '':
                ans.append(ll)
        x = ' '.join(ans)
        return x 
```
<br>
**提交结果可战胜90%+的用户**
![QQ截图20190904011752.png](https://pic.leetcode-cn.com/3d707fcbd109610103fbd8bc149b2a0e27dbf10c21e694d463774875ecae9d5e-QQ%E6%88%AA%E5%9B%BE20190904011752.png)
