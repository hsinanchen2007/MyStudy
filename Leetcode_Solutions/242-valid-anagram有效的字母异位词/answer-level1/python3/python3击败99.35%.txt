### 解题思路
见代码。
1.长度不一致，false
2.利用set排除相同元素，元素不相同，false
3.元素相同，判断相同元素个数是否相同
![屏幕快照 2019-12-18 16.52.48.png](https://pic.leetcode-cn.com/529ae8d8eda428bf1e206d78ae285b89d183e4fc79385efb29295caf4688826e-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-12-18%2016.52.48.png)

### 代码

```python3
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        else:
            ss = set(s)
            tt = set(t)
            if ss != tt:
                return False 
            else:
                ls = list(ss)
                for i in range(len(ls)):
                    if s.count(ls[i]) != t.count(ls[i]):
                        return False
                return True
                
```