### 解题思路
正序排完删除
逆序排完删除

### 代码

```python3
class Solution:
    def sortString(self, s: str) -> str:
        
        ans = [] 
        s_list = list(s)
        while s_list:
            #正序
            pos = sorted(set(s_list))
            for i in pos:
                s_list.remove(i)
            ans += pos
            
            #逆序
            neg = sorted(set(s_list), reverse = True)
            for i in neg:
                s_list.remove(i)
            ans += neg
        return ''.join(ans)


                

```