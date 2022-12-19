用for移动右边界来写比较简单  

```python3
    def findAnagrams(self, s: str, p: str) -> List[int]:
        left, right = 0, 0                                  #滑动窗口左边界
        window = {}                                         #滑动窗口
        need = {}                                           #统计p的字符数
        re = []
        for i in p:
            need[i] = need.get(i,0) + 1
            
        for right in range(len(s)):                         #右边界滑动
            window[s[right]] = window.get(s[right], 0) + 1  #每次滑动新加入右侧值到window中
            if left + len(p) == right:                      #窗口满了，那就把左边的弹出去  
                if window[s[left]] == 1:                    #只有1个时需要删掉key，不然后面dict对比有问题
                    window.pop(s[left])
                else:
                    window[s[left]] -= 1
                left += 1                                   #左窗口右移一位
            if window == need:                              #一样就把左窗口坐标加入结果
                re.append(left)
        return re
```
