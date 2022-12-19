#### 以递归回溯的方式模拟自己手动解题
1. 列竖式加法计算表达式，从低位往高位求和；从上往下，从第一个单词往最后一个单词尝试填补数字；
2. 如果某个大写字符有对应数字，则直接使用对应数字填补竖式；
3. 如果某个大写字符还没有对应的数字，则从0（如果是最高位就是从1开始）到9找一个还没使用过的数字进行填补;
```
class Solution {
public:
	bool isSolvable(vector<string>& words, string result) {
		vector<int> charDigits(26, -1);
		vector<bool> usedDigits(10, false);
		return trySolve(words, result, charDigits, usedDigits, 1, 0, 0);
	}

	bool trySolve(
		const vector<string>& words,
		const string& result,
		vector<int> charDigits,		// 记录大写字母对应的数字
		vector<bool> usedDigits,	// 标记相应的数字是否已被使用
		size_t digitIdx,			// 表示处理第几位数字，由低位到高位，从1开始
		size_t strIdx,				// 表示处理第几个单词，从0开始
		int digitsSum)				// 表示当前位置的和，初始和为0，下一位置的初始值为上个位置和的进位
	{
		// words单词digitIdx位已处理完，检验和result的digitIdx位置
		if (strIdx == words.size())
		{
			// 和result没有digitIdx位
			if (digitIdx > result.size())
				return digitsSum == 0;

			int ch = result[result.size() - digitIdx] - 'A';
			int d = digitsSum % 10;
			if (charDigits[ch] != -1)			// result的digitIdx位字母已有对应的数字值
			{
				if (charDigits[ch] == d)		// 尝试下一digitIdx位，从第0个单词开始，初始和为当前和的进位
					return trySolve(words, result, charDigits, usedDigits, digitIdx + 1, 0, digitsSum / 10);
				else
					return false;
			}
			else	// result的digitIdx位字符还没有对应的数字值
			{
				if (!usedDigits[d])
				{
					charDigits[ch] = d;
					usedDigits[d] = true;
					if (trySolve(words, result, charDigits, usedDigits, digitIdx + 1, 0, digitsSum / 10))
						return true;

					// 还原
					charDigits[ch] = -1;
					usedDigits[d] = false;
				}

				return false;
			}
		}

		// 第strIdx个单词没有digitIdx位，直接下一个字符
		if (digitIdx > words[strIdx].size())
			return trySolve(words, result, charDigits, usedDigits, digitIdx, strIdx + 1, digitsSum);

		int ch = words[strIdx][words[strIdx].size() - digitIdx] - 'A';
		if (charDigits[ch] != -1)	// 第strIdx个单词的第digitIdx位的字母已有对应数字，累加该数字，尝试下一个字符
		{
			return trySolve(words, result, charDigits, usedDigits, digitIdx, strIdx + 1, digitsSum + charDigits[ch]);
		}
		else
		{
			// 从0（如果是最高位就是从1开始）到9找一个还没使用过的数字进行填补
			for (int i = (digitIdx == words[strIdx].size()); i <= 9; ++i)
			{
				if (!usedDigits[i])
				{
					charDigits[ch] = i;
					usedDigits[i] = true;
					// 处理下一个单词
					if (trySolve(words, result, charDigits, usedDigits, digitIdx, strIdx + 1, digitsSum + i))
						return true;

					// 还原
					charDigits[ch] = -1;
					usedDigits[i] = false;
				}
			}

			return false;
		}

		return false;
	}
};
```