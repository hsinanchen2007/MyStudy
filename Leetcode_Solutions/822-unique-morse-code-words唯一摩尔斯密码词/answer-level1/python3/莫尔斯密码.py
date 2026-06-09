### 解题思路
字典对应
执行用时 :
36 ms
, 在所有 python3 提交中击败了
98.59%
的用户
内存消耗 :
12.8 MB
, 在所有 python3 提交中击败了
99.50%
的用户
### 代码

```python3
class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        T = []
        moer = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        str1 = 'abcdefghijklmnopqrstuvwxyz'
        zimu = []
        for i in str1:
            zimu.append(i)
        for i in range(len(words)):
            str2 = ''
            for j in range(len(words[i])):
                k = zimu.index(words[i][j])
                str2 += moer[k]
            if str2 not in T:
                T.append(str2)
        return len(T)

```