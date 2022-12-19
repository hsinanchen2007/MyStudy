![result.JPG](https://pic.leetcode-cn.com/bfe043a520e4fc8537d5bf9d6c4d5dc060a8baa71ff27c34d2f7ce2893d7e7dd-result.JPG)
整个过程如下：
![image.png](https://pic.leetcode-cn.com/585e7f492169c5af0a317661a4d81ea6761c5aa323d55660fa3b13a03f842c52-image.png)
![image.png](https://pic.leetcode-cn.com/1e5b5ad0526151c051c58e86c28430f33220e08ba410515adca4da0633daa8ac-image.png)
![image.png](https://pic.leetcode-cn.com/8a0d495fa65f25d5da55dded4d963ca5e3ab0f0223eb4438432d1559cec59a49-image.png)

附代码：
```
/**
* Note: The returned array must be malloced, assume caller calls free().
*/

int belongto(unsigned int *num, int count, unsigned int tar)
{
	int i = 0;
	for (i = 0; i < count; i++) {
		if (num[i] == tar) {
			return i;
		}
	}
	return -1;
}
int fullMatch(unsigned int *match, int * target, int count)
{
	int i = 0;
	for (i = 0; i < count; i++) {
		if (match[i] != target[i]) break;
	}
	return i == count;
}
int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize) {
	unsigned int *word_2_num, *s_2_num;
	int count = 0, word_len, i, s_len, index, j, pos, diff_word_cnt = 0;
	unsigned int *match_cnt;
    unsigned int m;
	int *result_buf, result_size = 0, *index_buf, *target;
    if(wordsSize == 0 || s == NULL || words == NULL || words[0] == NULL || (strlen(words[0]) >  strlen(s))){
        *returnSize = 0;
        return NULL;
    }
	word_len = strlen(words[0]);
	s_len = strlen(s);
    
	word_2_num = (unsigned int *)malloc(sizeof(unsigned int)*wordsSize);
	s_2_num = (unsigned int *)malloc(sizeof(unsigned int)*s_len);
	match_cnt = (unsigned int *)malloc(sizeof(unsigned int)*wordsSize);
	target = (int *)malloc(sizeof(int)*wordsSize);
	result_buf = (int *)malloc(sizeof(int)*s_len);
	index_buf = (int *)malloc(sizeof(int)*(s_len/word_len));

    //将words映射为unsigned int型数字
	for (count = 0; count < wordsSize; count++) {
		word_2_num[count] = 0;
		m = 1;
		for (i = 0; i < word_len; i++) {
			word_2_num[count] += words[count][i] * m;
			m *= 31;
		}
	}
     //将words映射为unsigned int型数字
	for (count = 0; count <= s_len - word_len; count++) {
		s_2_num[count] = 0;
		m = 1;
		for (i = 0; i < word_len; i++) {
			s_2_num[count] += s[count + i] * m;
			m *= 31;
		}
	}
    //将重复的word合并，整理target
    memset(target, 0, sizeof(unsigned int)*wordsSize);
	for (i = 0; i < wordsSize; i++) {
		for (j = 0; j < i; j++) {
			if (word_2_num[i] == word_2_num[j]) {
				break;
			}
		}
		if (j == i)diff_word_cnt++;
		target[j] ++;
	}
    //滑动窗口匹配
	for (count = 0; count < word_len; count++) {
		memset(match_cnt, 0, sizeof(unsigned int)*wordsSize);

		for (j = 0; j < s_len / word_len; j++) {
			if ((index = belongto(word_2_num, wordsSize, s_2_num[count + j * word_len])) != -1) {
                match_cnt[index]++;
			}
			index_buf[j] = index;

			if (fullMatch(match_cnt, target, diff_word_cnt)) {
				result_buf[result_size++] = count + (j - (wordsSize - 1)) * word_len;
			}

			if (j >= wordsSize - 1) {
				index = index_buf[j - (wordsSize - 1)];
				if (index != -1) {
					match_cnt[index]--;
				}
			}
		}

	}
	*returnSize = result_size;
    free(word_2_num);
    free(s_2_num);
    free(match_cnt);
    free(target);
    free(index_buf);
	return result_buf;
}
```

