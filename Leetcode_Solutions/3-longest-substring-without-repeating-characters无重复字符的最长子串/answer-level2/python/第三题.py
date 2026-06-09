### 解题思路
不用转列表，用字符串计算就可以。

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        test_list = list(s)
        test_list2 = []
        a = 0
        long_list = []   #用来存放非重复字符计数
        
        if len(test_list) == 0:a = 0
        for i in range(len(test_list)):            
            if test_list[i] in test_list2:
                n = len(test_list2)
                long_list.append(n)
                j = test_list2.index(test_list[i])
                test_list2 = test_list2[j+1:]
                test_list2.append(test_list[i])
            else:
                test_list2.append(test_list[i])
        n = len(test_list2)  #计算最后剩下的非重复的字符长度
        long_list.append(n)
                    
        a = max(long_list)
            
        return a
```