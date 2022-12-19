### 解题思路
![QQ截图20200214180051.png](https://pic.leetcode-cn.com/31caa1a69bbc1eccb54cc5143b0e41d8a0b39facbb7ea46a7a2b0cd6924f0482-QQ%E6%88%AA%E5%9B%BE20200214180051.png)

我承认我有炼钼情结
### 代码

```python3
class Solution:
    def numberOfLines(self, widths: List[int], S: str) -> List[int]:
        sum_width=0#一行能容纳的sum_width<=100
        res1=0
        for i in range(0,len(S)):
            sum_width+=widths[ord(S[i])-ord("a")]
            if sum_width==100:
                res1+=1
                sum_width=0#开下一行
            elif sum_width>100:
                res1+=1
                sum_width=widths[ord(S[i])-ord("a")]#上一行的放不下的字母所占的单位
            else:
                pass
        return [res1+1,sum_width]
```