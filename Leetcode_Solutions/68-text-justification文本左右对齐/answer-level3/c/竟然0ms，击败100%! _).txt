### 解题思路
感觉也没什么技巧，就是先判断单词能不能放到一行里，然后在计算单词间空格数，前面的空格多就行了。

### 代码

```c
 /**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fullJustify(char ** words, int wordsSize, int maxWidth, int* returnSize){
	char** result, *linebuffer;
	int lines = 0, i, j, k, newline = 1, first = 0, wordcount = 0, linelength = 0, len, space, morespace, offset;

	result = (char**)malloc(wordsSize * sizeof(char*));
	linebuffer = (char*)malloc((maxWidth + 1) * wordsSize);
	for (i = 0; i < wordsSize; i++)
		result[i] = linebuffer + i * (maxWidth + 1);

	for (i = 0; i < wordsSize; i++)
	{
		if (linelength + strlen(words[i]) + wordcount > maxWidth)
		{
			if (wordcount == 1)
			{
				len = strlen(words[first]);
				strcpy(result[lines], words[first]);
				if (len < maxWidth)
				{
					for (j = len; j < maxWidth; j++)
						result[lines][j] = ' ';
					result[lines][maxWidth] = '\0';
				}
			}
			else
			{
				space = (maxWidth - linelength) / (wordcount - 1);
				morespace = (maxWidth - linelength) % (wordcount - 1);
				offset = 0;
				for (j = first; j < i; j++)
				{
					strcpy(result[lines] + offset, words[j]);
					if (j == i - 1)
						break;
					offset += strlen(words[j]);
					for (k = 0; k < space; k++)
						result[lines][offset + k] = ' ';
					offset += space;
					if (j - first < morespace)
					{
						result[lines][offset] = ' ';
						offset++;
					}
				}
			}
			lines++;
			first = i;
			linelength = strlen(words[i]);
			wordcount = 1;
		}
		else
		{
			linelength += strlen(words[i]);
			wordcount++;
		}
	}
	// last line
	if (wordcount == 1)
	{
		len = strlen(words[first]);
		strcpy(result[lines], words[first]);
		if (len < maxWidth)
		{
			for (j = len; j < maxWidth; j++)
				result[lines][j] = ' ';
			result[lines][maxWidth] = '\0';
		}
	}
	else
	{
		offset = 0;
		for (j = first; j < i; j++)
		{
			strcpy(result[lines] + offset, words[j]);
			offset += strlen(words[j]);
			if (j == i - 1)
				break;
			result[lines][offset] = ' ';
			offset++;
		}
		for (k = offset; k < maxWidth; k++)
			result[lines][k] = ' ';
		result[lines][maxWidth] = '\0';
	}
	lines++;
	*returnSize = lines;
	return result;
}
```