# 题解
显然的想法，和凑零钱的问题一样，每次选择最大的，可以保证用的罗马字符最少且最终的组合唯一。

## 贪心算法

 1. 初始化词典$numtochar=\{1:"I",\cdots,1000:"M"\}$，保存可用的字符。
 2. 对于可以选择的数值$key$，我们使用贪心策略，从大到小选，即从$1000$到$1$：
 	+ 若$num==0$：则退出
 	+ 定义$tmp=num//key$，表示使用当前数值几次
 	+ 若$tmp==0$，表示$num<key$，所以跳过
 	+ 在$res$中加入$tmp$个$key$对应的罗马数字。
 	+ 更新$num=num-tmp*key$
 
 3. 返回$res$

	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
### 复杂度分析
 - 时间复杂度：$O(1)$
 - 空间复杂度：$O(1)$

### Python
```python
class Solution:
    def intToRoman(self, num: int) -> str:
        num_dict={1:'I',
            4:'IV',
            5:'V',
            9:'IX',
            10:'X',
            40:'XL',
            50:'L',
            90:'XC',
            100:'C',
            400:'CD',
            500:'D',
            900:'CM',
            1000:'M' }
        res=""
        for key in sorted(num_dict.keys())[::-1]:
            if(num==0):
                break
            tmp=num//key
            if(tmp==0):
                continue
            res+=num_dict[key]*(tmp)
            num-=key*(tmp)
        return res
```