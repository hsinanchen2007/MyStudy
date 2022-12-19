**每次填充一个单词：复杂度过高**
```
   def wordsTyping(self, sentence, rows, cols):
        ans, idx = 0, 0
        n = len(sentence)
        word_lens = [len(word) for word in sentence]

        for i in range(rows):
            length = cols
            while length >= word_lens[idx]:
                length -= word_lens[idx] + 1
                idx += 1
                if idx == n:
                    ans += 1
                    idx = 0
        return ans
```

 

**加入段落填充**
```
    def wordsTyping(self, sentence, rows, cols):
        n = len(sentence)
        word_lens = [len(word) for word in sentence]
        sent_len = sum(word_lens) + n - 1
        right_lens = [sum(word_lens[i:]) + n - i - 1 for i in range(n)]

        cur_num, cur_word = 0, 0
        for row in range(rows):
            length = cols

            if cur_word > 0 and right_lens[cur_word] <= length:
                length -= right_lens[cur_word] + 1
                cur_num += 1
                cur_word = 0
            if sent_len <= length:
                tmp = (length + 1) // (sent_len + 1)
                # 小心这里length的更新
                length -= tmp * sent_len + tmp
                cur_num += tmp
                cur_word = 0
            while length >= word_lens[cur_word]:
                length -= word_lens[cur_word] + 1
                cur_word += 1
        return cur_num

```
