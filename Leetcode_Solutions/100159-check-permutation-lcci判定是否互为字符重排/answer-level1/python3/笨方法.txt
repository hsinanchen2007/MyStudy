### 解题思路
此处撰写解题思路
1、长度是否相同
2、去重
3、冒泡看s1在s2的出现次数
4、次数等同于长度即相等
### 代码

```python3
class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        count = 0
        ss1=''.join(set(s1))
        ss2=''.join(set(s2))
        if(len(ss1)==len(ss2)):
            for i in range(len(ss1)):
                for j in range (len(ss2)):
                    if ss1[i]==ss2[j]:
                        count = count + 1  
            if count ==len(ss1):              
                return True                
            else:
                return False                                       
        else:
            return False

```