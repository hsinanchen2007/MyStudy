### 解题思路
1.
如果字符串长度相等，遍历寻找是否只需要替换一次
如果字符串长度不等，依次删除长字符串中的一个字符是否等于另一字符串

### 代码

```python3
class Solution:
    def oneEditAway(self, first: str, second: str) -> bool:
        if abs(len(first)-len(second)) > 1:
            return False
        
        replace_count = 0
        if len(first) == len(second):
            for i in range(len(first)):
                if first[i] != second[i]:
                    replace_count += 1
                if replace_count >= 2:
                    return False
                
            return True
            
        if len(second) > len(first):
            first,second = second, first

        if len(first) > len(second):
            for i in range(len(first)):
                if first[0:i] + first[i+1:] == second:
                    return True
            return False

'''
作者：flypython
链接：https://leetcode-cn.com/problems/one-away-lcci/solution/zong-he-ti-jie-by-flypython-3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
'''
```