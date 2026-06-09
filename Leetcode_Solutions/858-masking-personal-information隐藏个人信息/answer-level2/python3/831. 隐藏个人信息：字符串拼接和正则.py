![image.png](https://pic.leetcode-cn.com/de0b2bb969f356ac9ed5aa3fac58bf7472c4ee9ce44aba72d41707ac2db3260b-image.png)

```python []
class Solution:
    def maskPII(self, S: str) -> str:
        i = S.find('@')
        if i >= 0:
            return S[0].lower() + '*****' + S[i - 1: ].lower()
        else:
            s = re.sub('[\+\-\(\) ]', '', S)
            return '***-***-' + s[-4: ] if len(s) == 10 \
                else '+' + '*' * (len(s) - 10) + '-***-***-' + s[-4: ]
```
