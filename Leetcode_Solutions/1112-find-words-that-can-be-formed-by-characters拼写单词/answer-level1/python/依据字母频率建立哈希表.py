### 解题思路
![image.png](https://pic.leetcode-cn.com/94d0a9e3bbd92bf806f8d35dcb1e2bd4e49874a780dd3b854400902403b34092-image.png)
这道题绝对不能算简单题……如果用简单的做法我估计时间都慢到不知道哪里去了。
但是它又不能算是中等题……
这道题的时间复杂度好像推不出来……因为$words$数组的元素的长度是不确定的。
最坏的时间复杂度应该是$words$中每个词都能够拼写出来，设$words$的元素个数为$n$，最长的单词的长度为$k_1$，chars的长度为$k_2$。
那么给$chars$建哈希表的时间复杂度是$O(k_2)$
然后比对的时间复杂度为$O(n*k_1)$
那么最坏时间复杂度就是$max(O(n*k_1),O(k_2))$
空间复杂度就是大哈希表（chars的哈希表）和小哈希表（words的每个单词的哈希表）的和，因为这里最多只会有26个元素，所以空间复杂度为：$O(1)$
思路就是：先给$chars$建哈希表，判断每个字母的频率，然后再对$words$的每个单词建一个哈希表，如果建立完整个哈希表后，后者的哈希表的每个元素出现的频率都小于等于前者的哈希表对应元素出现的频率，那么这个单词就能被拼写。
举例：
$
chars = "atach"\\
words = ["cat","bt","hat","tree"]
$

那么$chars$的哈希表就是：$\{'a':2,'c':1,'h':1,'t':1\}$
遍历$words$，比如遍历到$"cat"$，建立起来的哈希表就是：$\{'a':1,'c':2,'t':1\}$，所有元素在$chars$的哈希表中均有出现，并且出现频率均小于等于在$chars$哈希表中对应元素的频率。

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        # "atach"可以转化为"a2c1h1t1"
        # "cat"可以转化为"a1c1t1"
        # 每个字符串开个dict
        total_count = 0
        chars_dict = {}
        for i in chars:
            if i not in chars_dict:
                chars_dict[i] = 1
            else:
                chars_dict[i] += 1
        for word in words:
            count = 0
            word_dict = {}
            for char in word:
                if char not in chars_dict:
                    count = 0
                    break
                if char not in word_dict:
                    word_dict[char] = 1
                    count += 1
                elif char in word_dict:
                    word_dict[char] += 1
                    if word_dict[char] > chars_dict[char]:
                        count = 0
                        break
                    else:
                        count += 1
            total_count += count
        return total_count
```