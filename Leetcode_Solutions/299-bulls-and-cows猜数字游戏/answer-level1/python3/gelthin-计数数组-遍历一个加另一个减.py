### 解题思路
用两个计数数组来实现 hash 表的功能。
一不小心，又写了一个 bug， 循环变量弄错了。

#### 只使用一个计数数组的解法 [Java方法--只使用一类桶就够了](https://leetcode-cn.com/problems/bulls-and-cows/solution/javafang-fa-zhi-shi-yong-yi-lei-tong-jiu-gou-liao-/)

这一遍历时，同时对一个来源加，另一个来源减的做法，之前见过。 [gelthin-异或-求和](https://leetcode-cn.com/problems/missing-number/solution/yi-huo-qiu-he-by-gelthin/)

还有他人的解答待查找。 例如 [242. 有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/)

遍历 secret[i] 和 guess[i]
+ if secret[i] == guess[i], A += 1
+ if secret[i] != guess[i], hash[secret[i]] += 1, hash[guess[i]] -= 1


最后 B = len(secret) - A - secret中没有被匹配到的数字

secret 中被匹配到了的数字，最终 hash[secret[i]] = 0, 
出现在secret中但未出现在 guess 中最终 hash[secret[i]] = 1  (or >=1  可能会重复出现)
出现在 guess 中但未出现在 secret 中，最终 hash[guess[i]] = -1

统计 hash[i] >= 1 的值的和即可。



### 代码

```python3
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        A, B= 0, 0
        hash1, hash2 = [0]*10, [0]*10  # 0-9 用作计数数组
        n = len(secret)
        for i in range(n):
            if secret[i] == guess[i]:
                A += 1
            else:
                hash1[int(secret[i])] += 1
                hash2[int(guess[i])] += 1
        # for i in range(n):  bug 在这里  "1807" "7810"
        for i in range(10):
            B += min(hash1[i], hash2[i])
        return str(A) + "A" + str(B) +"B"

```