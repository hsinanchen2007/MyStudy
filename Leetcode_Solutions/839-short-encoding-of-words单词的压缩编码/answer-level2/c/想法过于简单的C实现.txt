思路就是求出整个words里单词的总长度length，再加上wordsSize个“#”，接着遍历数组，两两比较，每次只比较比自己短的字符串，如果短的字符串是自己末尾的子字符串，length就减去这个字符串的长度再减1，并且在标记数组Flag中这一下标的数置1，下次循环遍不再考虑这个字符串了。
时间效率太低，但是空间效率很高。
int minimumLengthEncoding(char ** words, int wordsSize){
    if(wordsSize==0)
        return 0;
    if(wordsSize==1)
        return strlen(words[0])+1;
    int i, j;
	int length = 0;
	int length1, length2;
	int flag;
	int Flag[wordsSize];
	memset(Flag, 0, sizeof(Flag));
	for (i = 0; i<wordsSize; i++)
	{
		length = length + strlen(words[i]) + 1;
	}
	for (i = 0; i<wordsSize; i++)
	{
		if (Flag[i] == 1)
			continue;
		for (j = 0; j<wordsSize; j++)
		{
			if (j == i || Flag[j] == 1)
				continue;
			length1 = strlen(words[i]);
			length2 = strlen(words[j]);
			if (length2>length1)
				continue;
			if (length2 == length1)
			{
				if (strcmp(words[i], words[j]) == 0)
				{
					length = length - length2 - 1;
					Flag[j] = 1;
				}
				continue;
			}
			flag = 0;
			while (length2 > 0)
			{
				length1--;
				length2--;
				if (words[i][length1] != words[j][length2])
				{
					flag = 1;
					break;
				}
			}
			if (flag)
				continue;
			else
			{
				length = length - strlen(words[j]) - 1;
				Flag[j] = 1;
			}
		}
	}
	return length;
}```

