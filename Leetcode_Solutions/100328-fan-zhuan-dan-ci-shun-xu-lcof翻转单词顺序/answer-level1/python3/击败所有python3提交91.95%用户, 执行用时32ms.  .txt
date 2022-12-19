### 解题思路
![bc0d422ed299681f512224cf06a763b.png](https://pic.leetcode-cn.com/68f902df79a10dfbd283e9066a858e887f812fd73bbe1b8c36d0c73e14ece0b0-bc0d422ed299681f512224cf06a763b.png)

(小白朴素法) 去掉两边的" ", 再逆序遍历, 遍历遇到""直接跳过, 详见如下代码。
### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str: # 例如 s = "k  a good example  "
        res, stack = [], []
        stack = s.strip().split(" ")  # 此时stack=['k', '', 'a', 'good', 'example']
        for i in range(len(stack)-1, -1, -1):  # 逆序遍历stack
            if stack[i] == '':  #遇见空格，直接跳过本次循环
                continue
            else:
                res.append(stack[i]) #将非""的字符逐个追加到res数组
                
        return(' '.join(res)) #res数组转化成字符串输出


        



## 精简了下上面的代码(思路类似)，效率差不多。
class Solution:
    def reverseWords(self, s: str) -> str:     
        res, stack = [], []
        stack = s.split()
        for i in range(len(stack)-1, -1, -1):
            res.append(stack[i])          
        return(' '.join(res))
```

```





```