    int maxProduct(vector<string>& words) {
        vector<int> wordBits;
        int i, j, wordBit, len;
        len = words.size();
        /* 由于单词只有小写字母，用移位法将其转成对应的数字 */
        for (i = 0; i < len; i++){
            wordBit = 0;
            for (j = 0; j < words[i].length(); j++){
                wordBit |= 1 << (words[i][j] - 'a');
            }
            wordBits.push_back(wordBit);
        }
        int result = 0;
        for (i = 0; i < len; i++){
            /* 两个单词没有公共字母，等价于单词转成的数字A和B，A | B = A ^ B，
               遍历任意两个不同的单词，满足此条件的计算乘积 */
            for (j = i + 1; j < len; j++){
                if ((wordBits[i] | wordBits[j]) == (wordBits[i] ^ wordBits[j])){
                    result = max(result, int(words[i].length() * words[j].length()));
                }
            }
        }
        return result;
    }