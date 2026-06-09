### 大家好，我的博客是: http://erik-chen.github.io/，欢迎交流！
![image.png](https://pic.leetcode-cn.com/db6eea35e1af5186548e005833c8bf9a08ac90849df4a1f7d16190849e2bd47e-image.png)

### 解题思路
其实就是对votes[0]里的每一个字母进行排序，关键是排序的依据是什么？Python有现成的sort函数，那么参数key是什么呢？
1. 比较字母`A`比字母`B`在所有str的第`1`位，哪个出现次数多
2. 如果字母`A`和字母`B`在所有str的前`k`位出现次数都一样多，那么比较第`k+1`位，哪个出现次数多
3. 如果都一样多，就以字典序排序

所以怎么利用以上的规则，把key表示出来呢？
这里采取了把出现字数压缩成`chr`值的办法，然后依据字典序的方法来排序
1. 如果字母`A`在所有str的第`1`位出现5次，`B`出现4次，那么我们把`A`标记为`chr(1000-5)`，`B`标记为`chr(1000-4)`。因为`chr(1000-5) < chr(1000-4)`，所以`A`排在`B`的前面
2. 如果字母`A`和`B`在前`k`位都是一样的，那么前面k个chr值都一样。如果第`k+1`位，`A`比`B`多，那么依照上面的法则，`A`排在`B`的前面。
3. 如果都一样，我们就在chr值后面加上字母本身，因为`A`<`B`，所以`A`排在`B`的前面


### 代码

```python3
class Solution:
    def rankTeams(self, votes: List[str]) -> str:
        mapping = {}                                        # mapping储存key值
        for word in votes:
            for i, letter in enumerate(word):
                if letter not in mapping:
                    mapping[letter] = [1000] * len(word)    # 初始化key值
                mapping[letter][i] -= 1                     # 如果A在第i位多出现一次，就在第i位的chr值-=1，提高其比较的优先级
        for letter in mapping:
            mapping[letter] = ''.join((chr(x) for x in mapping[letter])) + letter   # 为了利用字典序，须转换为字符串
        return ''.join(sorted(votes[0], key=lambda x: mapping[x]))                  # 进行排序
```
