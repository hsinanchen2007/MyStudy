### 解题思路
用2个哈希表，一个存储char里的字母及个数，一个用来存储word里的字母及个数。


### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        hashmap={}
        ch_len=len(chars)
        # 记录chars的字母及个数
        for ch in chars:
            j = hashmap.get(ch)
            if j is None:
                hashmap[ch] = 1
            if j is not None:
                hashmap[ch] += 1

        #记录记住的单词总长度
        words_sum_len=0
        # 获得words[i]的长度，对比chars短的进行判断，长的直接跳过
        for word in words:
            word_hashmap={}
            #
            check_pass=0
            if len(word)<= ch_len:
                # 提取words[i]的字母及个数  并与chars对比
                for word_ch in word:
                    j = hashmap.get(word_ch)
                    k = word_hashmap.get(word_ch)
                    if j is None:
                        check_pass = 0
                        break
                    else:
                        if k is None:
                            check_pass = 1
                            word_hashmap[word_ch] = 1
                        if k is not None:
                            check_pass = 1
                            word_hashmap[word_ch] += 1
                            if word_hashmap[word_ch]> hashmap[word_ch]:
                                check_pass = 0
                                break
                if check_pass == 1:
                    words_sum_len+= len(word) 
        return words_sum_len

```