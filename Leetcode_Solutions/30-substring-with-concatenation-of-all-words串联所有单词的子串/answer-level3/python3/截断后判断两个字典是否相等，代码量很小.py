### 解题思路
如题，不知道有没有办法直接用正则解决。

### 代码

```python3
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if s == "" or len(words) == 0: return []
         
        word_lenth = len(words[0])
        sub_s_lenth = word_lenth*len(words)
        words_dic = collections.Counter(words)
        ans = []

        for i in range(0, len(s)-sub_s_lenth+1):
            tmpdic = collections.Counter(re.findall(r'.{' + str(word_lenth) + '}', s[i:i+sub_s_lenth]))
            if  tmpdic == words_dic:
                ans.append(i)
        
        return ans




```