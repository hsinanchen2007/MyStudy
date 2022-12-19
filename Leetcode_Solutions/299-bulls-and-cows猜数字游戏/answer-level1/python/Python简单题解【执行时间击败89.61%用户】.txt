### 解题思路
首先准备两个变量，A代表公牛个数，B代表奶牛个数。

第一步先遍历，找到对应位置相等的次数，即公牛个数。

第二步，对于secret和guess分别建立哈希表，统计每个数字出现的次数。

第三步，对于在guess中出现的数字，如果该数字也同时在secret中出现，B加上guess和secret中小的次数。

第四步，在统计B时，只比较了secret和guess有多少相同元素，而本题中，公牛和奶牛是分开的，所以，需要减去公牛的个人，即B-A。

### 代码

```python
class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        A = 0
        B = 0

        for i in range(len(secret)):
            if secret[i] == guess[i]:
                A += 1
        
        map1 = {}
        map2 = {}

        for i in range(len(secret)):
            map1[secret[i]] = map1.get(secret[i], 0) + 1
            map2[guess[i]] = map2.get(guess[i], 0) + 1

        for key in map2.keys():
            if key in map1.keys():
                B += min(map1[key], map2[key])
        
        ret = str(A)+"A"+str(B-A)+"B"
        return ret

```