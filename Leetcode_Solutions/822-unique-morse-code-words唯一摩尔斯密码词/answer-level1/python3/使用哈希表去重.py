![b126f648f4a4833f5d19130509d3c35.png](https://pic.leetcode-cn.com/57a3ac6b69320407b20420e4d594aa3cac3e4b26d00b89a34a45e441bdcf1947-b126f648f4a4833f5d19130509d3c35.png)

#### 单词在经过莫尔斯密码加密后存在多对一的问题，因此我们需要使用集合或字典去重

```python []
class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        morse_code = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        encrypted_words = set()  ## 创建集合用来去重
        for word in words:
            encrypted_word = ''  ## 创建encrypted_word用来储存加密后的单词
            for letter in word:
                encrypted_word += morse_code[ord(letter)-97]  ## 对每个字母进行加密。这里用 ord(letter)-97 获得字母在字母表中的排序(0, 1, 2, …, 25)
            encrypted_words.add(encrypted_word)  ## 将加密后的单词加到集合中
        return len(encrypted_words)  ## 返回集合中元素的数量

```
