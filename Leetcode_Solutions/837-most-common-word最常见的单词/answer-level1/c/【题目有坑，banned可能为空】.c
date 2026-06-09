// 算法：
// 把段落中的大写字母都转换为小写字母【还可以把所有标点符号都置换为空格】
// 根据分隔符，分割段落中的每个单词【用strtok或者手动分割都可以，手动分割别忘了添加结束符】
// 把得到的单词保存在有效单词列表，允许存在重复单词
// 对有效单词列表按升序排序
// 以遇到新单词为界限，统计相同单词的个数，并与最大值比较，确定是否置换【只要遇到新单词，计数重新开始】
// 由于以遇到新单词为界限，比较当前计数与最大值，因此对最后一个单词要单独处理
// 遍历完整个段落后，返回出现频次最高的单词
// strtok在划分原串时，把包含在分隔集内的字符转化成了'\0'（可能是其他字符）；
// 如果想对同一个串多次划分，请保存原串，用复制串去划分
// 假设段落包含x个单词，由(x-1)个空格分开，那么 x+(x-1)<=1000, x<501<512
// banned有可能为空
// strcpy会把源字符串的结束符也复制到目标buffer，因此相当于覆盖buffer原有字符
// 返回指针或数组，一定要用malloc申请

```
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX_M 512

// find函数
// 作用：在列表中寻找某个单词
// 返回值：
// 如果key存在于list，返回1；否则返回0
// 函数参数中，不修改的指针用const修饰
int find(const char* key, const char** list, int listSize)
{
	if (listSize < 1 || key == NULL || list == NULL) {
		return 0;
	}

	int i;
	for (i = 0; i < listSize; i++) {
		if (strcmp(key, list[i]) == 0) {
			return 1;  // 返回相同单词在list中的下标
		}
	}

	return 0;
}

// qsort的cmp与strcmp的排列规律一致; <0; >0; =0
int compare(const void* a, const void* b)
{
	return strcmp((char*)a, (char*)b);
}

char * mostCommonWord(char * paragraph, char ** banned, int bannedSize)
{
	int lenPa = strlen(paragraph);
	if (paragraph == NULL || lenPa < 1 || lenPa > 1000 || bannedSize > 100) {
		return "";
	}

	// 把段落中的大写字母都转换为小写字母
	int i;
	for (i = 0; i < lenPa; i++) {
		if (isupper(paragraph[i])) {
			paragraph[i] = paragraph[i] + 32;   // 'a' = 'A' + 32
		}
	}

	char* token = NULL;
	char delim[10] = " !?',;.";
	token = strtok(paragraph, delim);

	char effWords[MAX_M][MAX_M] = {{0}};	// 有效单词列表
	int numEff = 0;   // 有效单词个数
	char* mostWord = (char*)malloc(MAX_M * sizeof(char));		// 最常见单词
	memset(mostWord, 0, MAX_M * sizeof(char));
	int maxCount = 0;		// 最大次数（最常见单词的频次）
	

	while (token != NULL) {
		strcpy(effWords[numEff++], token);  // 将token保存在有效单词列表
		token = strtok(NULL, delim);  // 获取下一个单词
	}

	qsort(effWords, numEff, MAX_M, compare);  // 按升序排列

	// 遍历有效单词列表
	int currCount = 1;	// 每个单词最少出现1次
	for (i = 0; i < numEff; i++) {
		if (strcmp(effWords[i], effWords[i + 1]) == 0) {	// 遇到相同单词，累加
			currCount++;
		} else {	// 遇到新单词
			if (currCount > maxCount && find(effWords[i], banned, bannedSize) == 0) {
				maxCount = currCount;
				strcpy(mostWord, effWords[i]);
				
			}
			currCount = 1;	// 不管是否更新maxCount,遇到新单词以后，currCount都要重新计算
		}
	}

	// 处理最后一个单词
	if (currCount > maxCount && find(effWords[numEff - 1], banned, bannedSize) == 0) {
		strcpy(mostWord, effWords[numEff - 1]);
	}

	return mostWord;
}
```
