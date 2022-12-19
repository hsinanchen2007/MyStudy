$O(n^2)$的方法一定超时。

`rightEnding`指当前最大的亮着的灯泡
1. 位操作【超时】
    
```
class Solution:
    def numTimesAllBlue(self, light):
        if not light:return 0
        state ,rightEnding ,mask,count= 0,0,0,0
        for ele in light:
            state |= 1<<(ele-1)
            rightEnding = max(rightEnding,ele)
            mask = 2 ** rightEnding -1
            if mask & state == mask:
                count += 1

        return count 
```

2. 字符串比对【通过】

```
class Solution:
    def numTimesAllBlue(self, light: List[int]) -> int:
        if not light:return 0
        state ,rightEnding ,count= '0'*(len(light)+1),0,0
        for ele in light:
            state = state[:ele]+'1'+state[ele+1:]
            rightEnding = max(rightEnding,ele)
            mask = '0'+'1'*rightEnding
            if mask == state[:rightEnding+1]:
                count += 1

        return count 
```
时间复杂度*O(n)*

感觉思路不够优雅。

3. 讨论区[Amir](https://leetcode-cn.com/u/amir-6/)十分巧妙的方法。

循环一次，记录一个值：当前打开的最大的灯的编号，如果当前开灯数量等于这个编号，那么当前所有灯就都是开的。

```
class Solution:
    def numTimesAllBlue(self, light: List[int]) -> int:
        cm = 1
        cnt = 0
        for i, l in enumerate(light):
            cm = max(cm, l)
            if i + 1 == cm:
                cnt += 1
        return cnt

作者：Amir
链接：https://leetcode-cn.com/circle/discuss/5HNw3j/view/Des6Im/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```
