求出每一个字符距离右边的第一个C字符的距离，组成列表l1，再然后求出每一个字符距离左边的第一个C字符的距离，组成列表l2.可以直接让字符串S加上一个反序的S，组成一个新的S。然后求出一个总的距离列表，列表前一半是从左往右遍历，后一半是从右往左遍历，再挨个比较取最小值，组成列表ans即可。
```
class Solution:
    def shortestToChar(self, S: str, C: str) -> List[int]:
        l = []
        index = 0
        S += S[::-1]
        for i in S:
            if i == C:
                l += [x for x in range(index + 1)][::-1]
                index = 0
            else:
                index += 1
        if index != 0:
            l += [x for x in range(1,index + 1)]
        ans = []
        for i in range(len(l)//2):
            ans.append(min(l[i],l[-(i+1)]))
        return ans
```
