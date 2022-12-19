```
class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        思路：  一一对应
               第一步 key为pattern, value为words, 遍历pattern, 检查同一个patten是否对应相同的word
               第二步 key为words, value为pattern, 遍历words, 检查同一个word是否对应相同的patter
        """
        
        words = str.split(" ")
        hash_table_pattern = {}
        hash_table_words = {}
        
        if len(words) != len(pattern):
            return False
        
        #第一步
        for i, letter in enumerate(pattern):
            if hash_table_pattern.get(letter):
                if hash_table_pattern[letter] != words[i]:
                    return False
            else:
                hash_table_pattern[letter] = words[i]
        
        #第二步
        for i, word in enumerate(words):
            if hash_table_words.get(word):
                if hash_table_words[word] != pattern[i]:
                    return False
            else:
                hash_table_words[word] = pattern[i]
                
        return True
```
