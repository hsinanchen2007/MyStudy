### 解题思路
写一个匹配字典，初始化值为0，分两种情况计算，只有一个罗马数字的字母时，和两个或两个以上的字母；一个字母时直接返回；第二种情况需要进行计算，两个两个进行比较，第一个小于第二个则要减掉第一个，否则加上；这个遍历里面没有包含最后一个字母，因此需要加上最后一个字母。


### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        num_dict = {'I':'1','V':'5','X':'10','L':'50','C':'100','D':'500','M':'1000'}
        sum = 0
        if len(s) is 1:
            # print(int(num_dict[s]))
            return int(num_dict[s])
        for i in range(1,len(s)):
            if int(num_dict[s[i-1]]) < int(num_dict[s[i]]) and i < len(s): sum -= int(num_dict[s[i-1]])
            else: sum += int(num_dict[s[i-1]])
        sum += int(num_dict[s[len(s)-1]])
        # print(sum)
        return sum
```

