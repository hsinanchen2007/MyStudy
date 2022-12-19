### 解题思路
注意字符串中的单词可能长度大小不唯一，可能会存在ffofoot这种情况
所以我认为第一层的s的基础遍历是必须的，按照链表的字母长度取值，如果有匹配就移除掉，继续滑动，直到字典里的字母完全移除完为止．然后返回相应坐标．这样完成了一次迭代，以此内推下去．
### 代码

```python3
class Solution:
    def findSubstring(self, s: str, word: List[str]) -> List[int]:
            if not s or not word:return []
            number = []
            zimu_len = len(word[0])
            word_num = len(word)
            all_lenth = zimu_len * word_num
            for i in range(0,len(s)-all_lenth+1):
                words = word.copy()
                j = i
                while len(words)!=0:
                    if j+zimu_len <=len(s):
                        zimu_tem = s[j:j+zimu_len]
                        j += zimu_len
                        if zimu_tem in words:
                            words.remove(zimu_tem)
                        else:break
                    else:break
                if len(words)==0:
                    number.append(j-len(word[0])*len(word))
            return number
```