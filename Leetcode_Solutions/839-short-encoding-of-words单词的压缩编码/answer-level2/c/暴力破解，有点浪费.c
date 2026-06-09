暴力破解思想：
    1）统计下每个单词的长度
    2）选择单词长度最大的一个赋值给dst，并以#结尾，将当前单词的长度置位-1
    3）参考选择排序，起始位置为1，终点位置为wordsize，每轮选取最长的单词，每个word在进入dst之前先进行比较，看这个word+#的串是否已经存在于dst串中，如果存在则不需要加入到dst中，每轮结束前将当前word统计长度置位-1
    4）遍历完所有的单词后，得到的dst长度就是结果

int include_word(char *dst, char *word, int word_len, int dst_len)
{
    for (int i = 0; i < dst_len; i++) {
        if (word_len >= dst_len - i) {
            return 0;
        }

        if (dst[i] == word[0] && dst[i + word_len] == '#' &&strncmp(dst + i, word, word_len) == 0) {
            return 1;
        }
    }
    return 0;
}

int minimumLengthEncoding(char ** words, int wordsSize) {
    char dst[20000] = { 0 };
    int word_len = 0;
    int dst_len = 0;
    int count[10000];

    if (wordsSize == 0) {
        return 0;
    }

    for (int i = 0; i < wordsSize; i++) {
        count[i] = strlen(words[i]);
    }

    int temp = 0;
    int local = 0;
    for (int s = 0; s < wordsSize; s++) {
        if (temp < count[s]) {
            temp = count[s];
            local = s;
        }
    }

    (void)strncpy(dst, words[local], strlen(words[local]));
    dst[strlen(words[local])] = '#';
    dst[strlen(words[local]) + 1] = '\0';
    count[local] = -1;

    for (int j = 1; j < wordsSize; j++) {
        temp = 0;
        local = 0;
        for (int s = 0; s < wordsSize; s++) {
            if (temp < count[s]) {
                temp = count[s];
                local = s;
            }
        }
        
        dst_len = strlen(dst);
        word_len = strlen(words[local]);
        if (include_word(dst, words[local], word_len, dst_len) != 1) {
            strncat(dst, words[local], word_len);
            dst[dst_len + word_len] = '#';
            dst[dst_len + word_len + 1] = '\0';
        }
        count[local] = -1;
    }

    return strlen(dst);
}