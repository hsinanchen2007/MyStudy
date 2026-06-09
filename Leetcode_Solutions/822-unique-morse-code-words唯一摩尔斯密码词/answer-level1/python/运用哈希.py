### 解题思路

具体看代码实现
### 代码

```python3
class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        word = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
        secret = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        hash ={}
        for i in range(len(word)):
            hash[word[i]] = secret[i]
        res_list = []
        for item in words:
            res = ''
            for it in item:
                res += hash[it]
            res_list.append(res)
        return len(set(res_list))

```