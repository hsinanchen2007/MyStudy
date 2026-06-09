```
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if len(words) == 0 or len(words[0]) == 0: return []
        len_word, count = len(words[0]), len(words)
        if len(s) - len(words) * len_word < 0: return []  # 总长度小于子串长度

        dic = {}
        for word in words:
            if word in dic:
                dic[word] += 1
            else:
                dic[word] = 1
        res = []
        for i in range(len_word):  # 单词错位遍历
            total_words = (len(s) - i) // len_word  # 总单词数
            dic_bak = dic.copy()
            j, k = 0, 0  # 全文(s)单词索引, 子串中单词索引
            while j < total_words - count + 1 and k < count:
                error = False  # 标记子串是否符合条件
                for index in range(k, count):
                    start = i + j * len_word + index * len_word
                    word_str = s[start:start + len_word]
                    if word_str in dic_bak and dic_bak[word_str] > 0:  # 在字典中且还剩名额
                        dic_bak[word_str] -= 1
                    elif word_str not in dic_bak:  # 不在字典中
                        j += index + 1  # 跳过该组前 index 个单词
                        # 从跳过 index 个单词后, 恢复 k=0, dic_bak, 重新开始
                        k = 0
                        dic_bak = dic.copy()
                        error = True
                        break
                    else:  # 单词超过个数
                        # 窗口向后, 按单词长度单位移动, 直到遇到第一个该单词后停止
                        skip = 0  # 跳过的单词数
                        for skip_index in range(count):
                            start = i + j * len_word + skip_index * len_word
                            word_str_tmp = s[start:start + len_word]
                            if word_str_tmp != word_str:
                                dic_bak[word_str_tmp] += 1
                                skip += 1
                            else:
                                break
                        j += skip + 1
                        k = index - skip
                        error = True
                        break
                if not error:  # 符合条件的索引存储
                    res.append(i + j * len_word)
                    # 后移一位
                    start = i + j * len_word
                    dic_bak[s[start: start + len_word]] += 1
                    j += 1
                    k = len(words) - 1
        return res
```