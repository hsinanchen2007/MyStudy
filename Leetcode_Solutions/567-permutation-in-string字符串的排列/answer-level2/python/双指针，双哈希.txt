执行用时 :44 ms, 在所有 Python 提交中击败了99.39%的用户。

**核心点：使用双哈希和双指针**

hash1存储s1的字符及其数量；hash2存储s2在索引head和tail的字符及其数量，其中：
`tail - head = len(s1), tail < len(s2) - 1;`
比较hash1和hash2，如果不同，则在保证tail合法的情况下，将tail加1，接下来：
1. 如果tail所对应的值在s1中，则修hash1，将s1[tail]对应的字符数加1，同时将s1[head]对应的字符数减1，并将head加1
2. 如果tail所对应的值不在s1中，那么说明，我们需要从tail + 1开始，重新构建hash2，这里需要考虑tail + 1 + len(s1)是否合法：
- 如果合法，则继续
- 如果不合法，遍历结束

最后需要注意的是，对于tail值的判断，这里我是直接选取的是索引，所以需要考虑加减1的问题。虽然是小问题，但是很容易错。
```
class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        def getHash(s): # 拿到哈希
            hashTable = dict()
            for c in s:
                if c not in hashTable:
                    hashTable[c] = 0
                hashTable[c] += 1
            return hashTable

        lenS1 = len(s1)
        lenS2 = len(s2)
        lenDiff = lenS2 - lenS1

        if lenDiff < 0:
            return False

        head, tail = 0, lenS1 - 1
        hashS1 = getHash(s1)
        hashS2 = getHash(s2[head: tail + 1])
        while tail < lenS2:
            if hashS1 == hashS2:
                return True
            tail += 1
            if tail == lenS2:
                break
            if s2[tail] not in hashS1:
                if tail + 1 + lenS1 >= lenS2:
                    break
                else:
                    head = tail + 1
                    tail = head + lenS1 - 1
                    hashS2 = getHash(s2[head: tail + 1])
            else:
                if s2[tail] not in hashS2:
                    hashS2[s2[tail]] = 0
                hashS2[s2[tail]] += 1
                hashS2[s2[head]] -= 1
                if hashS2[s2[head]] == 0: #这里需要注意的是，如果这里没有了这个数，则需要删除这个键值
                    del hashS2[s2[head]]
                head += 1

        return False
```
