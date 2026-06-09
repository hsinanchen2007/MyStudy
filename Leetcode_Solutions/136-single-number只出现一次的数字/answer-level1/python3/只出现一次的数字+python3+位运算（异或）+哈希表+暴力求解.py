### 解法1：异或（^）
1. 0与任何数异或都等于该数本身；
2. 两个相同的数异或等于0；
3. 异或支持结合律：a^b^c = a^(b^c)

代码如下：

```
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        target = 0
        for i in nums:
            target = target^i          
        return target
```
### 解法2：哈希表
1. 一遍遍历，用哈希表计数；
2. 再遍历，返回个数是1的数。
```
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        dic = {}
        for i in nums:
            dic[i] = dic.get(i,0)+1
            
        for i in nums:
            if dic.get(i)==1:
                return i
```
### 解法3：暴力法
1. 设置tmp数组；
2. 如i不在tmp中，则加入；
3. 如i已经在tmp中，删除tmp中的i（不加人）；
4. 遍历完以后，tmp中只剩下一个数，就是目标数。
```
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        tmp = []
        for i in nums:
            if i not in tmp:
                tmp.append(i)
            else:
                tmp.remove(i)
        return tmp[0]
```
